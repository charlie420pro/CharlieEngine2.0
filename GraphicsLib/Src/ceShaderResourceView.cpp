#include "ceShaderResourceView.h"
#include "DX11Headers.h"

namespace ceEngineSDK
{
	//! Constructor default.
	ceShaderResourceView::ceShaderResourceView()
	{
		m_pShaderResourceView = nullptr;
		m_pShaderResourceView = new ShaderResourceView();
	}

	//! Destructor default.
	ceShaderResourceView::~ceShaderResourceView()
	{
		Destroy();
	}

	//! Funcion para liberar memoria del objeto.
	void ceShaderResourceView::Destroy()
	{
		if (m_pShaderResourceView != nullptr)
		{
			m_pShaderResourceView->Destroy();
			delete m_pShaderResourceView;
			m_pShaderResourceView = nullptr;
		}
	}
}