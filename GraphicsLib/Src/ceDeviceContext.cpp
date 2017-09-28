#include "ceDeviceContext.h"
#include "DX11Headers.h"

namespace ceEngineSDK
{
	//! Constructor default.
	ceDeviceContext::ceDeviceContext()
	{
		m_pDeviceContext = nullptr;
		m_pDeviceContext = new DeviceContext();
	}

	//! Destructor default.
	ceDeviceContext::~ceDeviceContext()
	{
		Destroy();
	}

	//! Funcion para liberar memoria del objeto.
	void ceDeviceContext::Destroy()
	{
		if (m_pDeviceContext != nullptr)
		{
			m_pDeviceContext->Destroy();
			delete m_pDeviceContext;
			m_pDeviceContext = nullptr;
		}
	}
}