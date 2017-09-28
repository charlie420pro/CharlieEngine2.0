#pragma once
#include "cePrerequisitesGraphics.h"
#include "ceDevice.h"
#include "ceBlob.h"

namespace ceEngineSDK
{
	///************************************************************************/
	///*   Declaracion por delante de las estructuras definidas en DXHeaders  */
	///************************************************************************/
	struct VertexShader;

	//! Clase de shader de vertices.
	class CE_GRAPHICS_EXPORT ceVertexShader
	{
		///************************************************************************/
		///*                     Friends de Clase.								  */
		///************************************************************************/

	private:
		friend class ceGraphicsAPI;

		///************************************************************************/
		///*                   Constructor y Destructor default					  */
		///************************************************************************/

	public:

		/**
		 *	@brief Constructor default.
		 */
		ceVertexShader();

		/**
		 *	@brief Destructor default.
		 */
		~ceVertexShader();

		///************************************************************************/
		///*                      Variables miembro de clase.					  */
		///************************************************************************/

		//! Puntero al shader de vertices.
		VertexShader* m_pVertexShader;

		///************************************************************************/
		///*                      Funciones de clase.							  */
		///************************************************************************/

		/** 
		 *	@brief Funcion para liberar memoria del VertexShader.
		 */
		void Destroy();

		/**
		 *	@brief Funcion para crear el shader de pixeles.
		 *	@param ceDevice* pDevice: Device para crear el shader.
		 *	@param ceBlob* pBlob: blob.
		 */
		void CreateVertexShader(ceDevice* pDevice, ceBlob* pBlob);
	};
}
