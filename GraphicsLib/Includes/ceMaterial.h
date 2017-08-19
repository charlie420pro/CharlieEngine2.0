#pragma once
#include "cePrerequisitesGraphics.h"
#include "ceTexture.h"

namespace ceEngineSDK
{
	class CE_GRAPHICS_EXPORT ceMaterial
	{
	public:
		///************************************************************************/
		///*                       Constructor y Destructor						  */
		///************************************************************************/

		//! Constructor default.
		ceMaterial();
		//! Destructor default.
		~ceMaterial();

		///************************************************************************/
		///*                      Variables miembro de clase.					  */
		///************************************************************************/

		/**
		 *	@brief Lista de texturas del material.
		 */
		Vector<ceTexture*> m_TextureVector;

		///************************************************************************/
		///*                      Variables miembro de clase.					  */
		///************************************************************************/

		/**
		 *	@brief Funcion para inicializar.
		 */
		void Init();

		/**
		 *	@brief Funcion para destruir.
		 */
		void Destroy();

		/**
		 *	@brief Funcion para Actualizar.
		 */
		void Update(float fTime);


	};
}