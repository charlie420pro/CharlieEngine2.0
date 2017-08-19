#pragma once
#include "cePrerequisitesGraphics.h"

namespace ceEngineSDK
{
	///************************************************************************/
	///*   Declaracion por delante de las estructuras definidas en el CPP	  */
	///************************************************************************/
	struct BlobDX;

	/**
	 *	@brief Clase de blob.
	 */
	class CE_GRAPHICS_EXPORT ceBlob
	{
	private:
		friend class ceGraphicsAPI;
	public:

		///************************************************************************/
		///*                   Constructor y Destructor de la clase.			  */
		///************************************************************************/

		/**
		 *	@brief Constructor Default.
		 */
		ceBlob();

		/**
		 *	@brief Destructor Default.
		 */
		~ceBlob();

		///************************************************************************/
		///*                     Variables miembro de la clase.					  */
		///************************************************************************/

		/**
		 *	@brief Puntero al blob.
		 */
		BlobDX* m_pBlob;

		///************************************************************************/
		///*							Funciones de Clase.						  */
		///************************************************************************/

		/**
		 *	@brief Funcion para destruir los recursos de la clase.
		 */
		void Destroy();

		///************************************************************************/
		///*							Accesores.							      */
		///************************************************************************/

		/**
		 *	@brief Funcion para obtener el puntero al blob.
		 *	@return Blob visto como un void puntero.
		 */
		void* GetBlob();

		/**
		 *	@brief Funcion para obtener por referencia el blob.
		 *	@return Blob data visto como un void puntero puntero.
		 */
		void** GetBlobReference();

		/** 
		 *	@brief Funcion para obtener el puntero a buffer del blob.
		 *	@return Puntero del bufer visto como void puntero constante.
		 */
		const void* GetBufferPointer();

		/**
		 *	@brief Funcion para obtener el tamaño del buffer.
		 *	@return el tamaño del buffer.
		 */
		SIZE_T GetBufferSize();

	};
}