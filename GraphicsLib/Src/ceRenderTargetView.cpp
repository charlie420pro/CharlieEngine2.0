#include "ceRenderTargetView.h"
#include "DX11Headers.h"

namespace ceEngineSDK
{
	
	//! Constructor default.
	ceRenderTargetView::ceRenderTargetView()
	{
		m_pRenderTargetView = nullptr;
		m_pRenderTargetView = new RenderTargetView();
	}

	//! Destructor default.
	ceRenderTargetView::~ceRenderTargetView()
	{
		Destroy();
	}

	//! Funcion para liberar memoria del objeto.
	void ceRenderTargetView::Destroy()
	{
		if (m_pRenderTargetView != nullptr)
		{
			m_pRenderTargetView->Destroy();
			delete m_pRenderTargetView;
			m_pRenderTargetView = nullptr;
		}
	}

	//! Funcion para crear el Render Target View.
	void ceRenderTargetView::CreateRTV(ceSwapChain* pSwapChain, ceDevice* pDevice, ceTexture& pTexture)
	{
	
		/// Creamos un HRESULT a manera de bandera.
		HRESULT hr = S_OK;

		hr = pSwapChain->m_pSwapChain->m_DXSwapChain->GetBuffer(
			0, IID_ID3D11Texture2D,
			reinterpret_cast<void**>(&pTexture.m_pTexture->m_pDXTexture));
		
		if (FAILED(hr))
			std::cout << "Fallo al Crear la Textura" << std::endl;

		/// Creamos el render target view.
		hr = pDevice->m_pDevice->m_DXDevice->CreateRenderTargetView(
			pTexture.m_pTexture->m_pDXTexture,
			nullptr, &m_pRenderTargetView->m_DXRenderTargetView);

		if (FAILED(hr))
			std::cout << "Fallo al Crear RTV" << std::endl;

		
	}
}