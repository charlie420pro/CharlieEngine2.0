#pragma once
#include "cePrerequisitesEngine.h"
#include <ceTexture.h>

namespace ceEngineSDK
{
	class CE_ENGINE_EXPORT ceMaterial
	{
	public:
		///************************************************************************/
		///*                       Constructor y Destructor						  */
		///************************************************************************/

		/** 
		 *	@brief Constructor default.
		 */
		ceMaterial();

		/** 
		 *	@brief Destructor default.
		 */
		~ceMaterial();

		/**
		 *	@brief Funcion para cargar la textura del material.
		 *	@param String sTextureFileName: Ruta del archivo de textura.
		 *	@param ceDevice* pDevice: Device.
		 */
		void LoadTexture(String sTextureFileName, ceDevice* pDevice);

		///************************************************************************/
		///*                      Variables miembro de clase.					  */
		///************************************************************************/

		/**
		 *	@brief Lista de texturas del material.
		 */
		ceTexture* m_pTexture;
	};
}