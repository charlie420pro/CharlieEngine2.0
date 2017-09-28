#pragma once
#include "ceMesh.h"
#include <ceVertex.h>

namespace ceEngineSDK
{
	/** 
	 *	@brief Clase de modelo.
	 */
	class CE_ENGINE_EXPORT ceModel
	{
		///************************************************************************/
		///*                     Constructor y Destructor						  */
		///************************************************************************/

	public:

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
		Vector<ceMesh*> m_pMeshesVector;

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
		 *	@param ceDevice* pDevice: Device.
		 **/
		void Init(String fileName, ceDevice* pDevice);

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
		 *	@param ceDeviceContext* pDeviceContext:  Device context para mandar el drawindex.
		 **/
		void Render(ceDeviceContext* pDeviceContex);

		/**
		 *	@brief Funcion para crear los buffers de vertices.
		 *	@param ceDevice* pDevice para crear los buffers.
		 **/
		void CreateVertexBuffers(ceDevice* pDevice);

		/**
		 *	@brief Funcion para crear los buffers de indices.
		 *	@param ceDevice* pDevice para crear los indices.
		 **/
		void CreateIndexBuffers(ceDevice* pDevice);

		/**
		 *	@brief Funcion para setear los buffers.
		 *	@param ceDeviceContext* pDeviceContext: Contexto del dispositivo.
		 */
		void SetBuffers(ceDeviceContext* pDeviceContext);

		/**
		 *	@brief Funcion para leer el archivo.
		 *	@param String fileName: Nombre del archivo.
		 *	@param ceDevice* pDevice: Device.
		 **/
		void ImportModel(String fileName, ceDevice* pDevice);

	};

}
