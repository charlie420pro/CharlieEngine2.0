#pragma once
#include "cePrerequisitesEngine.h"

namespace ceEngineSDK
{
	/**
	 *	@brief Clase para utilizacion de distintas fuerzas.
	 */
	class CE_ENGINE_EXPORT ceForces
	{
	public:

		///************************************************************************/
		///*                     Constructor y Destructor.						  */
		///************************************************************************/

		/**
		 *	@brief Constructor default.
		 */
		ceForces();

		/**
		 *	@brief Destructor default.
		 */
		~ceForces();

		///************************************************************************/
		///*                 Variables miembro de la clase.						  */
		///************************************************************************/

		/**
		 *	@brief Constante que define la fuerza de gravedad.
		 */
		static const float m_fGravity;


		///************************************************************************/
		///*                Funciones de la clase.								  */
		///************************************************************************/
	};
}
