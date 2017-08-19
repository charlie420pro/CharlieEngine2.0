#include "ceMesh.h"



namespace ceEngineSDK
{
	/**
	 *	@brief Constructor default de la clase.
	 **/
	ceMesh::ceMesh()
	{
		m_pVertexBuffer = nullptr;
		m_pIndexBuffer = nullptr;
	}

	/**
	 *	@brief Destructor default de la clase.
	 **/
	ceMesh::~ceMesh()

	{
		m_pVertexBuffer = nullptr;
		m_pIndexBuffer = nullptr;
	}

}