#pragma once
#include "ceBuffer.h"

namespace ceEngineSDK
{
	///************************************************************************/
	///*   Declaracion por delante de las estructuras definidas en el CPP	  */
	///************************************************************************/
	struct ceBufferDX;

	//! Clase de buffers constantes hereda de buffer.
	class CE_GRAPHICS_EXPORT ceConstantBuffer : public ceBuffer 
	{
	public:
		/************************************************************************/
		/*                   Constructor y Destructor default					*/
		/************************************************************************/

		//! Constructor default.
		ceConstantBuffer();
		//! Destructor default.
		virtual~ceConstantBuffer();

		/************************************************************************/
		/*                    Funciones de la clase								*/
		/************************************************************************/

		
		//! Funcion para crear un buffer.
		bool CreateBuffer(void* pDevice);
		//! Funcion para setear un buffer.
		void SetBuffer(void* pDeviceContext, uint32 StartSlot);

		


		/************************************************************************/
		/*                         Funciones heredadas						    */
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