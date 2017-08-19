#include "ceInputLayaout.h"
#include <d3d11.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	struct InputLayout
	{
		ID3D11InputLayout* m_DXInputLayout;
		void Destroy() { m_DXInputLayout->Release(); }
	};

	ceInputLayaout::ceInputLayaout()
	{
		m_pInputLayaout = nullptr;
		m_pInputLayaout = new InputLayout();
	}


	ceInputLayaout::~ceInputLayaout()
	{
		Destroy();
	}

	void ceInputLayaout::Destroy()
	{
		if (m_pInputLayaout != nullptr)
		{
			m_pInputLayaout->Destroy();
			delete m_pInputLayaout;
			m_pInputLayaout = nullptr;
		}
	}

	void ** ceInputLayaout::GetInputLayoutReference()
	{
		//! Regresa el Buffer que no cambia int32erpretado como un void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pInputLayaout->m_DXInputLayout);
	}
	void* ceInputLayaout::GetInputLayout()
	{
		//! Regresa el Buffer que no cambia int32erpretado como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pInputLayaout->m_DXInputLayout);
	}

	void ceInputLayaout::CreateILO(void * pDevice, ceBlob * pBlob)
	{
		HRESULT hr = S_OK;

		ID3D11Device* pTempDevice = reinterpret_cast<ID3D11Device*>(pDevice);
		
		// Define the input layout
		D3D11_INPUT_ELEMENT_DESC layout[] =
		{
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT , 0,D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
		};
		uint32 numElements = ARRAYSIZE(layout);

		// Create the input layout
		hr = pTempDevice->CreateInputLayout(layout, numElements, pBlob->GetBufferPointer(),
			pBlob->GetBufferSize(), &m_pInputLayaout->m_DXInputLayout);

		pBlob->Destroy();
		if (FAILED(hr))
			std::cout << "Fallo al Crear ImputLayout" << std::endl;
		
	}
}
