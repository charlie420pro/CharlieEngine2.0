#include "ceIndexBuffer.h"
#include "DX11Headers.h"

namespace ceEngineSDK
{
	//! Constructor default de la clase.
	ceIndexBuffer::ceIndexBuffer()
	{
		/// Llama al constructor del padre.
		__super::ceBuffer();
	}

	//! Destructor default de clase.
	ceIndexBuffer::~ceIndexBuffer()
	{
		/// Llama al destructor del padre.
		__super::ceBuffer();
	}

	//! Funcion para liberar memoria del buffer constante.
	void ceIndexBuffer::Destroy()
	{
		/// Llama la funcion Destroy del padre.
		__super::Destroy();
	}

	//! Funcion para crear un buffer de indices.
	bool ceIndexBuffer::CreateBuffer(ceDevice * pDevice, Vector<uint32>& Indices)
	{
		
		HRESULT hr = S_OK;
	
		D3D11_BUFFER_DESC bd;
		ZeroMemory(&bd, sizeof(bd));
		bd.Usage = D3D11_USAGE_DEFAULT;
		bd.ByteWidth = sizeof(uint32) * Indices.size();
		bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
		bd.CPUAccessFlags = 0;
		bd.MiscFlags = 0;
		bd.StructureByteStride = 0;

		D3D11_SUBRESOURCE_DATA InitData;
		ZeroMemory(&InitData, sizeof(InitData));
		InitData.pSysMem = &Indices[0];

		hr = pDevice->m_pDevice->m_DXDevice->CreateBuffer(&bd, &InitData, &m_pBuffer->m_pDXBuffer);
		if (FAILED(hr))
			return false;
		else
			return true;
	}

	//! Funcion para setar el buffer de indices.
	void ceIndexBuffer::SetBuffer(ceDeviceContext * pDeviceContext)
	{
		/// Seteamos el buffer de indices.
		pDeviceContext->m_pDeviceContext->m_pDXDeviceContext->IASetIndexBuffer(
			m_pBuffer->m_pDXBuffer, DXGI_FORMAT_R32_UINT, 0);
	}

	//! Funcion para mapear el buffer constante.
	void * ceIndexBuffer::MapBuffer(ceDeviceContext * pDeviceContext)
	{
		/// Llama la funcion MapBuffer del padre.
		return __super::MapBuffer(pDeviceContext);
	}

	//! Funcion para hacer unmap al buffer constante.
	void ceIndexBuffer::UnMapBuffer(ceDeviceContext * pDeviceContext)
	{
		/// Llama la funcion UnMapBuffer del padre.
		__super::UnMapBuffer(pDeviceContext);
	}
}