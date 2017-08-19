#include "ceIndexBuffer.h"
#include <d3d11.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	/**
	 *	@brief Constructor default.
	 **/
	ceIndexBuffer::ceIndexBuffer()
	{
		__super::ceBuffer();
	}

	/**
	 *	@brief Destructor defult.
	 **/
	ceIndexBuffer::~ceIndexBuffer()
	{
		Destroy();
	}

	/**
	 *	@brief Funcion para crear un buffer.
	 *	@param void* pDevice device para la creacion del buffer.
	 *  @return verdadero si se creo el buffer, falso en caso contrario.
	 **/
	bool ceIndexBuffer::CreateBuffer(void * pDevice, Vector<uint32>& Indices)
	{
		
		HRESULT hr = S_OK;
		ID3D11Device* tempDevice = reinterpret_cast<ID3D11Device*>(pDevice);
		ID3D11Buffer** pBufferRef = reinterpret_cast<ID3D11Buffer**>(GetBufferReference());

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

		
		hr = tempDevice->CreateBuffer(&bd, &InitData, pBufferRef);
		if (FAILED(hr))
			return false;
		else
			return true;
	}

	/**
	 *	@brief Funcion para setear el buffer.
	 *	@param void* pDeviceContext el device context para setear el buffer.
	 **/
	void ceIndexBuffer::SetBuffer(void * pDeviceContext)
	{
		ID3D11DeviceContext* tempDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(pDeviceContext);
		ID3D11Buffer* pBuffer = reinterpret_cast<ID3D11Buffer*>(GetBuffer());
		tempDeviceContext->IASetIndexBuffer(pBuffer, DXGI_FORMAT_R32_UINT, 0);
	}

	void ceIndexBuffer::Destroy()
	{
		__super::Destroy();
	}

	/**
	*	@brief Funcion para Obtener por referencia el buffer.
	*	@return Referencia del buffer.
	**/
	void ** ceIndexBuffer::GetBufferReference()
	{
		return __super::GetBufferReference();
	}

	/**
	*	@brief Funcion para obtener un puntero al buffer.
	*	@return Puntero al buffer.
	**/
	void * ceIndexBuffer::GetBuffer()
	{
		return __super::GetBuffer();
	}

	/**
	*	@brief Funcion para mapear el buffer.
	*	@brief void* pDeviceContext el device context para mapear el buffer.
	*	@return Recurso mapeado.
	**/
	void * ceIndexBuffer::MapBuffer(void * pDeviceContext)
	{
		return __super::MapBuffer(pDeviceContext);
		
	}

	/**
	*	@brief Funcion para hacer unmap al buffer.
	*	@brief void* pDeviceContext el device context para unmapear el buffer.
	**/
	void ceIndexBuffer::UnMapBuffer(void * pDeviceContext)
	{
		__super::UnMapBuffer(pDeviceContext);
	}
}