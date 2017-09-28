#pragma once
#include "ceSwapChain.h"
#include "ceTexture.h"

namespace ceEngineSDK
{
	///************************************************************************/
	///*   Declaracion por delante de las estructuras definidas en DXHeaders  */
	///************************************************************************/
	struct RenderTargetView;

	//! Clase de render target view.
	class CE_GRAPHICS_EXPORT ceRenderTargetView
	{
		///************************************************************************/
		///*                     Friends de Clase.								  */
		///************************************************************************/

	private:
		friend class ceGraphicsAPI;

		///************************************************************************/
		///*                   Constructor y Destructor de la clase.			  */
		///************************************************************************/

	public:

		/** 
		 *	@brief Constructor default.
		 */
		ceRenderTargetView();

		/** 
		 *	@brief Destructor default.
		 */
		~ceRenderTargetView();

		///************************************************************************/
		///*                      Variables miembro de clase.					  */
		///************************************************************************/

		/** 
		 *	@brief Puntero al render target view.
		 */
		RenderTargetView* m_pRenderTargetView;

		///************************************************************************/
		///*                      Funciones de clase.							  */
		///************************************************************************/

		/**
		 *	@brief Funcion para liberar memoria del objeto.
		 */
		void Destroy();

		/**
		 *	@brief Funcion para crear el RTV.
		 *	@param ceSwapChain* pSwapChain: Cadena de intercambio.
		 *	@param ceDevice* pDevice: Device para crear el RTV.
		 *	@param ceTexture& pTexture: Textura donde se va a crear.
		 */
		void CreateRTV(ceSwapChain* pSwapChain, ceDevice* pDevice, ceTexture& pTexture);
	};
}
