#include "ceRenderTargetView.h"
#include <d3d11.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	struct RTV
	{
		ID3D11RenderTargetView* m_DXRenderTargetView;
		void Destroy() { m_DXRenderTargetView->Release(); }
	};

	ceRenderTargetView::ceRenderTargetView()
	{
		m_pRenderTargetView = nullptr;
		m_pRenderTargetView = new RTV();
	}


	ceRenderTargetView::~ceRenderTargetView()
	{
		Destroy();
	}

	void ceRenderTargetView::Destroy()
	{
		if (m_pRenderTargetView != nullptr)
		{
			m_pRenderTargetView->Destroy();
			delete m_pRenderTargetView;
			m_pRenderTargetView = nullptr;
		}
	}

	void ** ceRenderTargetView::GetRenderTargetViewReference()
	{
		//! Regresa el Buffer que no cambia int32erpretado como un void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pRenderTargetView->m_DXRenderTargetView);
	}
	void * ceRenderTargetView::GetRenderTargetView()
	{
		//! Regresa el Buffer que no cambia int32erpretado como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pRenderTargetView->m_DXRenderTargetView);
	}

	void ceRenderTargetView::CreateRTV(void * pSwapChain, void * pDevice, ceTexture& pTexture)
	{
		IDXGISwapChain* pTempSwapChain = reinterpret_cast<IDXGISwapChain*>(pSwapChain);
		ID3D11Device* pTempDevice = reinterpret_cast<ID3D11Device*>(pDevice);

		//! Creamos un HRESULT a manera de bandera.
		HRESULT hr = S_OK;

		hr = pTempSwapChain->GetBuffer(0, IID_ID3D11Texture2D, pTexture.GetTextureReference());
		//! Si fallo 
		if (FAILED(hr))
			std::cout << "Fallo al Crear la Textura" << std::endl;

		//! //! Creamos el render target view.
		hr = pTempDevice->CreateRenderTargetView(reinterpret_cast<ID3D11Texture2D*>(pTexture.GetTexture()),
												nullptr, &m_pRenderTargetView->m_DXRenderTargetView);
		//! Si fallo
		if (FAILED(hr))
			std::cout << "Fallo al Crear RTV" << std::endl;

		
	}
}