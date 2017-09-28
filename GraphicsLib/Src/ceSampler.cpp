#include "ceSampler.h"
#include "DX11Headers.h"

namespace ceEngineSDK
{
	//! Constructor default de la clase.
	ceSampler::ceSampler()
	{
		m_pSampler = nullptr;
		m_pSampler = new Sampler();
	}

	//! Destructor default de la clase.
	ceSampler::~ceSampler()
	{
		Destroy();
	}

	//! Funcion para liberar memoria del sampler.
	void ceSampler::Destroy()
	{
		if (m_pSampler != nullptr)
		{
			m_pSampler->Destroy();
			delete m_pSampler;
			m_pSampler = nullptr;
		}
	}

	//! Funcion para crear el sampler.
	void ceSampler::CreateSampler(ceDevice * pDevice)
	{
		HRESULT hr = S_OK;
	
		// Create the sample state
		D3D11_SAMPLER_DESC sampDesc;
		ZeroMemory(&sampDesc, sizeof(sampDesc));
		sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
		sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
		sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
		sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
		sampDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
		sampDesc.MinLOD = 0;
		sampDesc.MaxLOD = D3D11_FLOAT32_MAX;

		hr = pDevice->m_pDevice->m_DXDevice->CreateSamplerState(&sampDesc, &m_pSampler->m_DXSampler);

		if (FAILED(hr))
			std::cout << "Fallo al CrearSampler" << std::endl;
	}
}