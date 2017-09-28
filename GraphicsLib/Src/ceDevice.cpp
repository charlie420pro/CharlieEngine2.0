#include "ceDevice.h"
#include "DX11Headers.h"

namespace ceEngineSDK
{
	//! Constructor default.
	ceDevice::ceDevice()
	{
		m_pDevice = nullptr;
		m_pDevice = new Device();
	}

	//! Destructor default.
	ceDevice::~ceDevice()
	{
		Destroy();
	}

	//! Funcion para liberar la memoria del objeto.
	void ceDevice::Destroy()
	{
		if (m_pDevice != nullptr)
		{
			m_pDevice->Destroy();
			delete m_pDevice;
			m_pDevice = nullptr;
		}
	}
}