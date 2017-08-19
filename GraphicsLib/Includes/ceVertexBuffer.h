#pragma once
#include "ceBuffer.h"

namespace ceEngineSDK
{
	struct ceBufferDX;
	//! Clase vertexbuffer hereda de cebuffer.
	class CE_GRAPHICS_EXPORT ceVertexBuffer : public ceBuffer
	{

	public:
		/************************************************************************/
		/*                    Constructor y Destructor default.					*/
		/************************************************************************/

		//! Constructor default.
		ceVertexBuffer();
		//! Destructor default.
		virtual~ceVertexBuffer();

		/************************************************************************/
		/*                    Funciones de la clase								*/
		/************************************************************************/

		//! Funcion para crear un buffer.
		bool CreateBuffer(void* pDevice, Vector<ceVertex>& Vertex);
		//! Funcion para setear un buffer.
		void SetBuffer(void* pDeviceContext);


		/************************************************************************/
		/*                          Funciones heredadas							*/
		/************************************************************************/

		//! Funcion para destruir.
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