#pragma once
#include "cePrerequisitesGraphics.h"

namespace ceEngineSDK
{
	/************************************************************************/
	/*   Declaracion por delante de las estructuras definidas en el CPP		*/
	/************************************************************************/
	struct ShaderResourceView;

	//! Clase de shader resource view.
	class CE_GRAPHICS_EXPORT ceShaderResourceView
	{
	public:
		/************************************************************************/
		/*                       Constructor y Destructor						*/
		/************************************************************************/

		//! Constructor default.
		ceShaderResourceView();
		//! Destructor default.
		~ceShaderResourceView();

		/************************************************************************/
		/*                      Variables miembro de clase.						*/
		/************************************************************************/

		//! Puntero al shader resource view.
		ShaderResourceView* m_pShaderResourceView;

		/************************************************************************/
		/*							Funciones de la clase.					    */
		/************************************************************************/

		/**
		 *	@brief Funcion para liberar memoria del objeto.
		 */
		void Destroy();

		//! Funcion para obtener por referencia el ShaderResourceView.
		void** GetShaderResourceViewReference();
		//! Funcion para obtener el ShaderResourceView.
		void* GetShaderResourceView();
	};
}
