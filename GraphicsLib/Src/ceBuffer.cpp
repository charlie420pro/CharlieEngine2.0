#include "ceBuffer.h"
#include "DX11Headers.h"

namespace ceEngineSDK
{
	//! Constructor default.
	ceBuffer::ceBuffer()
	{
		m_pBuffer = nullptr;
		m_pBuffer = new Buffer();
	}

	//! Destructor default.
	ceBuffer::~ceBuffer()
	{
		Destroy();
	}

	//! Funcion para liberar memoria del buffer.
	void ceBuffer::Destroy()
	{
		if (m_pBuffer != nullptr)
		{
			m_pBuffer->Destroy();
			delete m_pBuffer;
			m_pBuffer = nullptr;
		}
	}

	//! Funcion para mapear un buffer.
	void * ceBuffer::MapBuffer(ceDeviceContext* pDeviceContext)
	{
		D3D11_MAPPED_SUBRESOURCE ms = {};
	
		pDeviceContext->m_pDeviceContext->m_pDXDeviceContext->Map(m_pBuffer->m_pDXBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &ms);
		return ms.pData;
	}

	//! Funcion para hacer unmap al buffer.
	void ceBuffer::UnMapBuffer(ceDeviceContext* pDeviceContext)
	{
		pDeviceContext->m_pDeviceContext->m_pDXDeviceContext->Unmap(m_pBuffer->m_pDXBuffer, 0);
	}
	
}