#include "ceConstantBuffer.h"
#include "DX11Headers.h"

namespace ceEngineSDK
{
	//! Constructor default de la clase.
	ceConstantBuffer::ceConstantBuffer()
	{
		/// Llama al constructor del padre.
		__super::ceBuffer();
	}

	//! Destructor default de clase.
	ceConstantBuffer::~ceConstantBuffer()
	{
		/// Llama al destructor del padre.
		__super::ceBuffer();
	}

	//! Funcion para liberar memoria del buffer constante.
	void ceConstantBuffer::Destroy()
	{
		/// Llama la funcion Destroy del padre.
		__super::Destroy();
	}

	//! Funcion para crear el buffer constante.
	bool ceConstantBuffer::CreateBuffer(ceDevice * pDevice, uint32 uiSize)
	{
		HRESULT hr = S_OK;		/// Creamos el HRESULT para saber si el buffer se creo bien.
		D3D11_BUFFER_DESC bd;	/// Descriptor del buffer.

		/// Seteamos como es que queremos crear el buffer constante.
		ZeroMemory(&bd, sizeof(bd));
		bd.Usage = D3D11_USAGE_DYNAMIC;
		bd.ByteWidth = (uiSize + 15) & 0xfffffff0;
		bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		bd.MiscFlags = 0;
		bd.StructureByteStride = 0;

		/// Creamos el buffer.
		hr = pDevice->m_pDevice->m_DXDevice->CreateBuffer(&bd, nullptr, &m_pBuffer->m_pDXBuffer);

		/// Checamos que se haya creado de manera exitosa regresando verdadero si este fue el caso.
		if (FAILED(hr))
			return false;
		else
			return true;
	}

	//! Funcion para setear el buffer constante.
	void ceConstantBuffer::SetBuffer(ceDeviceContext * pDeviceContext, uint32 StartSlot)
	{
		/// Seteamos el constante buffer.
		pDeviceContext->m_pDeviceContext->m_pDXDeviceContext->VSSetConstantBuffers(
			StartSlot, 1, &m_pBuffer->m_pDXBuffer);
	}

	//! Funcion para mapear el buffer constante.
	void * ceConstantBuffer::MapBuffer(ceDeviceContext * pDeviceContext)
	{
		/// Llama la funcion MapBuffer del padre.
		return __super::MapBuffer(pDeviceContext);
	}

	//! Funcion para hacer unmap al buffer constante.
	void ceConstantBuffer::UnMapBuffer(ceDeviceContext * pDeviceContext)
	{
		/// Llama la funcion UnMapBuffer del padre.
		__super::UnMapBuffer(pDeviceContext);
	}
}