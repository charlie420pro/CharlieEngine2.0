#pragma once
#include "cePrerequisitesGraphics.h"

namespace ceEngineSDK
{
	///************************************************************************/
	///*   Declaracion por delante de las estructuras definidas en DXHeaders  */
	///************************************************************************/ 
	struct DeviceContext;

	/**
	 *	@brief Clase para la utilizacion de objetos DeviceContext.
	 */
	class CE_GRAPHICS_EXPORT ceDeviceContext
	{
		///************************************************************************/
		///*                     Friends de Clases.								  */
		///************************************************************************/

	private:
		friend class ceGraphicsAPI;

		///************************************************************************/
		///*                   Constructor y Destructor de la clase.			  */
		///************************************************************************/

	public:

		/**
		 *	@brief Constructor default de la clase.
		 */
		ceDeviceContext();

		/**
		 *	@brief Destructor default de la clase.
		 */
		~ceDeviceContext();

		///************************************************************************/
		///*						Variables miembro de la clase				  */
		///************************************************************************/

		/** 
		 *	@brief Puntero a un objeto DeviceContext.
		 */
		DeviceContext* m_pDeviceContext;

		///************************************************************************/
		///*                        Funciones de clase.							  */
		///************************************************************************/

		/**
		 *	@brief Funcion para mandar liberar la memoria del objeto.
		 */
		void Destroy();
	};
}
