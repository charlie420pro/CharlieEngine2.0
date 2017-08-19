#pragma once
#include "cePrerequisitesGraphics.h"
#include "ceMaterial.h"
#include "ceVertexBuffer.h"
#include "ceIndexBuffer.h"

namespace ceEngineSDK
{

	//! Clase de mesh.
	class CE_GRAPHICS_EXPORT ceMesh
	{
	public:
		/************************************************************************/
		/*                     Constructor y Destructor							*/
		/************************************************************************/

		//! Constructor default.
		ceMesh();
		//! Destructor default.
		~ceMesh();


		/************************************************************************/
		/*              Variables miembro de la Clase.							*/
		/************************************************************************/

		//! Vector de vertices.
		Vector<ceVertex> m_VertexList;
		//! Vector de Indices.
		Vector<uint32> m_IndicesList;

		//! Vertex Buffer.
		ceVertexBuffer* m_pVertexBuffer;
		//! Index Buffer.
		ceIndexBuffer* m_pIndexBuffer;

		//! Material del mesh.
		ceMaterial m_Material;

		/************************************************************************/
		/*								Accesores.								*/
		/************************************************************************/

		//! Funcion para setear el numero de vertices del mesh.
		int32 GetVertexSize() { return m_VertexList.size(); };
		//! Funcion para setear el numero de indices del mesh.
		int32 GetIndexSize(){ return m_IndicesList.size(); };

	};
}