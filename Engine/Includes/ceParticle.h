#pragma once
#include "cePrerequisitesEngine.h"
#include "ceModel.h"
#include "ceSprite.h"
#include <ceVector4D.h>

namespace ceEngineSDK
{
	/**
	 *	@brief Clase para utilización de particulas.
	 */
	class CE_ENGINE_EXPORT ceParticle
	{
	public:

		///************************************************************************/
		///*                     Constructor y Destructor.						  */
		///************************************************************************/

		/**
		 *	@brief Constructor default.
		 */
		ceParticle();

		/**
		 *	@brief Constructor con parametros.
		 *	@param ceVector4D Position: Posición de la particula.
		 *	@param ceVector4D Direction: Dirección de la particula.
		 *	@param float fLifeTime: Tiempo de vida de la particula.
		 *	@param float fVelocity: Velocidad de la particula.
		 */
		ceParticle(ceVector4D Position, ceVector4D Direction, float fLifeTime, float fVelocity);

		/**
		 *	@brief Destructor default.
		 */
		~ceParticle();

		///************************************************************************/
		///*                 Variables miembro de la clase.						  */
		///************************************************************************/

	private:

		/**
		 *	@brief Vector para la posición en el mundo.
		 */
		ceVector4D m_Position;

		/**
		 *	@brief Vector para la dirección en el mundo.
		 */
		ceVector4D m_Direction;

		/**
		 *	@brief Variable para establecer el tiempo de vida de la particula.
		 */
		float m_fLifeTime;

		/**
		 *	@brief Variable para establecer la velocidad de la particula.
		 */
		float m_fVelocity;

		/**
		 *	@brief Variable para saber cuando una particula esta inactiva.
		 */
		bool m_bActivate;


		///************************************************************************/
		///*                Funciones de la clase.								  */
		///************************************************************************/

	public:

		/**
		 *	@brief Función para eliminar la particula.
		 */
		void Destroy();

		/**
		 *	@brief Función para actualizar la particula.
		 *	@param float fTime: Tiempo de actualización.
		 */
		void Update(float fTime);

		///************************************************************************/
		///*							Seteadores.								  */
		///************************************************************************/

		/**
		 *	@brief Función para setear la posición.
		 *	@param ceVector4D Position: Posición de la particula en el mundo.
		 */
		 void SetPosition(ceVector4D Position) { m_Position = Position; };

		/**
		 *	@brief Función para setear la dirección de la particula.
		 *	@param ceVector4D Direction: Dirección de la particula en el mundo.
		 */
		 void SetDirection(ceVector4D Direction) { m_Direction = Direction; };

		/**
		 *	@brief Función para setear el tiempo de vida de la particula.
		 *	@param float fLifeTime: Tiempo de vida de la particula.
		 */
		 void SetLifeTime(float fLifeTime) { m_fLifeTime = fLifeTime; };

		/**
		 *	@brief Función para setear el tiempo de vida de la particula.
		 *	@param float fVelocity: Velocidad inicial de la particula.
		 */
		 void SetVelocity(float fVelocity) { m_fVelocity = fVelocity; };

		///************************************************************************/
		///*							Accesores.								  */
		///************************************************************************/

		/**
		 *	@brief Función para obtener la posición de la particula.
		 *	@return la posición de la particula en el mundo.
		 */
		 ceVector4D GetPosition() { return m_Position; };

		/**
		 *	@brief Función para obtener la dirección de la particula.
		 *	@return la dirección de la particula en el mundo.
		 */
		 ceVector4D GetDirection() { return m_Direction; };

		/**
		 *	@brief Función para obtener el tiempo de vida de la particula.
		 *	@return Tiempo de vida de la particula.
		 */
		 float GetLifeTime() { return m_fLifeTime; };

		/**
		 *	@brief Función para obtener el tiempo de vida de la particula.
		 *	@return Tiempo de vida de la particula.
		 */
		 float GetVelocity() { return m_fVelocity; };
	};
}

