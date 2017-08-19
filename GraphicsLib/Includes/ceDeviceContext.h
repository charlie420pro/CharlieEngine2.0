#pragma once
#include "cePrerequisitesGraphics.h"

namespace ceEngineSDK
{
	/************************************************************************/
	/*   Declaracion por delante de las estructuras definidas en el CPP		*/
	/************************************************************************/
	struct DeviceContext;

	//! Clase para la utilizacion de objetos ceDeviceContext.
	class CE_GRAPHICS_EXPORT ceDeviceContext
	{
	public:
		//! Constructor default.
		ceDeviceContext();
		//! Destructor default.
		~ceDeviceContext();

		/************************************************************************/
		/*						Variables miembro de la clase					*/
		/************************************************************************/

		//! Puntero a un objeto DeviceContext.
		DeviceContext* m_pDeviceContext;

		/**
		 *	@brief Funcion para liberar la memoria del objeto.
		 */
		void Destroy();

		/************************************************************************/
		/*								Accesores								*/	
		/************************************************************************/

		//! Funcion para obtener el DeviceContext por parametro.
		void** GetDeviceContextReference();
		//! Funcion para obtener el deviceContext como puntero.
		void* GetDeviceContext();
	};
}
