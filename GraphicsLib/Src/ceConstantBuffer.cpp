#include "ceConstantBuffer.h"
#include <d3d11.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	/**
	 *	@brief Constructor default de la clase.
	 **/
	ceConstantBuffer::ceConstantBuffer()
	{
		__super::ceBuffer();
	}

	/**
	 *	@brief Destructor default de la clase.
	 **/
	ceConstantBuffer::~ceConstantBuffer()
	{
		__super::ceBuffer();
	}

	/**
	 *	@brief Funcion para crear un buffer.
	 *	@param void* pDevice device para la creacion del buffer.
	 *	@return verdadero si se creo el buffer, falso en caso contrario
	 **/
	bool ceConstantBuffer::CreateBuffer(void * pDevice)
	{
		HRESULT hr = S_OK;
		ID3D11Device* tempDevice = reinterpret_cast<ID3D11Device*>(pDevice);
		ID3D11Buffer** ppBuffer = reinterpret_cast<ID3D11Buffer**>(GetBufferReference());

		D3D11_BUFFER_DESC bd;
		ZeroMemory(&bd, sizeof(bd));
		bd.Usage = D3D11_USAGE_DYNAMIC;
		bd.ByteWidth = (sizeof(ceMatrix_4X4)); /*+ 15) & 0xfffffff0;*/
		bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		bd.MiscFlags = 0;
		bd.StructureByteStride = 0;

		hr = tempDevice->CreateBuffer(&bd, nullptr, ppBuffer);

		if (FAILED(hr))
			return false;
		else
			return true;
	}

	/**
	 *	@brief Funcion para setear el buffer.
	 *	@param void* pDeviceContext el device context para setear el buffer.
	 *	@param uint32 StartSlot Posicion donde va a iniciar el buffer.
	 *	@param uint32 Numbuffer Numero de buffers a setear.
	 **/
	void ceConstantBuffer::SetBuffer(void * pDeviceContext, uint32 StartSlot)
	{
		ID3D11DeviceContext* tempDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(pDeviceContext);
		ID3D11Buffer** ppBuffer = reinterpret_cast<ID3D11Buffer**>(GetBufferReference());
		tempDeviceContext->VSSetConstantBuffers(StartSlot, 1, ppBuffer);
	}

	void ceConstantBuffer::Destroy()
	{
		__super::Destroy();
	}

	/**
	 *	@brief Funcion para Obtener por referencia el buffer.
	 *	@return Referencia del buffer.
	 **/
	 void ** ceConstantBuffer::GetBufferReference()
	{
		return __super::GetBufferReference();
	}

	/**
	 *	@brief Funcion para obtener un puntero al buffer.
	 *	@return Puntero al buffer.
	 **/
	void * ceConstantBuffer::GetBuffer()
	{
		return __super::GetBuffer();
	}

	/**
	 *	@brief Funcion para mapear el buffer.
	 *	@brief void* pDeviceContext el device context para mapear el buffer.
	 *	@return Recurso mapeado.
	 **/
	void * ceConstantBuffer::MapBuffer(void * pDeviceContext)
	{
		return __super::MapBuffer(pDeviceContext);
	}

	/**
	 *	@brief Funcion para hacer unmap al buffer.
	 *	@brief void* pDeviceContext el device context para unmapear el buffer.
	 **/
	void ceConstantBuffer::UnMapBuffer(void * pDeviceContext)
	{
		__super::UnMapBuffer(pDeviceContext);
	}


}