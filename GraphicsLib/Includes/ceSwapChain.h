#pragma once
#include "cePrerequisitesGraphics.h"


namespace ceEngineSDK
{
	/************************************************************************/
	/*   Declaracion por delante de las estructuras definidas en el CPP		*/
	/************************************************************************/
	struct SwapChain;
	struct FeatureLevel;

	//!Clase de objeto SwapChain.
	class CE_GRAPHICS_EXPORT ceSwapChain
	{

	public:

		/************************************************************************/
		/*                       Constructor y Destructor						*/
		/************************************************************************/

		//! Constructor default de la clase.
		ceSwapChain();
		//! Destructor default de la clase.
		~ceSwapChain();

		/************************************************************************/
		/*                      Variables miembro de clase.						*/
		/************************************************************************/

		//! Puntero a un objeto swapchain.
		SwapChain* m_pSwapChain;
		//! Feature level
		FeatureLevel* m_pFeatureLevel;

		/************************************************************************/
		/*                      Funciones de clase.								*/
		/************************************************************************/

		/**
		 *	@brief Funcion para liberar la memoria del objeto.
		 */
		void Destroy();

		//! Funcion para crear el SwapChain.
		void CreateSwapChainAndDevice(uint32 uiScrenHandle, int32 iWidth, int32 iHeight, void** pDevice, void** pDeviceContext);

		/************************************************************************/
		/*							Accesores.									*/
		/************************************************************************/

		//! Funcion para obtener el SwapChain como referencia.
		void** GetSwapChainReference();
		//! Funcion para obtener el SwapChain.
		void* GetSwapChain();
	};
}
