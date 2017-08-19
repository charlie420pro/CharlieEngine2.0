#include "ceDevice.h"
#include <d3d11.h>
//#include <d3dx11.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	struct Device
	{
		ID3D11Device* m_DXDevice;
		void Destroy() { m_DXDevice->Release(); }
	};

	ceDevice::ceDevice()
	{
		m_pDevice = nullptr;
		m_pDevice = new Device();
	}


	ceDevice::~ceDevice()
	{
		Destroy();
	}

	void ceDevice::Destroy()
	{
		if (m_pDevice != nullptr)
		{
			m_pDevice->Destroy();
			delete m_pDevice;
			m_pDevice = nullptr;
		}
	}

	void** ceDevice::GetDeviceReference()
	{
		//! Regresa el Buffer que no cambia int32erpretado como un void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pDevice->m_DXDevice);
	}
	void* ceDevice::GetDevice()
	{
		//! Regresa el Buffer que no cambia int32erpretado como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pDevice->m_DXDevice);
	}
}