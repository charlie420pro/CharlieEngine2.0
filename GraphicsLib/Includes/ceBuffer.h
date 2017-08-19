#pragma once
#include "cePrerequisitesGraphics.h"
#include "ceVertex.h"
#include "ceMatrix_4X4.h"

namespace ceEngineSDK
{
	///************************************************************************/
	///*   Declaracion por delante de las estructuras definidas en el CPP     */
	///************************************************************************/ 
	struct ceBufferDX;

	/** 
	 * @brief Clase para la utilizacion de buffers.
	 */
	class CE_GRAPHICS_EXPORT ceBuffer
	{
	public:

		/** 
		 *	@brief Constructor default de la clase.
		 */
		ceBuffer();

		/** 
		 *	@brief Destructor default de la clase.
		 */
		virtual~ceBuffer(); 


		///************************************************************************/
		///*                              Funciones de clase.					  */
		///************************************************************************/

		/**
		 *	@brief Funcion para destruir los recursos de la clase.
		 */
		virtual void Destroy();

		///************************************************************************/
		///*                              Accesores							      */
		///************************************************************************/

		//! Funcion que retorna un VertexBuffer como referencia.
		virtual void** GetBufferReference();
		//! Funcion que retorna un Buffer para guardar el mundo.
		virtual void* GetBuffer();

		
		//! Funcion de mapeado de buffer.
		virtual void* MapBuffer(void* pDeviceContext);
		//! Funcion de unmapeado de buffer.
		virtual void UnMapBuffer(void* pDeviceContext);

		

		///************************************************************************/
		///*						Variables miembro de la clase				  */
		///************************************************************************/

		//! Puntero a buffer DX
		ceBufferDX* m_pBuffer;	
	};
}
