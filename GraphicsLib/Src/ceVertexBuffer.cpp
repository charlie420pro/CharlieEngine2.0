#include "ceVertexBuffer.h"
#include <d3d11.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	/**
	 *	@brief Constructor default.
	 **/
	ceVertexBuffer::ceVertexBuffer()
	{
		__super::ceBuffer();
	}

	/**
	 *	@brief Destructor default.
	 **/
	ceVertexBuffer::~ceVertexBuffer()
	{
		Destroy();
	}

	
	/**
	*	@brief Funcion para destruir.
	**/
	void ceVertexBuffer::Destroy()
	{
		__super::Destroy();
	}

	/**
	 *	@brief Funcion para crear un buffer.
	 *	@param void* pDevice device para la creacion del buffer.
	 *  @param vector<ceVertex*> Vertex arreglo de vertices.
	 *  @return verdadero si se creo el buffer, falso en caso contrario.
	 **/
	bool ceVertexBuffer::CreateBuffer(void * pDevice, Vector<ceVertex>& Vertex)
	{
		
		HRESULT hr = S_OK;
		ID3D11Device* tempDevice = reinterpret_cast<ID3D11Device*>(pDevice);
		ID3D11Buffer** ppBufferRef = reinterpret_cast<ID3D11Buffer**>(GetBufferReference());

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

		
		hr = tempDevice->CreateBuffer(&bd, &InitData, ppBufferRef);
		if (FAILED(hr)) {
			return false;
		}
		
		return true;
	}

	/**
	 *	@brief Funcion para setear el buffer.
	 *	@param void* pDeviceContext el device context para setear el buffer.
	 **/
	void ceVertexBuffer::SetBuffer(void * pDeviceContext)
	{
		uint32 Stride = sizeof(ceVertex);
		uint32 Offset = 0;

		ID3D11DeviceContext* tempDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(pDeviceContext);
		ID3D11Buffer** ppBuffer = reinterpret_cast<ID3D11Buffer**>(GetBufferReference());

		tempDeviceContext->IASetVertexBuffers(0, 1, ppBuffer, &Stride, &Offset);
	}

	/**
	*	@brief Funcion para Obtener por referencia el buffer.
	*	@return Referencia del buffer.
	**/
	void ** ceVertexBuffer::GetBufferReference()
	{
		return __super::GetBufferReference();
	}

	/**
	*	@brief Funcion para obtener un puntero al buffer.
	*	@return Puntero al buffer.
	**/
	void * ceVertexBuffer::GetBuffer()
	{
		return __super::GetBuffer();	
	}

	/**
	*	@brief Funcion para mapear el buffer.
	*	@brief void* pDeviceContext el device context para mapear el buffer.
	*	@return Recurso mapeado.
	**/
	void * ceVertexBuffer::MapBuffer(void * pDeviceContext)
	{
		 return __super::MapBuffer(pDeviceContext);
	}

	/**
	*	@brief Funcion para hacer unmap al buffer.
	*	@brief void* pDeviceContext el device context para unmapear el buffer.
	**/
	void ceVertexBuffer::UnMapBuffer(void * pDeviceContext)
	{
		__super::UnMapBuffer(pDeviceContext);
	}
}