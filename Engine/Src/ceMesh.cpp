#include "ceMesh.h"

namespace ceEngineSDK
{
	//! Constructor default.
	ceMesh::ceMesh()
	{
		m_pVertexBuffer = nullptr;
		m_pIndexBuffer = nullptr;
		m_pMaterial = new ceMaterial();
	}

	//! Destructor default.
	ceMesh::~ceMesh()

	{
		if (m_pVertexBuffer != nullptr)
		{
			m_pVertexBuffer->Destroy();
			delete m_pVertexBuffer;
			m_pVertexBuffer = nullptr;
		}

		if (m_pIndexBuffer != nullptr)
		{
			m_pIndexBuffer->Destroy();
			delete m_pIndexBuffer;
			m_pIndexBuffer = nullptr;
		}

		if (m_pMaterial != nullptr)
		{
			delete m_pMaterial;
			m_pMaterial = nullptr;
		}
	}

}