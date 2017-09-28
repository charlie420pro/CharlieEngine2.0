#include "ceDepthStencilView.h"
#include "DX11Headers.h"

namespace ceEngineSDK
{
	//! Constructor default de la clase.
	ceDepthStencilView::ceDepthStencilView()
	{
		m_pDepthStencilView = nullptr;
		m_pDepthStencilView = new DepthStencilView();
	}

	//! Destructor default de la clase.
	ceDepthStencilView::~ceDepthStencilView()
	{
		Destroy();
	}

	//! Funcion para liberar memoria de la clase.
	void ceDepthStencilView::Destroy()
	{
		if (m_pDepthStencilView != nullptr)
		{
			m_pDepthStencilView->Destroy();
			delete m_pDepthStencilView;
			m_pDepthStencilView = nullptr;
		}
	}
	
	//! Funcion para crear el DepthStencilView.
	void ceDepthStencilView::CreateDSV(ceDevice * pDevice, ceTexture& pTexture, int32 iWidth, int32 iHeight)
	{
		
		HRESULT hr = S_OK;
		D3D11_TEXTURE2D_DESC descDepth; /// Descriptor de la textura.
		ZeroMemory(&descDepth, sizeof(descDepth));
		descDepth.Width = iWidth;
		descDepth.Height = iHeight;
		descDepth.MipLevels = 1;
		descDepth.ArraySize = 1;
		descDepth.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		descDepth.SampleDesc.Count = 1;
		descDepth.SampleDesc.Quality = 0;
		descDepth.Usage = D3D11_USAGE_DEFAULT;
		descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
		descDepth.CPUAccessFlags = 0;
		descDepth.MiscFlags = 0;

		hr = pDevice->m_pDevice->m_DXDevice->CreateTexture2D(&descDepth, nullptr, 
			&pTexture.m_pTexture->m_pDXTexture);

		if (FAILED(hr))
			std::cout << "Fallo al Crear la Textura" << std::endl;

		hr = pDevice->m_pDevice->m_DXDevice->CreateDepthStencilView(pTexture.m_pTexture->m_pDXTexture,
			nullptr, &m_pDepthStencilView->m_DXDepthStencilView);
		if (FAILED(hr))
			std::cout << "Fallo al Crear DSV" << std::endl;

	}
}