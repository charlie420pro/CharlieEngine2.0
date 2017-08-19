#include "cePixelShader.h"
#include <d3d11.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	struct PixelShader
	{
		ID3D11PixelShader* m_DXPixelShader;
		void Destroy() { m_DXPixelShader->Release(); }
	};

	cePixelShader::cePixelShader()
	{
		m_pPixelShader = nullptr;
		m_pPixelShader = new PixelShader();
	}


	cePixelShader::~cePixelShader()
	{
		if (m_pPixelShader != nullptr)
		{
			m_pPixelShader->Destroy();
			delete m_pPixelShader;
		}
	}

	void ** cePixelShader::GetPixelShaderReference()
	{
		//! Regresa el Buffer que no cambia int32erpretado como un void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pPixelShader->m_DXPixelShader);
	}
	void* cePixelShader::GetPixelShader()
	{
		//! Regresa el Buffer que no cambia int32erpretado como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pPixelShader->m_DXPixelShader);
	}

	void cePixelShader::CreatePixelShader(void * pDevice, ceBlob * pBlob)
	{
		HRESULT hr = S_OK;
		ID3D11Device* pTempDevice =reinterpret_cast<ID3D11Device*>(pDevice);
		ID3DBlob* pTempBlob = reinterpret_cast<ID3DBlob*>(pBlob->GetBlob());

		// Create the pixel shader
		hr = pTempDevice->CreatePixelShader(pTempBlob->GetBufferPointer(),
			pTempBlob->GetBufferSize(), nullptr, &m_pPixelShader->m_DXPixelShader);


		pTempBlob->Release();
		if (FAILED(hr))
			std::cout << "Fallo al crear el PixelShader" << std::endl;
		
	}
}