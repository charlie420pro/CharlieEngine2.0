#pragma once
#include "cePrerequisitesEngine.h"

namespace ceEngineSDK
{
	class CE_ENGINE_EXPORT ceSprite
	{
	public:
		///************************************************************************/
		///*                     Constructor y Destructor.						  */
		///************************************************************************/

		/**
		 *	@brief Constructor default.
		 */
		ceSprite();

		/**
		 *	@brief Destructor default.
		 */
		~ceSprite();

		///************************************************************************/
		///*                 Variables miembro de la clase.						  */
		///************************************************************************/

		///************************************************************************/
		///*                Funciones de la clase.								  */
		///************************************************************************/

		/**
		 *	@brief Funci�n para destruir los recursos de la clase.
		 */
		void Destroy();

	};
}
