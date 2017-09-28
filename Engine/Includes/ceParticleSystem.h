#pragma once
#include "cePrerequisitesEngine.h"
#include "ceEmitter2D.h"
#include "ceEmitter3D.h"
#include "ceForces.h"

namespace ceEngineSDK
{
	/**
	 *	@brief Clase para crear un sistema de particulas.
	 */
	class CE_ENGINE_EXPORT ceParticleSystem
	{
	public:

		///************************************************************************/
		///*                     Constructor y Destructor.						  */
		///************************************************************************/

		/**
		 *	@brief Constructor default.
		 */
		ceParticleSystem();

		/**
		 *	@brief Constructor con parametros.
		 *	@param int32 iNumEmitters: Numero de emisores en el sistema.
		 */
		ceParticleSystem(int32 iNumEmitters);

		/**
		 *	@brief Destructor default.
		 */
		~ceParticleSystem();

		///************************************************************************/
		///*                 Variables miembro de la clase.						  */
		///************************************************************************/

		/**
		 *	@brief Vector para almacenar los tipos de fuerzas que utilizara el sistema.
		 */
		Vector<ceForces*> m_pForcesVector;

		/**
		 *	@brief Vector para almacenar los emisores que tendra el sistema de particulas.
		 */
		Vector<ceEmitterBase*> m_pEmitterVector;

		/**
		 *	@brief Variable para establecer cuantos emisores tendra el sistema de particulas.
		 */
		int32 m_iNumEmitter;


		///************************************************************************/
		///*                Funciones de la clase.								  */
		///************************************************************************/

		///************************************************************************/
		///*							Seteadores.								  */
		///************************************************************************/

		/**
		 *	@brief Función para setear el número de emisores.
		 *	@param int32 iNumEmitters: Número de emisores de particulas del sistema.
		 */
		 void SetNumEmitters(int32 iNumEmitters) { m_iNumEmitter = iNumEmitters; };
	};
}

