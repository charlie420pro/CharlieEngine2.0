#include "ceShaderResourceView.h"
#include <d3d11.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	struct ShaderResourceView
	{
		ID3D11ShaderResourceView* m_DXShaderResourceView;
		void Destroy() { m_DXShaderResourceView->Release(); }
	};
	ceShaderResourceView::ceShaderResourceView()
	{
		m_pShaderResourceView = nullptr;
		m_pShaderResourceView = new ShaderResourceView();
	}


	ceShaderResourceView::~ceShaderResourceView()
	{
		Destroy();
	}

	void ceShaderResourceView::Destroy()
	{
		if (m_pShaderResourceView != nullptr)
		{
			m_pShaderResourceView->Destroy();
			delete m_pShaderResourceView;
			m_pShaderResourceView = nullptr;
		}
	}

	void ** ceShaderResourceView::GetShaderResourceViewReference()
	{
		//! Regresa el Buffer que no cambia int32erpretado como un void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pShaderResourceView->m_DXShaderResourceView);
	}
	void * ceShaderResourceView::GetShaderResourceView()
	{
		//! Regresa el Buffer que no cambia int32erpretado como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pShaderResourceView->m_DXShaderResourceView);
	}
}