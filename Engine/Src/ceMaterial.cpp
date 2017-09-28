#include "ceMaterial.h"

namespace ceEngineSDK
{
	//! Constructor default.
	ceMaterial::ceMaterial()
	{
		m_pTexture = new ceTexture();
	}

	//! Destructor default.
	ceMaterial::~ceMaterial()
	{
		if (m_pTexture != nullptr)
		{
			m_pTexture->Destroy();
			delete m_pTexture;
			m_pTexture = nullptr;
		}
	}

	//! Funcion para cargar la textura del material.
	void ceMaterial::LoadTexture(String sTextureFileName, ceDevice* pDevice)
	{
		m_pTexture->LoadTextureFromFile(
			sTextureFileName, pDevice);
	}
}