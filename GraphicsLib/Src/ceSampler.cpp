#include "ceSampler.h"
#include "DX11Headers.h"

namespace ceEngineSDK
{
	
	ceSampler::ceSampler()
	{
		m_pSampler = nullptr;
		m_pSampler = new Sampler();
	}


	ceSampler::~ceSampler()
	{
		Destroy();
	}

	void ceSampler::Destroy()
	{
		if (m_pSampler != nullptr)
		{
			m_pSampler->Destroy();
			delete m_pSampler;
			m_pSampler = nullptr;
		}
	}

	void ** ceSampler::GetSamplerReference()
	{
		//! Regresa el Buffer que no cambia int32erpretado como un void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pSampler->m_DXSamplerLinear);
	}
	void* ceSampler::GetSampler()
	{
		//! Regresa el Buffer que no cambia int32erpretado como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pSampler->m_DXSamplerLinear);
	}

	void ceSampler::CreateSampler(void * pDevice)
	{
		HRESULT hr = S_OK;
		ID3D11Device* pTempDevice = reinterpret_cast<ID3D11Device*>(pDevice);
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

		hr = pTempDevice->CreateSamplerState(&sampDesc, &m_pSampler->m_DXSamplerLinear);

		if (FAILED(hr))
			std::cout << "Fallo al CrearSampler" << std::endl;
	}
}