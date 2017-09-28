#pragma once
#include "cePrerequisitesGraphics.h"

namespace ceEngineSDK
{
	///************************************************************************/
	///*   Declaracion por delante de las estructuras definidas en DXHeaders  */
	///************************************************************************/
	struct Device;

	/**
	 *	@brief Clase para utilizar un Device.
	 */
	class CE_GRAPHICS_EXPORT ceDevice
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

		ceDevice();
		/** 
		 *	@brief Destructor default de la clase.
		 */
		~ceDevice();

		///************************************************************************/
		///*                     Variables miembro de la clase					  */
		///************************************************************************/

		/**
		 *	@brief Puntero a un device.
		 */
		Device* m_pDevice;

		///************************************************************************/
		///*                        Funciones de clase.							  */
		///************************************************************************/

		/**
		 *	@brief Funcion para mandar liberar la memoria del objeto.
		 */
		void Destroy();

	};
}