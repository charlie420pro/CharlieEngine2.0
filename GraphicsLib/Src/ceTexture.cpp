#define STB_IMAGE_IMPLEMENTATION
#define BIT_PER_PIXEL 32

#include "windows.h"
#include "ceTexture.h"
#include "stb_image.h"

#include <FreeImage.h>
#include "DX11Headers.h"

namespace ceEngineSDK
{
	

	//! Constructor default.
	ceTexture::ceTexture()
	{
		m_pTexture = nullptr;
		m_pTexture = new Texture();
	}

	//! Destructor default.
	ceTexture::~ceTexture()
	{
		Destroy();
	}

	//! Funcion para destruir.
	void ceTexture::Destroy()
	{
		/// Si es diferente de nullptr entonces manda el destroy para liberar memoria.
		if (m_pTexture != nullptr)
		{
			m_pTexture->Destroy();
			delete m_pTexture;
			m_pTexture = nullptr;
		}
	}

	//! Funcion para obtener una referencia a la textura.
	void ** ceTexture::GetTextureReference()
	{
		/// Regresa una referencia a la textura como un void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pTexture->m_pDXTexture);
	}

	//! Funcion para obtener la textura.
	void * ceTexture::GetTexture()
	{
		/// Regresa la textura como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pTexture->m_pDXTexture);
	}

	void ** ceTexture::GetShaderResourceViewReference()
	{
		return reinterpret_cast<void**>(&this->m_pTexture->m_pDXShaderResourceView);
	}

	void * ceTexture::GetShaderResourceView()
	{
		/// Regresa la textura como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pTexture->m_pDXShaderResourceView);
	}

	//! Funcion para setear la textura.
	void ceTexture::SetTexture(void* pTexture)
	{
		m_pTexture->m_pDXTexture = reinterpret_cast<ID3D11Texture2D*>(pTexture);
	}

	//! Funcion para cargar una textura desde archivo.
	void ceTexture::LoadTextureFromFile(String sFileName, void* pDevice, void* pDeviceContext)
	{
		//TODO: Separar todo esto por funciones esto esta hardcore aqui en la misma funcion.
		HRESULT hr;
		/*int32 iComponent;
		int32 iRequeriment_Component;

		unsigned char* pImageBts = stbi_load(sFileName.c_str(), &m_iWidth, &m_iHeight, &iComponent, iRequeriment_Component);
		*/

		/// Creamos el formato de imagen que se va a utilizar y lo inicializamos como UNKNOWN.
		FREE_IMAGE_FORMAT ImageFormat = FIF_UNKNOWN;
		/// Cargamos la imagen desde un archivo.
		ImageFormat = FreeImage_GetFIFFromFilename(sFileName.c_str());

		/// Checamos que el formato de imagen sea soportado por FreeImage.
		if ((ImageFormat != FIF_UNKNOWN) && (FreeImage_FIFSupportsReading(ImageFormat)))
		{
			/// Creamos un bitmap temporal donde se va almacenar la imagen.
			FIBITMAP* bitmap = nullptr;
			/// Cargamos la imagen.
			bitmap = FreeImage_Load(ImageFormat, sFileName.c_str());

			/// Obtenemos datos de la imagen para futuras referencias.
			m_iWidth = FreeImage_GetWidth(bitmap); /// Ancho de la imagen.
			m_iHeight = FreeImage_GetHeight(bitmap); /// Alto de la imagen.
			m_iBitsPerPixel = FreeImage_GetBPP(bitmap); /// Bits por pixel de la imagen.

			/// Guardamos la informacion en la variable miembro
			m_pData = bitmap;
		}

		
		/// Si los bits que tiene la imagen por pixel es diferente a 32.
		if (m_iBitsPerPixel != BIT_PER_PIXEL)
		{
			/// Creamos un bitmap temporal.
			FIBITMAP* temp = nullptr;
			/// Convertimos el data a 32 bits y lo guardamos.
			temp = FreeImage_ConvertTo32Bits((FIBITMAP*)m_pData);
			/// Liberamos el data ya que se guardo en el temporal y ya no necesitamos la informacion anterior.
			FreeImage_Unload((FIBITMAP*)m_pData);
			/// Asignamos los bit por pixel a la variable miembra para futuras referencias.
			m_iBitsPerPixel = FreeImage_GetBPP(temp);

			/// Ahora asignamos de nuevo al data la imagen pero ya convertida a 32 bits.
			/// Forzando que el data siempre sea de 32 bits.
			m_pData = temp;
		}
		
		FreeImage_FlipVertical((FIBITMAP*)m_pData);

		/// Guardamos el data en byte para su utilizacion posteriormente
		BYTE* pData = FreeImage_GetBits((FIBITMAP*)m_pData);

		/// Guardamos en el tamaño de la imagen en una variable temporal.
		int32 uiSize = (m_iBitsPerPixel/8) * m_iWidth * m_iHeight;

		/// Creamos una textura temporal donde se va almacenar la informacion.
		ID3D11Texture2D* pTempTexture = nullptr;

		/// Creamos el descriptor de la textura y lo llenamos con sus valores.
		D3D11_TEXTURE2D_DESC Desc = { 0 };
		Desc.Width = m_iWidth;
		Desc.Height = m_iHeight;
		Desc.ArraySize = 1;
		Desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
		Desc.CPUAccessFlags = 0;
		Desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		Desc.MipLevels = 1;
		Desc.MiscFlags = 0;
		Desc.SampleDesc.Count = 1;
		Desc.SampleDesc.Quality = 0;
		Desc.Usage = D3D11_USAGE_DEFAULT;

		D3D11_SUBRESOURCE_DATA SubData = {0};
		SubData.SysMemPitch = m_iWidth * m_iBitsPerPixel/ 8;
		SubData.pSysMem = pData;
		SubData.SysMemSlicePitch = uiSize;


		/// Creamos la textura2D.
		hr = reinterpret_cast<ID3D11Device*>(pDevice)->CreateTexture2D(&Desc, &SubData, &pTempTexture);
		if (FAILED(hr))
		{
			/// Imprimimos en consola que no se pudo crear la textura.
			std::cout << "Fallo al crear la textura" << std::endl;
		}

		ID3D11ShaderResourceView* pShaderResourceView = nullptr;
		D3D11_SHADER_RESOURCE_VIEW_DESC sRVDesc = {};

		sRVDesc.Texture2D.MipLevels = Desc.MipLevels;
		sRVDesc.Texture2D.MostDetailedMip = 0;
		sRVDesc.Format = Desc.Format;
		sRVDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;

	
		reinterpret_cast<ID3D11Device*>(pDevice)->CreateShaderResourceView(pTempTexture, &sRVDesc, &pShaderResourceView);
		//reinterpret_cast<ID3D11DeviceContext*>(pDeviceContext)->GenerateMips(pShaderResourceView);

		m_pTexture->m_pDXTexture = pTempTexture;
		m_pTexture->m_pDXShaderResourceView = pShaderResourceView;
	}
}
