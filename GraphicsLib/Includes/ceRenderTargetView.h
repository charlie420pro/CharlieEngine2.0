#pragma once
#include "cePrerequisitesGraphics.h"
#include "ceTexture.h"

namespace ceEngineSDK
{
	/************************************************************************/
	/*   Declaracion por delante de las estructuras definidas en el CPP		*/
	/************************************************************************/
	struct RTV;

	//! Clase de render target view.
	class CE_GRAPHICS_EXPORT ceRenderTargetView
	{
	public:
		/************************************************************************/
		/*                       Constructor y Destructor						*/
		/************************************************************************/

		//! Constructor default.
		ceRenderTargetView();
		//! Destructor default.
		~ceRenderTargetView();

		/************************************************************************/
		/*                      Variables miembro de clase.						*/
		/************************************************************************/

		//! Puntero al render target view.
		RTV* m_pRenderTargetView;

		/************************************************************************/
		/*                      Funciones de clase.								*/
		/************************************************************************/

		/**
		 *	@brief Funcion para liberar memoria del objeto.
		 */
		void Destroy();

		//! Funcion para crear el RTV.
		void CreateRTV(void* pSwapChain, void* pDevice, ceTexture& pTexture);

		/************************************************************************/
		/*							Accesores.									*/
		/************************************************************************/

		//! Funcion para obtener por referencia el RTV.
		void** GetRenderTargetViewReference();
		//! Funcion para obtener el RTV.
		void* GetRenderTargetView();
		

	};
}
