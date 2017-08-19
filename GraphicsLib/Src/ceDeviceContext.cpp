#include "ceDeviceContext.h"
#include <d3d11.h>
//#include <d3dx11.h>
#include <d3dcompiler.h>


namespace ceEngineSDK
{
	struct DeviceContext
	{
		ID3D11DeviceContext* m_pDXDeviceContext;
		void Destroy() { m_pDXDeviceContext->Release(); }
	};

	ceDeviceContext::ceDeviceContext()
	{
		m_pDeviceContext = nullptr;
		m_pDeviceContext = new DeviceContext();
	}


	ceDeviceContext::~ceDeviceContext()
	{
		Destroy();
	}

	void ceDeviceContext::Destroy()
	{
		if (m_pDeviceContext != nullptr)
		{
			m_pDeviceContext->Destroy();
			delete m_pDeviceContext;
			m_pDeviceContext = nullptr;
		}
	}
	
	void ** ceDeviceContext::GetDeviceContextReference()
	{
		//! Regresa el Buffer que no cambia int32erpretado como un void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pDeviceContext->m_pDXDeviceContext);
	}
	void * ceDeviceContext::GetDeviceContext()
	{
		//! Regresa el Buffer que no cambia int32erpretado como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pDeviceContext->m_pDXDeviceContext);
	}
}