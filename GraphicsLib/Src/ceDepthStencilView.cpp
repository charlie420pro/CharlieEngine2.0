#include "ceDepthStencilView.h"
#include <d3d11.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	struct ceDSV
	{
		ID3D11DepthStencilView* m_DXDepthStencilView;
		void Destroy() { m_DXDepthStencilView->Release(); }
	};

	ceDepthStencilView::ceDepthStencilView()
	{
		m_pDepthStencilView = nullptr;
		m_pDepthStencilView = new ceDSV();
	}


	ceDepthStencilView::~ceDepthStencilView()
	{
		Destroy();
	}

	void ceDepthStencilView::Destroy()
	{
		if (m_pDepthStencilView != nullptr)
		{
			m_pDepthStencilView->Destroy();
			delete m_pDepthStencilView;
			m_pDepthStencilView = nullptr;
		}
	}
	
	void** ceDepthStencilView::GetDepthStencilViewReference()
	{
		//! Regresa el Buffer que no cambia int32erpretado como un void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pDepthStencilView->m_DXDepthStencilView);
	}

	void* ceDepthStencilView::GetDepthStencilView()
	{
		//! Regresa el Buffer que no cambia int32erpretado como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pDepthStencilView->m_DXDepthStencilView);
	}

	void ceDepthStencilView::CreateDSV(void * pDevice, ceTexture& pTexture, int32 iWidth, int32 iHeight)
	{
		
		ID3D11Device* pTempDevice = reinterpret_cast<ID3D11Device*>(pDevice);

		HRESULT hr = S_OK;
		// Create depth stencil texture
		D3D11_TEXTURE2D_DESC descDepth;
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

		hr = pTempDevice->CreateTexture2D(&descDepth, nullptr, 
			(ID3D11Texture2D**)pTexture.GetTextureReference());
		if (FAILED(hr))
			std::cout << "Fallo al Crear la Textura" << std::endl;

		hr = pTempDevice->CreateDepthStencilView((ID3D11Texture2D*)pTexture.GetTexture(),
			nullptr, &m_pDepthStencilView->m_DXDepthStencilView);
		if (FAILED(hr))
			std::cout << "Fallo al Crear DSV" << std::endl;

	}
}