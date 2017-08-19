#pragma once
#include "cePrerequisitesGraphics.h"
#include "ceString.h"
#include "ceMesh.h"


namespace ceEngineSDK
{
	/// Clase de modelo.
	class CE_GRAPHICS_EXPORT ceModel
	{
	public:

		///************************************************************************/
		///*                     Constructor y Destructor						  */
		///************************************************************************/

		/** 
		 *	@brief Constructor default.
		 */
		ceModel();

		/** 
		 *	@brief Destructor default.
		 */
		~ceModel();

		///************************************************************************/
		///*                 Variables miembro de la clase						  */
		///************************************************************************/

		/** 
		 * @brief Vector de meshes del modelo.
		 */
		Vector<ceMesh> m_Meshes;

		/**
		 *	@brief Nombre del modelo
		 */
		String m_sName;


		///************************************************************************/
		///*                Funciones de la clase								  */
		///************************************************************************/

		/**
		 *	@brief Funcion para inicializar el modelo.
		 *	@param String fileName: Nombre del archivo.
		 *	@param void* pDevice: Device.
		 **/
		void Init(String fileName, void* pDevice);

		/**
		 *	@brief Funcion para actualizar.
		 *	@param float fTime tiempo de actualizacion.
		 **/
		void Update(float fTime);

		/**
		 *	@brief Funcion para destruir.
		 **/
		void Destroy();

		/**
		 *	@brief Funcion para renderear el modelo.
		 *	@param void* pDeviceContext para mandar el drawindex.
		 **/
		void Render(void* pDeviceContex);

		/**
		 *	@brief Funcion para crear los buffers de vertices.
		 *	@param void* pDevice para crear los buffers.
		 **/
		void CreateVertexBuffers(void* pDevice);

		/**
		 *	@brief Funcion para crear los buffers de indices.
		 *	@param void* pDevice para crear los indices.
		 **/
		void CreateIndexBuffers(void* pDevice);


		/**
		 *	@brief Funcion para leer el archivo.
		 *	@param String fileName: Nombre del archivo.
		 **/
		void ImportModel(String fileName);

	};

}
