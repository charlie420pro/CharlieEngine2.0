#pragma once
#include "cePrerequisitesGraphics.h"

namespace ceEngineSDK
{
	///************************************************************************/
	///*   Declaracion por delante de las estructuras definidas en DXHeaders  */
	///************************************************************************/
	struct Blob;

	/**
	 *	@brief Clase de blob.
	 */
	class CE_GRAPHICS_EXPORT ceBlob
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
		Blob* m_pBlob;

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
		 *	@brief Funcion para obtener el puntero a buffer del blob.
		 *	@return Puntero del bufer visto como void puntero constante.
		 */
		 const void* GetBufferPointer();

		/**
		 *	@brief Funcion para obtener el tamaño del buffer.
		 *	@return el tamaño del buffer.
		 */
		SIZE_T GetBufferSize();

		/**
		 *	@brief Funcion para agregar una referencia.
		 *	@return ref.
		 */
		uint64 AddRef();

	};
}