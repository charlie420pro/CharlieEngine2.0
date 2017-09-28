#include "ceVertexBuffer.h"
#include "DX11Headers.h"

namespace ceEngineSDK
{
	//! Constructor default de la clase.
	ceVertexBuffer::ceVertexBuffer()
	{
		/// Llama al constructor del padre.
		__super::ceBuffer();
	}

	//! Destructor default de clase.
	ceVertexBuffer::~ceVertexBuffer()
	{
		/// Llama al destructor del padre.
		__super::ceBuffer();
	}

	//! Funcion para liberar memoria del buffer constante.
	void ceVertexBuffer::Destroy()
	{
		/// Llama la funcion Destroy del padre.
		__super::Destroy();
	}

	//! Funcion para crear un buffer de vertices.
	bool ceVertexBuffer::CreateBuffer(ceDevice * pDevice, Vector<ceVertex>& Vertex)
	{
		
		HRESULT hr = S_OK;
	
		D3D11_BUFFER_DESC bd;
		ZeroMemory(&bd, sizeof(bd));
		bd.Usage = D3D11_USAGE_DEFAULT;
		bd.ByteWidth = sizeof(ceVertex) * Vertex.size();
		bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bd.CPUAccessFlags = 0;
		bd.MiscFlags = 0;
		bd.StructureByteStride = 0;


		D3D11_SUBRESOURCE_DATA InitData;
		ZeroMemory(&InitData, sizeof(InitData));
		InitData.pSysMem = &Vertex[0];

		
		hr = pDevice->m_pDevice->m_DXDevice->CreateBuffer(&bd, &InitData, &m_pBuffer->m_pDXBuffer);
		if (FAILED(hr)) {
			return false;
		}
		
		return true;
	}

	//! Funcion para setar el buffer de vertices.
	void ceVertexBuffer::SetBuffer(ceDeviceContext * pDeviceContext)
	{
		uint32 Stride = sizeof(ceVertex);
		uint32 Offset = 0;

		pDeviceContext->m_pDeviceContext->m_pDXDeviceContext->IASetVertexBuffers(0, 1, &m_pBuffer->m_pDXBuffer, &Stride, &Offset);
	}

	//! Funcion para mapear el buffer constante.
	void * ceVertexBuffer::MapBuffer(ceDeviceContext * pDeviceContext)
	{
		/// Llama la funcion MapBuffer del padre.
		return __super::MapBuffer(pDeviceContext);
	}

	//! Funcion para hacer unmap al buffer constante.
	void ceVertexBuffer::UnMapBuffer(ceDeviceContext * pDeviceContext)
	{
		/// Llama la funcion UnMapBuffer del padre.
		__super::UnMapBuffer(pDeviceContext);
	}
}