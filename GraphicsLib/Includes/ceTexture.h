#pragma once
#include "cePrerequisitesGraphics.h"
#include "ceString.h"

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
	protected:
		friend class ceGraphicsAPI;
	public:

		///************************************************************************/
		///*                       Constructor y Destructor						  */
		///************************************************************************/

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

		///************************************************************************/
		///*							Accesores.								  */
		///************************************************************************/

		/**
		 *	@brief Funcion para obtener una referencia a la textura.
		 *	@return referencia a la textura.
		 */
		void** GetTextureReference();

		/**
		 *	@brief Funcion para obtener la textura.
		 *	@return puntero a la textura.
		 */
		void* GetTexture();

		/**
		 *	@brief Funcion para obtener una referencia al shader resource view.
		 *	@return referencia a la textura.
		 */
		void** GetShaderResourceViewReference();

		/**
		 *	@brief Funcion para obtener shader resource view.
		 *	@return puntero a la textura.
		 */
		void* GetShaderResourceView();

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
		 *	@param void* pDevice: El device.
		 *  @param void* pDeviceContext: El device context.
		 */
		void LoadTextureFromFile(String sFileName, void* pDevice, void* pDeviceContext);
	};
}

