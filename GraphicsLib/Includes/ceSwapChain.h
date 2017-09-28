#pragma once
#include "ceDevice.h"
#include "ceDeviceContext.h"


namespace ceEngineSDK
{
	///************************************************************************/
	///*   Declaracion por delante de las estructuras definidas en DXHeaders  */
	///************************************************************************/
	struct SwapChain;
	struct FeatureLevel;

	/** 
	 *	@brief Clase de objeto SwapChain.
	 */
	class CE_GRAPHICS_EXPORT ceSwapChain
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
		 *	@brief Constructor default de la clase.
		 */
		ceSwapChain();

		/** 
		 *	@brief Destructor default de la clase.
		 */
		~ceSwapChain();

		///************************************************************************/
		///*                      Variables miembro de clase.					  */
		///************************************************************************/

		/** 
		 *	@brief Puntero a un objeto swapchain.
		 */
		SwapChain* m_pSwapChain;

		/** 
		 *	@brief Feature level
		 */
		FeatureLevel* m_pFeatureLevel;

		///************************************************************************/
		///*                      Funciones de clase.							  */
		///************************************************************************/

		/**
		 *	@brief Funcion para liberar la memoria del objeto.
		 */
		void Destroy();

		/** 
		 *	@brief Funcion para crear el SwapChain.
		 *	@param uint32 uiScreenHandle: Handle a la ventana.
		 *	@param int32 iWidth: Ancho de la ventana.
		 *	@param int32 iHeight: Alto de la ventana.
		 *	@param ceDevice& Device: El device para crear el swapchain.
		 *	@param ceDeviceContext& DeviceContext: El device context para crear el swapchain.
		 */
		void CreateSwapChainAndDevice(uint32 uiScrenHandle, int32 iWidth, int32 iHeight, ceDevice& Device, ceDeviceContext& DeviceContext);
	};
}
