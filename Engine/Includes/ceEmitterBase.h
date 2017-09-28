#pragma once
#include "cePrerequisitesEngine.h"
#include "ceParticle.h"

namespace ceEngineSDK
{

	/**
	 *	@brief Clase de emisor de particulas.
	 */
	class CE_ENGINE_EXPORT ceEmitterBase
	{

		///************************************************************************/
	    ///	                   Constructor y Destructor de la clase.			  */
		///************************************************************************/

	public:

		/**
		 *	@brief Constructor Default.
		 */
		ceEmitterBase();

		/**
		 *	@brief Constructor con parametros.
		 *	@param ceVector4D Position: Posicion en donde se va a inicializar.
		 *	@param ceVector4D Direction: Direccion hacia donde se van a emitir las particulas.
		 *	@param int32 NumStartParticle: Numero de particulas iniciales.
		 *	@param float fStartEmition: Tiempo de inicio de la emisión.
		 *	@param float fEndEmition: Tiempo de fin de la emisión.
		 *	@param float fStartVelocity: Velocidad inicial de la emisión.
		 */
		ceEmitterBase(ceVector4D Position, ceVector4D Direction, int32 NumStartParticle, float fStartEmition, float fEndEmition, float fStartVelocity);

		/**
		 *	@brief Destructor Default.
		 */
		virtual ~ceEmitterBase();

		///************************************************************************/
		///*                     Variables miembro de la clase.					  */
		///************************************************************************/

	protected:

		/**
		 *	@brief Vector para la posición en el mundo.
		 */
		ceVector4D m_Position;

		/**
		 *	@brief Vector para la dirección en el mundo.
		 */
		ceVector4D m_Direction;

		/**
		 *	@brief Variable para definir el número máximo de particulas.
		 */
		int32 m_iNumMaxParticles;

		/**
		 *	@brief Variable para contar cuantas particulas tiene el emisor.
		 */
		int32 m_iParticleCount;

		/**
		 *	@brief Variable para definir el tiempo de inicio de la emisión.
		 */
		float m_fStartEmition;

		/**
		 *	@brief Variable para definir el tiempo de fin de la emisión.
		 */
		float m_fEndEmition;

		/**
		 *	@brief Variable para definir la velocidad inicial de emisión.
		 */
		float m_fStartVelocity;

		/**
		 *	@brief Variable para poner un sprite a la particula.
		 */
		ceSprite* m_pSprite;

		/**
		 *	@brief Variable para poner un modelo a la particula.
		 */
		ceModel* m_pModel;

		/**
		 *	@brief Vector para almacenar las particulas.
		 */
		Vector<ceParticle*> m_pParticleVector;

		///************************************************************************/
		///*							Funciones de Clase.						  */
		///************************************************************************/

	public:

		/**
		 *	@brief Función para inicializar el emisor.
		 */
		virtual void Init();

		/**
		 *	@brief Función para destruir los recursos de la clase.
		 */
		virtual void Destroy();

		/**
		 *	@brief Función para actualizar el emisor.
		 *	@param float fTime: Tiempo de actualización.
		 */
		virtual void Update(float fTime);

		/**
		 *	@brief Función para crear una particula.
		 */
		virtual void CreateParticle();

		/**
		 *	@brief Función para crear una particula.
		 *	@param ceVector4D Position: Posición de la particula.
		 *	@param ceVector4D Direction: Dirección de la particula.
		 *	@param float fLifeTime: Tiempo de vida de la particula.
		 *	@param float fVelocity: Velocidad de la particula.
		 */
		virtual void CreateParticle(ceVector4D Position, ceVector4D Direction, float fLifeTime, float fVelocity);

		 ///************************************************************************/
		 ///*							Seteadores.								  */
		 ///************************************************************************/

	protected:

		/**
		 *	@brief Función para setear la posición.
		 *	@param ceVector4D Position: Posición del emisor en el mundo.
		 */
		virtual void SetPosition(ceVector4D Position) { m_Position = Position; };

		/**
		 *	@brief Función para setear la dirección de emisión.
		 *	@param ceVector4D Direction: Dirección del emisor en el mundo.
		 */
		virtual void SetDirection(ceVector4D Direction) { m_Direction = Direction; };

		/**
		 *	@brief Función para setear el número máximo de particulas.
		 *	@param int32 iMaxParticles: Número máximo de particulas del emisor.
		 */
		virtual void SetMaxParticles(int32 iMaxParticles) { m_iNumMaxParticles = iMaxParticles; };

		/**
		 *	@brief Función para setear el tiempo de inicio de la emisión de particulas.
		 *	@param float fStartEmition: Tiempo de inicio de la emisión.
		 */
		virtual void SetStartEmition(float fStartEmition) { m_fStartEmition = fStartEmition; };

		/**
		 *	@brief Función para setear el tiempo de finalización de la emisión de particulas.
		 *	@param float fEndEmition: Tiempo de finalización de la emisión.
		 */
		virtual void SetEndEmition(float fEndEmition) { m_fEndEmition = fEndEmition; };

		/**
		 *	@brief Función para setear la velocidad inicial de la emisión de particulas.
		 *	@param float fStartVelocity: Velocidad inicial de la particula.
		 */
		virtual void SetStartVelocity(float fStartVelocity) { m_fStartVelocity = fStartVelocity; };

		///************************************************************************/
		///*							Accesores.								  */
		///************************************************************************/

	public:

		/**
		 *	@brief Función para obtener la posición del emisor.
		 *	@return la posición del emisor en el mundo.
		 */
		virtual ceVector4D GetPosition() { return m_Position; };

		/**
		 *	@brief Función para obtener la dirección del emisor.
		 *	@return la dirección del emisor en el mundo.
		 */
		virtual ceVector4D GetDirection() { return m_Direction; };

		/**
		 *	@brief Función para obtener el número máximo de particulas.
		 *	@return Número máximo de particulas.
		 */
		virtual int32 GetMaxParticles() { return m_iNumMaxParticles; };

		/**
		 *	@brief Función para obtener el tiempo de inicio de la emisión de particulas.
		 *	@return Tiempo de inicio de la emisión de particulas.
		 */
		virtual float GetStartEmition() { return m_fStartEmition; };

		/**
		 *	@brief Función para obtener el tiempo de finalización de la emisión de particulas.
		 *	@return Tiempo de finalización de la emisión de particulas.
		 */
		virtual float GetEndEmition() { return m_fEndEmition; };

		/**
		 *	@brief Función para obtener la velocidad inicial de la emisión de particulas.
		 *	@return Velocidad inicial de la emisión de particulas.
		 */
		virtual float GetStartVelocity() { return m_fStartVelocity; };

	};
}