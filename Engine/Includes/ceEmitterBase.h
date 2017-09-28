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
		 *	@param float fStartEmition: Tiempo de inicio de la emisi�n.
		 *	@param float fEndEmition: Tiempo de fin de la emisi�n.
		 *	@param float fStartVelocity: Velocidad inicial de la emisi�n.
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
		 *	@brief Vector para la posici�n en el mundo.
		 */
		ceVector4D m_Position;

		/**
		 *	@brief Vector para la direcci�n en el mundo.
		 */
		ceVector4D m_Direction;

		/**
		 *	@brief Variable para definir el n�mero m�ximo de particulas.
		 */
		int32 m_iNumMaxParticles;

		/**
		 *	@brief Variable para contar cuantas particulas tiene el emisor.
		 */
		int32 m_iParticleCount;

		/**
		 *	@brief Variable para definir el tiempo de inicio de la emisi�n.
		 */
		float m_fStartEmition;

		/**
		 *	@brief Variable para definir el tiempo de fin de la emisi�n.
		 */
		float m_fEndEmition;

		/**
		 *	@brief Variable para definir la velocidad inicial de emisi�n.
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
		 *	@brief Funci�n para inicializar el emisor.
		 */
		virtual void Init();

		/**
		 *	@brief Funci�n para destruir los recursos de la clase.
		 */
		virtual void Destroy();

		/**
		 *	@brief Funci�n para actualizar el emisor.
		 *	@param float fTime: Tiempo de actualizaci�n.
		 */
		virtual void Update(float fTime);

		/**
		 *	@brief Funci�n para crear una particula.
		 */
		virtual void CreateParticle();

		/**
		 *	@brief Funci�n para crear una particula.
		 *	@param ceVector4D Position: Posici�n de la particula.
		 *	@param ceVector4D Direction: Direcci�n de la particula.
		 *	@param float fLifeTime: Tiempo de vida de la particula.
		 *	@param float fVelocity: Velocidad de la particula.
		 */
		virtual void CreateParticle(ceVector4D Position, ceVector4D Direction, float fLifeTime, float fVelocity);

		 ///************************************************************************/
		 ///*							Seteadores.								  */
		 ///************************************************************************/

	protected:

		/**
		 *	@brief Funci�n para setear la posici�n.
		 *	@param ceVector4D Position: Posici�n del emisor en el mundo.
		 */
		virtual void SetPosition(ceVector4D Position) { m_Position = Position; };

		/**
		 *	@brief Funci�n para setear la direcci�n de emisi�n.
		 *	@param ceVector4D Direction: Direcci�n del emisor en el mundo.
		 */
		virtual void SetDirection(ceVector4D Direction) { m_Direction = Direction; };

		/**
		 *	@brief Funci�n para setear el n�mero m�ximo de particulas.
		 *	@param int32 iMaxParticles: N�mero m�ximo de particulas del emisor.
		 */
		virtual void SetMaxParticles(int32 iMaxParticles) { m_iNumMaxParticles = iMaxParticles; };

		/**
		 *	@brief Funci�n para setear el tiempo de inicio de la emisi�n de particulas.
		 *	@param float fStartEmition: Tiempo de inicio de la emisi�n.
		 */
		virtual void SetStartEmition(float fStartEmition) { m_fStartEmition = fStartEmition; };

		/**
		 *	@brief Funci�n para setear el tiempo de finalizaci�n de la emisi�n de particulas.
		 *	@param float fEndEmition: Tiempo de finalizaci�n de la emisi�n.
		 */
		virtual void SetEndEmition(float fEndEmition) { m_fEndEmition = fEndEmition; };

		/**
		 *	@brief Funci�n para setear la velocidad inicial de la emisi�n de particulas.
		 *	@param float fStartVelocity: Velocidad inicial de la particula.
		 */
		virtual void SetStartVelocity(float fStartVelocity) { m_fStartVelocity = fStartVelocity; };

		///************************************************************************/
		///*							Accesores.								  */
		///************************************************************************/

	public:

		/**
		 *	@brief Funci�n para obtener la posici�n del emisor.
		 *	@return la posici�n del emisor en el mundo.
		 */
		virtual ceVector4D GetPosition() { return m_Position; };

		/**
		 *	@brief Funci�n para obtener la direcci�n del emisor.
		 *	@return la direcci�n del emisor en el mundo.
		 */
		virtual ceVector4D GetDirection() { return m_Direction; };

		/**
		 *	@brief Funci�n para obtener el n�mero m�ximo de particulas.
		 *	@return N�mero m�ximo de particulas.
		 */
		virtual int32 GetMaxParticles() { return m_iNumMaxParticles; };

		/**
		 *	@brief Funci�n para obtener el tiempo de inicio de la emisi�n de particulas.
		 *	@return Tiempo de inicio de la emisi�n de particulas.
		 */
		virtual float GetStartEmition() { return m_fStartEmition; };

		/**
		 *	@brief Funci�n para obtener el tiempo de finalizaci�n de la emisi�n de particulas.
		 *	@return Tiempo de finalizaci�n de la emisi�n de particulas.
		 */
		virtual float GetEndEmition() { return m_fEndEmition; };

		/**
		 *	@brief Funci�n para obtener la velocidad inicial de la emisi�n de particulas.
		 *	@return Velocidad inicial de la emisi�n de particulas.
		 */
		virtual float GetStartVelocity() { return m_fStartVelocity; };

	};
}