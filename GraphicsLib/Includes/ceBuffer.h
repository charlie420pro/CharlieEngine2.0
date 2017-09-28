#pragma once
#include "cePrerequisitesGraphics.h"
#include "ceDevice.h"
#include "ceDeviceContext.h"

namespace ceEngineSDK
{
	///************************************************************************/
	///*   Declaracion por delante de las estructuras definidas en DXHeaders  */
	///************************************************************************/ 
	struct Buffer;

	/** 
	 * @brief Clase para la utilizacion de buffers.
	 */
	class CE_GRAPHICS_EXPORT ceBuffer
	{

		///************************************************************************/
		///*                     Friends de Clase.								  */
		///************************************************************************/

	private:
		friend class ceGraphicsAPI;

		///************************************************************************/
		///*                          Constructor y Destructor.					  */
		///************************************************************************/

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
		///*						Variables miembro de la clase				  */
		///************************************************************************/

		/**
		 *	@brief Puntero a un buffer.
		 */
		Buffer* m_pBuffer;

		///************************************************************************/
		///*                              Funciones de clase.					  */
		///************************************************************************/

		/**
		 *	@brief Funcion para liberar memoria de la clase.
		 */
		virtual void Destroy();
	
		/**
		 *	@brief Funcin para mapear un buffer.
		 *	@param ceDeviceContext* pDeviceContext: El device context que se requiere para mapear el buffer.
		 *	@return recurso mapeado visto como void*.
		 */
		virtual void* MapBuffer(ceDeviceContext* pDeviceContext);

		/**
		 *	@brief Funcion de un map para el buffer.
		 *	@param ceDeviceContext* pDeviceContext: El device context que se requiere llamar la funcion de unmap.
		 */
		virtual void UnMapBuffer(ceDeviceContext* pDeviceContext);	
	};
}
