#pragma once
#include "ceBuffer.h"

namespace ceEngineSDK
{
	struct ceBufferDX;
	//! Clase index buffer hereda de buffer.
	class CE_GRAPHICS_EXPORT ceIndexBuffer : public ceBuffer
	{

	public:

		/************************************************************************/
		/*                       Constructor y Destructor						*/
		/************************************************************************/

		//! Constructor default.
		ceIndexBuffer();
		//! Destructor default.
		~ceIndexBuffer();

		/************************************************************************/
		/*                    Funciones de la clase								*/
		/************************************************************************/

		//! Funcion para crear un buffer.
		bool CreateBuffer(void* pDevice, Vector<uint32>& Indices);
		//! Funcion para setear un buffer.
		void SetBuffer(void* pDeviceContext);


		/************************************************************************/
		/*                             Funciones heredadas						*/
		/************************************************************************/

		//
		virtual void Destroy();

		//! Funcion que retorna un VertexBuffer como referencia.
		virtual void** GetBufferReference();
		//! Funcion que retorna un Buffer para guardar el mundo.
		virtual void* GetBuffer();

		//! Funcion de mapeado de buffer.
		virtual void* MapBuffer(void* pDeviceContext);
		//! Funcion de unmapeado de buffer.
		virtual void UnMapBuffer(void* pDeviceContext);
	};
}
