#pragma once
#include "ceTexture.h"

namespace ceEngineSDK
{
	///************************************************************************/
	///*   Declaracion por delante de las estructuras definidas en DXHeaders  */
	///************************************************************************/
	struct DepthStencilView;
	
	/**
	 *	@brief Clase para la utilizacion de depthstencilview.
	 */
	class CE_GRAPHICS_EXPORT ceDepthStencilView
	{
		///************************************************************************/
		///*                     Friends de Clase.								  */
		///************************************************************************/

	private:
		friend class ceGraphicsAPI;

		///************************************************************************/
		///*                          Constructor y Destructor.					  */
		///************************************************************************/

	public:

		/**
		 *	@brief Constructor default de la clase.
		 */
		ceDepthStencilView();

		/**
		 *	@brief Destructor default de la clase.
		 */
		~ceDepthStencilView();

		///************************************************************************/
		///*                      Variables miembro de la clase					  */
		///************************************************************************/

		//! Puntero a un DepthStencilView.
		DepthStencilView* m_pDepthStencilView;

		///************************************************************************/
		///*							Funciones de la clase					  */
		///************************************************************************/

		/**
		 *	@brief Funcion para liberar memoria del objeto.
		 */
		void Destroy();

		/**
		 *	@brief Funcion para crear el DepthStencilView.
		 *	@param ceDevice* pDevice: Device para la creacion del DSV.
		 *	@param ceTexture& pTexture: Textura a utilizar.
		 *	@param int32 iWidth: Ancho de la textura.
		 *	@param int32 iHeight: Alto de la textura.
		 */
		void CreateDSV(ceDevice* pDevice, ceTexture& pTexture, int32 iWidth, int32 iHeight);

		
	};
}

