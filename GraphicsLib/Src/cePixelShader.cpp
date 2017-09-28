#include "cePixelShader.h"
#include "DX11Headers.h"

namespace ceEngineSDK
{
	//! Constructor default.
	cePixelShader::cePixelShader()
	{
		m_pPixelShader = nullptr;
		m_pPixelShader = new PixelShader();
	}

	//! Destructor default.
	cePixelShader::~cePixelShader()
	{
		Destroy();
	}

	//! Funcion para liberar memoria.
	void cePixelShader::Destroy()
	{
		if (m_pPixelShader != nullptr)
		{
			m_pPixelShader->Destroy();
			delete m_pPixelShader;
			m_pPixelShader = nullptr;
		}
	}

	void cePixelShader::CreatePixelShader(ceDevice * pDevice, ceBlob * pBlob)
	{
		HRESULT hr = S_OK;
	
		// Create the pixel shader
		hr = pDevice->m_pDevice->m_DXDevice->CreatePixelShader(pBlob->GetBufferPointer(),
			pBlob->GetBufferSize(), nullptr, &m_pPixelShader->m_DXPixelShader);


		pBlob->Destroy();
		if (FAILED(hr))
			std::cout << "Fallo al crear el PixelShader" << std::endl;
		
	}
}