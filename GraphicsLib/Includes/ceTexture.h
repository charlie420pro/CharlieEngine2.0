#pragma once
#include "cePrerequisitesGraphics.h"
#include "ceDevice.h"
#include "ceDeviceContext.h"
#include <ceString.h>

namespace ceEngineSDK
{
	///************************************************************************/
	///*   Declaracion por delante de las estructuras definidas en el CPP	  */
	///************************************************************************/
	struct Texture;

	/**
	 *	@brief Clase de textura.
	 */
	class CE_GRAPHICS_EXPORT ceTexture
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
		ceTexture();

		/** 
		 *	@brief Destructor default.
		 */
		~ceTexture();
		
		///************************************************************************/
		///*                      Variables miembro de clase.					  */
		///************************************************************************/

		/**
		 *	@brief Puntero a la textura.
		 */
		Texture* m_pTexture;

		/** 
		 *	@brief Variable para el ancho de la textura.
		 */
		int32 m_iWidth;

		/** 
		 *	@brief Variable para el alto de la textura.
		 */
		int32 m_iHeight;

		/**
		 *	@brief Varieble para saber cuantos bits por pixel tiene la textura.
		 */
		int32 m_iBitsPerPixel;

		/**
		 *	@brief Puntero para almacenar la informacion.
		 */
		void* m_pData;


		///************************************************************************/
		///*                      Funciones de clase.							  */
		///************************************************************************/

		/**
		 *	@brief Funcion para destruir.
		 */
		void Destroy();

		/**
		 *	@brief Funcion para setear la textura.
		 *	@param void* pbackBuffer.
		 */
		void SetTexture(void* pTexture);

		///************************************************************************/
		///*							Funciones de Ayuda.						  */
		///************************************************************************/

		/**
		 *	@brief Funcion para cargar una textura desde un archivo.
		 *	@param String sFileName: Nombre de la textura.
		 *	@param ceDevice* pDevice: El device.
		 */
		void LoadTextureFromFile(String sFileName, ceDevice* pDevice);
	};
}

