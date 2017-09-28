#pragma once
#include "ceMaterial.h"
#include <ceVertexBuffer.h>
#include <ceIndexBuffer.h>

namespace ceEngineSDK
{

	/** 
	 *	@brief Clase de mesh.
	 */
	class CE_ENGINE_EXPORT ceMesh
	{
		///************************************************************************/
		///*                   Constructor y Destructor de la clase.			  */
		///************************************************************************/

	public:

		/** 
		 *	@brief Constructor default.
		 */
		ceMesh();

		/** 
		 *	@brief Destructor default.
		 */
		~ceMesh();

		///************************************************************************/
		///*              Variables miembro de la Clase.						  */
		///************************************************************************/

		/** 
		 *	@brief Vector de vertices.
		 */
		Vector<ceVertex> m_VertexList;

		/** 
		 *	@brief Vector de Indices.
		 */
		Vector<uint32> m_IndicesList;

		/** 
		 *	@brief Vertex Buffer.
		 */
		ceVertexBuffer* m_pVertexBuffer;

		/** 
		 *	@brief Index Buffer.
		 */
		ceIndexBuffer* m_pIndexBuffer;

		/**
		 *	@brief Material del mesh.
		 */
		ceMaterial* m_pMaterial;

		///************************************************************************/
		///*								Accesores.							  */
		///************************************************************************/

		/**
		 *	@brief Funcion para obtener el numero de vertices del mesh.
		 *	@return numero de vertices del mesh.
		 */
		int32 GetVertexSize() { return m_VertexList.size(); };

		/** 
		 *	@brief Funcion para setear el numero de indices del mesh.
		 *	@return numero de indices del mesh.
		 */
		int32 GetIndexSize(){ return m_IndicesList.size(); };

	};
}