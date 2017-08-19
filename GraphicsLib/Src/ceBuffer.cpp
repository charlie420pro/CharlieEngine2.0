#include "ceBuffer.h"
#include <d3d11.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	/**
	 *	@brief Estructura para el buffer de DirectX
	 **/
	struct ceBufferDX
	{
		ID3D11Buffer*  m_pDXBuffer;	
		void Destroy() {if(m_pDXBuffer != nullptr) m_pDXBuffer->Release(); }
	};

	/**
	 *	@brief Constructor default.
	 **/
	ceBuffer::ceBuffer()
	{
		m_pBuffer = nullptr;
		m_pBuffer = new ceBufferDX();
	}

	/**
	 *	@brief Destructor default.
	 **/
	ceBuffer::~ceBuffer()
	{
		Destroy();
	}

	void ceBuffer::Destroy()
	{
		if (m_pBuffer != nullptr)
		{
			m_pBuffer->Destroy();
			delete m_pBuffer;
			m_pBuffer = nullptr;
		}
	}

	/**
	 *	@brief Funcion que retorna un VertexBuffer de DirectX por referencia.
	 *  @return void** El buffer por referencia reint32erpretado como void**.
	 */
	void** ceBuffer::GetBufferReference()
	{
		return reinterpret_cast<void**>(&m_pBuffer->m_pDXBuffer);
	}

	/**
	*	@brief Funcion que retorna un Buffer de DirectX.
	*  @return void* Puntero al buffer reint32erpretado como void*.
	*/
	void* ceBuffer::GetBuffer()
	{
		return reinterpret_cast<void*>(m_pBuffer->m_pDXBuffer);
	}


	/**
	 *	@brief Funcion para mapear el buffer.
	 *	@brief void* pDeviceContext el device context para mapear el buffer.
	 *  @return void* recurso mapeado.
	 **/
	void * ceBuffer::MapBuffer(void* pDeviceContext)
	{
		D3D11_MAPPED_SUBRESOURCE ms = {};
		ID3D11DeviceContext* tempDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(pDeviceContext);

		tempDeviceContext->Map(m_pBuffer->m_pDXBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &ms);
		return ms.pData;
	}

	/**
	 *	@brief Funcion para unmapear el buffer.
	 *	@param void* pDeviceContext el device context para unmapear el buffer.
	 **/
	void ceBuffer::UnMapBuffer(void* pDeviceContext)
	{
		ID3D11DeviceContext* tempDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(pDeviceContext);
		tempDeviceContext->Unmap(m_pBuffer->m_pDXBuffer, 0);
	}
	
}