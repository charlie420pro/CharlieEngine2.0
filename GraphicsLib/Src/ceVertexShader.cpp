#include "ceVertexShader.h"
#include "DX11Headers.h"

namespace ceEngineSDK
{
	//! Constructor default.
	ceVertexShader::ceVertexShader()
	{
		m_pVertexShader = nullptr;
		m_pVertexShader = new VertexShader();
	}

	//! Destructor default.
	ceVertexShader::~ceVertexShader()
	{
		Destroy();
	}

	//! Funcion para liberar memoria.
	void ceVertexShader::Destroy()
	{
		if (m_pVertexShader != nullptr)
		{
			m_pVertexShader->Destroy();
			delete m_pVertexShader;
			m_pVertexShader = nullptr;
		}
	}

	void ceVertexShader::CreateVertexShader(ceDevice * pDevice, ceBlob * pBlob)
	{
		HRESULT hr = S_OK;
		// Create the vertex shader
		hr = pDevice->m_pDevice->m_DXDevice->CreateVertexShader(pBlob->GetBufferPointer(),
											pBlob->GetBufferSize(),
											nullptr, &m_pVertexShader->m_DXVertexShader);
		if (FAILED(hr))
		{
			pBlob->Destroy();
			std::cout << "Fallo al crear el Vertex Shader" << std::endl;
		}

	}
}