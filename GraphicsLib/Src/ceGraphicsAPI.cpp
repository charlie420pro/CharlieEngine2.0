#include "ceGraphicsAPI.h"
#include "DX11Headers.h"
#include <windows.h>

namespace ceEngineSDK
{
	const int32 g_iNumBuffer = 3;

	/**
	 *	@brief Constructor default de la clase.
	 */
	ceGraphicsAPI::ceGraphicsAPI()
	{
		//! Asignamos por default en el constructor los punteros como nulos.
		m_pDevice = nullptr;
		m_pDeviceContext = nullptr;
		m_pSwapChain = nullptr;
		m_pRenderTargetView = nullptr;
		m_pDepthStencilView = nullptr;
		m_pPixelShader = nullptr;
		m_pVertexShader = nullptr;
		m_pTextureRTV = nullptr;
		m_pTextureDSV = nullptr;
		m_pInputLayout = nullptr;
		m_pShaderResourceView = nullptr;
		m_pSampler = nullptr;
		m_pBlob = nullptr;
		m_uiScreenHandle = m_iHeight = m_iWidth = 0;
	}

	/**
	 *	@brief Destructor default de la clase.
	 **/
	ceGraphicsAPI::~ceGraphicsAPI()
	{
		Destroy();
	}


	/**
	 *	@brief Funcion para inicializar graphics.
	 *	@param iScreenHanlde: Identificador de la ventana.
	 *	@param iWidth: Ancho de la ventana.
	 *	@param iHeight: Alto de la ventana.
	 **/
	void ceGraphicsAPI::Init(uint32 uiScreenHandle, int32 iWidth, int32 iHeight)
	{
		//! Limpiamos en caso de que ya se hayan inicializado variables.
		Destroy();

		//! Guardamos las variables de parametro en las variables miembro para futuras referencias.
		m_uiScreenHandle = uiScreenHandle;
		m_iWidth = iWidth;
		m_iHeight = iHeight;

		m_World = ceMatrix_4X4::Identity();

		//! Creamos el device.
		CreateDevice();
		//! Creamos el device context.
		CreateDeviceContext();
		//! Creamos el swap chain.
		CreateSwapChain(m_uiScreenHandle, m_iWidth, m_iHeight);

		/// Creamos el render target view.
		CreateRenderTargetView();
		/// Creamos el depth stencil view.
		CreateDepthStencilView();

		/// Creamos el Vertex Shader.
		CreateVertexShader();
		//! Creamos el pixel shader.
		CreatePixelShader();
		//! Creamos el InputLayout.
		CreateInputLayout();

		//! Creamos los constantbuffer.
		CreateConstantBuffers();

		//! Creamos una luz.
		CreateLight();

		//! Creamos los buffers contastantes de luces.
		CreateConstantBuffersLight(sizeof(ceLight));

		//! Creamos el render target.
		SetRenderTargets();
		//! Seteamos el viewport.
		SetViewPort();

		//! Seteamos el input layout.
		SetInputLayout();
		//! Seteamos el tipo de topologia.
		SetPrimitiveTopology();

		//! Creamos el sample.
		CreateSample();
		//! Seteamos los samplers.
		SetSamplers();
		
		//! Seteamos los shaders.
		SetShaders();	
	}

	/**
	 *	@brief Funcion para renderear.
	 */
	void ceGraphicsAPI::Render()
	{
		
		float ClearColor[4] = { 0.7f, 0.2f, 0.2f, 1.0f }; // red, green, blue, alpha

		/// Limpiamos el render target view con el color que queremos.
		m_pDeviceContext->m_pDeviceContext->m_pDXDeviceContext->ClearRenderTargetView(
			m_pRenderTargetView->m_pRenderTargetView->m_DXRenderTargetView, ClearColor);

		/// Limpiamos el depth stencil view.
		m_pDeviceContext->m_pDeviceContext->m_pDXDeviceContext->ClearDepthStencilView(
			m_pDepthStencilView->m_pDepthStencilView->m_DXDepthStencilView,
			D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1, 0);
	}

	//! Funcion para actualizar el Graphics API.
	void ceGraphicsAPI::Update(float fTime)
	{
		
	}

	//! Funcion para liberar la memoria del objeto.
	void ceGraphicsAPI::Destroy()
	{
		//! Si el device es diferente de nulo.
		if (m_pDevice != nullptr)
		{
			m_pDevice->Destroy();//! Llama su funcion destroy.
			delete m_pDevice;//! Elimina el puntero.
			m_pDevice = nullptr;
		}

		//! Si el devicecontext es diferente de nulo.
		if (m_pDeviceContext != nullptr)
		{
			m_pDeviceContext->Destroy();//! Llama su funcion destroy.
			delete m_pDeviceContext;//! Elimina el puntero.
			m_pDeviceContext = nullptr;
		}

		//! Si el swapchain es diferente de nulo.
		if (m_pSwapChain != nullptr)
		{
			m_pSwapChain->Destroy();//! Llama su funcion destroy.
			delete m_pSwapChain;//! Elimina el puntero.
			m_pSwapChain = nullptr;
		}

		//! Si el rendertargetview es diferente de nulo.
		if (m_pRenderTargetView != nullptr)
		{
			m_pRenderTargetView->Destroy();//! Llama su funcion destroy.
			delete m_pRenderTargetView;//! Elimina el puntero.
			m_pRenderTargetView = nullptr;
		}

		//! Si el depthstencilview es diferente de nulo.
		if (m_pDepthStencilView != nullptr)
		{
			m_pDepthStencilView->Destroy();//! Llama su funcion destroy.
			delete m_pDepthStencilView;//! Elimina el puntero.
			m_pDepthStencilView = nullptr;
		}

		//! Si la textura es diferente de nulo.
		if (m_pTextureDSV != nullptr)
		{
			m_pTextureDSV->Destroy();//! Llama su funcion destroy.
			delete m_pTextureDSV;//! Elimina el puntero.
			m_pTextureDSV = nullptr;
		}
		//! Si la textura es diferente de nulo.
		if (m_pTextureRTV != nullptr)
		{
			m_pTextureRTV->Destroy();//! Llama su funcion destroy.
			delete m_pTextureRTV;//! Elimina el puntero.
			m_pTextureRTV = nullptr;
		}

		//! Si el inputlayaout es diferente de nulo.
		if (m_pInputLayout != nullptr)
		{
			m_pInputLayout->Destroy();//! Llama su funcion destroy.
			delete m_pInputLayout;//! Elimina el puntero.
			m_pInputLayout = nullptr;
		}

		//! Si el shaderresoureview diferente de nulo.
		if (m_pShaderResourceView != nullptr)
		{
			m_pShaderResourceView->Destroy();//! Llama su funcion destroy.
			delete m_pShaderResourceView;//! Elimina el puntero.
			m_pShaderResourceView = nullptr;
		}

		//! Si el sampler es diferente de nulo.
		if (m_pSampler != nullptr)
		{
			m_pSampler->Destroy();//! Llama su funcion destroy.
			delete m_pSampler;//! Elimina el puntero.
			m_pSampler = nullptr;
		}

		//! Si el blob es diferente de nulo.
		if (m_pBlob != nullptr)
		{
			m_pBlob->Destroy();//! Llama su funcion destroy.
			delete m_pBlob;//! Elimina el puntero.
			m_pBlob = nullptr;
		}

		m_uiScreenHandle = m_iHeight = m_iWidth = 0;
	}

	//! Funcion para crear el device context.
	void ceGraphicsAPI::CreateDevice()
	{
		//! Asignamos memoria al device.
		m_pDevice = new ceDevice();	
	}

	//! Funcion para crear el device context.
	void ceGraphicsAPI::CreateDeviceContext()
	{
		//! Asignamos memoria al devicecontext.
		m_pDeviceContext = new ceDeviceContext();
	}

	//! Funcion para crear el swapchain.
	void ceGraphicsAPI::CreateSwapChain(uint32 uiScreenHandle, int32 iWidth, int32 iHeight)
	{
		//! Asignamos memoria al swapchain.
		m_pSwapChain = new ceSwapChain();
		//! Creamos la cadena de int32ercambio y el dispositivo.
		m_pSwapChain->CreateSwapChainAndDevice(uiScreenHandle, iWidth, iHeight, *m_pDevice, *m_pDeviceContext);
			
	}

	//! Funcion para crear el render target view.
	void ceGraphicsAPI::CreateRenderTargetView()
	{
		/// Asignamosmemoria a la textura de render target.
		m_pTextureRTV = new ceTexture();
		//! Asignamos memoria al render target view.
		m_pRenderTargetView = new ceRenderTargetView();
		//! Creamos el render target view.
		m_pRenderTargetView->CreateRTV(m_pSwapChain, m_pDevice, *m_pTextureRTV);
	}

	//! Funcion para crear el depth stencil view.
	void ceGraphicsAPI::CreateDepthStencilView()
	{
		/// Asignamos memoria a la textura de depth stencil.
		m_pTextureDSV = new ceTexture();
		/// Asignamos memoria al depth stencil view.	
		m_pDepthStencilView = new ceDepthStencilView();
		/// Creamos el depth stencil view.
		m_pDepthStencilView->CreateDSV(m_pDevice, *m_pTextureDSV, m_iWidth, m_iHeight);
	}

	//! Funcion para crear el vertex shader.
	void ceGraphicsAPI::CreateVertexShader()
	{
		//! Asignamos memoria al vertex shader.
		m_pVertexShader = new ceVertexShader();
	
		//! Asignamos memoria al blob.
		m_pBlob = new ceBlob();
	
		//! Compilamos el shader desde un archivo.
		CompileShaderFromFile("VertexShader.hlsl", "VSMain", "vs_5_0", m_pBlob);
		//! Creamos el vertex shader.
		m_pVertexShader->CreateVertexShader(m_pDevice, m_pBlob);
			
	}

	//! Funcion para crear el pixel shader.
	void ceGraphicsAPI::CreatePixelShader()
	{
		//! Asignamos memoria al pixel shader.
		m_pPixelShader = new cePixelShader();

		//! Asignamos memoria al blob.
		ceBlob* pBlob = new ceBlob();
	
		//! Compilamos el shader desde un archivo.
		CompileShaderFromFile("PixelShader.hlsl", "PSMain", "ps_5_0", pBlob);
		//! Creamos el pixel shader.
		m_pPixelShader->CreatePixelShader(m_pDevice, pBlob);
	}

	//! Funcion para crear el inputlayout.
	void ceGraphicsAPI::CreateInputLayout()
	{
		//! Asignamos memoria al input layaout.
		m_pInputLayout = new ceInputLayout();

		//! Creamos el input layout.
		m_pInputLayout->CreateILO(m_pDevice, m_pBlob);
			
	}

	//! Funcion para crear los buffers constantes.
	void ceGraphicsAPI::CreateConstantBuffers()
	{
		for (int32 i = 0; i < g_iNumBuffer; i++)
		{
			ceConstantBuffer* pNewBuffer = new ceConstantBuffer();
			pNewBuffer->CreateBuffer(m_pDevice, sizeof(ceMatrix_4X4));
			m_pConstantBuffers.push_back(pNewBuffer);
		}
	}
	
	//! Funcion para setear la topologia.
	void ceGraphicsAPI::SetPrimitiveTopology()
	{
		/// Seteamos la topologia a utilizar.
		m_pDeviceContext->m_pDeviceContext->m_pDXDeviceContext->IASetPrimitiveTopology(
			D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	}

	//! Funcion para crear buffers constantes de luces.
	void ceGraphicsAPI::CreateConstantBuffersLight(uint32 uiSize)
	{
		ceConstantBuffer* pNewBuffer = new ceConstantBuffer();
		pNewBuffer->CreateBuffer(m_pDevice, uiSize);
		m_pConstantBuffers.push_back(pNewBuffer);
	}

	//! Funcion para crear un sampler.
	void ceGraphicsAPI::CreateSample()
	{
		//! Asignamos memoria al sampler.
		m_pSampler = new ceSampler();
	
		//! Creamos el sampler.
		m_pSampler->CreateSampler(m_pDevice);
			
	}

	void ceGraphicsAPI::CreateLight()
	{
		m_Diffuse.m_LightPosition = ceVector3D(3, 10, 0);
		m_Diffuse.m_Color = ceVector4D(0, 0.5, 1, 1);
	}

	//! Funcion para setear los render taregets.
	void ceGraphicsAPI::SetRenderTargets()
	{
		/// Seteamos los rendertargets.
		m_pDeviceContext->m_pDeviceContext->m_pDXDeviceContext->OMSetRenderTargets(1,
			&m_pRenderTargetView->m_pRenderTargetView->m_DXRenderTargetView, 
			m_pDepthStencilView->m_pDepthStencilView->m_DXDepthStencilView);
	}

	//! Funcion para setear el viewport.
	void ceGraphicsAPI::SetViewPort()
	{
		// Setup the viewport
		D3D11_VIEWPORT vp;
		vp.Width = (float)m_iWidth;
		vp.Height = (float)m_iHeight;
		vp.MinDepth = 0.0f;
		vp.MaxDepth = 1.0f;
		vp.TopLeftX = 0;
		vp.TopLeftY = 0;
		m_pDeviceContext->m_pDeviceContext->m_pDXDeviceContext->RSSetViewports(1, &vp);
	}

	//! Funcion para setear el inputlayout.
	void ceGraphicsAPI::SetInputLayout()
	{
		/// Seteamos el InputLayout
		m_pDeviceContext->m_pDeviceContext->m_pDXDeviceContext->IASetInputLayout(
			m_pInputLayout->m_pInputLayout->m_DXInputLayout);
	}

	//! Funcion para setear los shaders.
	void ceGraphicsAPI::SetShaders()
	{
		/// Seteamos el vertex shader.
		m_pDeviceContext->m_pDeviceContext->m_pDXDeviceContext->VSSetShader(
			m_pVertexShader->m_pVertexShader->m_DXVertexShader, nullptr, 0);

		/// Seteamos el pixel shader.
		m_pDeviceContext->m_pDeviceContext->m_pDXDeviceContext->PSSetShader(
			m_pPixelShader->m_pPixelShader->m_DXPixelShader, nullptr, 0);
	}

	//! Funcion para setear los constant buffers.
	void ceGraphicsAPI::SetConstantBuffers(ceMatrix_4X4* matProjectionCamera, ceMatrix_4X4* matViewCamera)
	{
		ceMatrix_4X4 matProjection = *matProjectionCamera;
		ceMatrix_4X4* tempProj = reinterpret_cast<ceMatrix_4X4*>(m_pConstantBuffers[0]->MapBuffer(m_pDeviceContext));
		*tempProj = matProjection;
		m_pConstantBuffers[0]->UnMapBuffer(m_pDeviceContext);
		m_pConstantBuffers[0]->SetBuffer(m_pDeviceContext, 0);

		ceMatrix_4X4 matView = *matViewCamera;
		ceMatrix_4X4* tempView = reinterpret_cast<ceMatrix_4X4*>(m_pConstantBuffers[1]->MapBuffer(m_pDeviceContext));
		*tempView = matView;
		m_pConstantBuffers[1]->UnMapBuffer(m_pDeviceContext);
		m_pConstantBuffers[1]->SetBuffer(m_pDeviceContext, 1);

		ceMatrix_4X4 matWorld = m_World.Transposed();
		ceMatrix_4X4* tempWorld = reinterpret_cast<ceMatrix_4X4*>(m_pConstantBuffers[2]->MapBuffer(m_pDeviceContext));
		*tempWorld = matWorld;
		m_pConstantBuffers[2]->UnMapBuffer(m_pDeviceContext);
		m_pConstantBuffers[2]->SetBuffer(m_pDeviceContext, 2);


		ceLight* Diffuse = reinterpret_cast<ceLight*>(m_pConstantBuffers[3]->MapBuffer(m_pDeviceContext));
		*Diffuse = m_Diffuse;
		m_pConstantBuffers[3]->UnMapBuffer(m_pDeviceContext);
		m_pConstantBuffers[3]->SetBuffer(m_pDeviceContext, 3);
	}

	void ceGraphicsAPI::SetSamplers()
	{
		/// Seteamos los samplers a utilizar.
		m_pDeviceContext->m_pDeviceContext->m_pDXDeviceContext->PSSetSamplers(
			0, 1, &m_pSampler->m_pSampler->m_DXSampler);
	}

	//! Funcion para compilar un shader desde un archivo.
	void ceGraphicsAPI::CompileShaderFromFile(const char* szFileName, const String szEntryPoint32, 
											const String szShaderModel, ceBlob* pBlobOut)
	{
		HRESULT hr = S_OK;
		

		//TODO: Implentar despues con mi propia clase de archivo.
		int32 iSize = 0;
		std::fstream file;
		String fileData;

		file.open(szFileName, std::ios::in | std::ios::out | std::ios::ate);
		iSize = file.tellg();//! Manda al final del archivo por tanto es el tamaño.
		file.seekg(0, std::fstream::beg);//! Funcion para regresar al inicio del archivo.

		
		fileData.resize(iSize + 1, 0);
		file.read(&fileData[0], iSize);
		file.seekg(iSize);
		file.close();



		DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )
		// Set the D3DCOMPILE_DEBUG flag to embed debug information in the shaders.
		// Setting this flag improves the shader debugging experience, but still allows 
		// the shaders to be optimized and to run exactly the way they will run in 
		// the release configuration of this program.
		dwShaderFlags |= D3DCOMPILE_DEBUG;
#endif

		ID3DBlob* pErrorBlob;
		
		hr = D3DCompile(fileData.c_str(), fileData.size(),szFileName, nullptr, nullptr,
			szEntryPoint32.c_str(),szShaderModel.c_str(),dwShaderFlags
			, 0, (ID3DBlob**)&pBlobOut->m_pBlob->m_pDXBlob, &pErrorBlob);

		if (FAILED(hr))
		{
			if (pErrorBlob != nullptr)
				OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());
			if (pErrorBlob) 
				pErrorBlob->Release();
			std::cout << "Fallo al Cargar el Archivo" << std::endl;
		}

		if (pErrorBlob) 
			pErrorBlob->Release();

	}
}