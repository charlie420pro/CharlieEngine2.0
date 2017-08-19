#include "ceVertexShader.h"
#include <d3d11.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	struct VertexShader
	{
		ID3D11VertexShader* m_DXVertexShader;
		void Destroy() { m_DXVertexShader->Release(); }
	};

	ceVertexShader::ceVertexShader()
	{
		m_pVertexShader = nullptr;
		m_pVertexShader = new VertexShader();
	}


	ceVertexShader::~ceVertexShader()
	{
		Destroy();
	}

	void ceVertexShader::Destroy()
	{
		if (m_pVertexShader != nullptr)
		{
			m_pVertexShader->Destroy();
			delete m_pVertexShader;
			m_pVertexShader = nullptr;
		}
	}

	void ** ceVertexShader::GetVertexShaderReference()
	{
		//! Regresa el Buffer que no cambia int32erpretado como un void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pVertexShader->m_DXVertexShader);
	}
	void * ceVertexShader::GetVertexShader()
	{
		//! Regresa el Buffer que no cambia int32erpretado como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pVertexShader->m_DXVertexShader);
	}

	void ceVertexShader::CreateVertexShader(void * pDevice, ceBlob * pBlob)
	{
		ID3D11Device* pTempDevice = reinterpret_cast<ID3D11Device*>(pDevice);
		ID3DBlob* pTempBlob = reinterpret_cast<ID3DBlob*>(pBlob->GetBlob());

		HRESULT hr = S_OK;
		// Create the vertex shader
		hr = pTempDevice->CreateVertexShader(pTempBlob->GetBufferPointer(),
											pTempBlob->GetBufferSize(),
											nullptr, &m_pVertexShader->m_DXVertexShader);
		if (FAILED(hr))
		{
			pTempBlob->Release();
			std::cout << "Fallo al crear el Vertex Shader" << std::endl;
		}

	}
}