#pragma once
#include "cePrerequisitesGraphics.h"
#include "ceBlob.h"


namespace ceEngineSDK
{
	/************************************************************************/
	/*   Declaracion por delante de las estructuras definidas en el CPP		*/
	/************************************************************************/
	struct InputLayout;

	//! Clase inputlayaout.
	class CE_GRAPHICS_EXPORT ceInputLayaout
	{
	public:
		/************************************************************************/
		/*                      Constructor y Destructor.						*/
		/************************************************************************/

		//! Constructor default.
		ceInputLayaout();
		//! Destructor default.
		~ceInputLayaout();

		/************************************************************************/
		/*                     Variables miembro de la clase.					*/
		/************************************************************************/

		//! Puntero al inputlayaout.
		InputLayout* m_pInputLayaout;

		/************************************************************************/
		/*                     Funciones de clase.								*/
		/************************************************************************/

		/**
		 *	@brief Funcion para liberar memoria del objeto.
		 */
		void Destroy();

		//! Funcion para crear el IL.
		void CreateILO(void* pDevice, ceBlob* pBlob);

		/************************************************************************/
		/*                          Accesores.									*/
		/************************************************************************/

		//! Funcion para obtener por referencia el IL.
		void** GetInputLayoutReference();
		//! Funcion para obtener el IL.
		void* GetInputLayout();

		
	};
}
