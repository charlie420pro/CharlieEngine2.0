#include "ceInputLayout.h"
#include "DX11Headers.h"

namespace ceEngineSDK
{
	//! Constructor default.
	ceInputLayout::ceInputLayout()
	{
		m_pInputLayout = nullptr;
		m_pInputLayout = new InputLayout();
	}

	//! Destructor default.
	ceInputLayout::~ceInputLayout()
	{
		Destroy();
	}

	//! Funcion para liberar memoria del objeto.
	void ceInputLayout::Destroy()
	{
		if (m_pInputLayout != nullptr)
		{
			m_pInputLayout->Destroy();
			delete m_pInputLayout;
			m_pInputLayout = nullptr;
		}
	}

	//! Funcion para crear el InputLayout.
	void ceInputLayout::CreateILO(ceDevice * pDevice, ceBlob * pBlob)
	{
		HRESULT hr = S_OK;
	
		// Define the input layout
		D3D11_INPUT_ELEMENT_DESC layout[] =
		{
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT , 0,D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
		};
		uint32 numElements = ARRAYSIZE(layout);

		// Create the input layout
		hr = pDevice->m_pDevice->m_DXDevice->CreateInputLayout(
			layout, numElements, pBlob->GetBufferPointer(),
			pBlob->GetBufferSize(), &m_pInputLayout->m_DXInputLayout);

		pBlob->Destroy();
		if (FAILED(hr))
			std::cout << "Fallo al Crear ImputLayout" << std::endl;
		
	}
}
