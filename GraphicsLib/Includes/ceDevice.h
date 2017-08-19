#pragma once
#include "cePrerequisitesGraphics.h"

namespace ceEngineSDK
{
	/************************************************************************/
	/*   Declaracion por delante de las estructuras definidas en el CPP		*/
	/************************************************************************/
	struct Device;

	//! Clase para utilizar objeto ceDevice.
	class CE_GRAPHICS_EXPORT ceDevice
	{
	public:
		//! Constructor default de la clase.
		ceDevice();
		//! Destructor default de la clase.
		~ceDevice();

		/************************************************************************/
		/*                     Variables miembro de la clase					*/
		/************************************************************************/

		//! Puntero a un device.
		Device* m_pDevice;

		/************************************************************************/
		/*                     Variables miembro de la clase					*/
		/************************************************************************/

		/**
		 *	@brief Funcion para mandar liberar la memoria del objeto.
		 */
		void Destroy();

		/************************************************************************/
		/*								Accesores								*/
		/************************************************************************/

		//! Funcion para obtener el device por referencia.
		void** GetDeviceReference();
		//! Funcion para obtener el device como puntero.
		void* GetDevice();
	};
}