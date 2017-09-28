#pragma once
#include "cePrerequisitesEngine.h"
#include "ceEmitterBase.h"

namespace ceEngineSDK
{
	/**
	 *	@brief Clase de emisor de particulas 3D para crear un �rea de emisi�n, hereda de ceEmitterBase.
	 */
	class CE_ENGINE_EXPORT ceEmitter3D : public ceEmitterBase
	{
	public:

		///************************************************************************/
		///*                   Constructor y Destructor de la clase.			  */
		///************************************************************************/
		/**
		 *	@brief Constructor Default.
		 */
		ceEmitter3D();

		/**
		 *	@brief Constructor con parametros.
		 *	@param ceVector4D Position: Posicion en donde se va a inicializar.
		 *	@param ceVector4D Direction: Direccion hacia donde se van a emitir las particulas.
		 *	@param int32 NumStartParticle: Numero de particulas iniciales.
		 *	@param float fStartEmition: Tiempo de inicio de la emisi�n.
		 *	@param float fEndEmition: Tiempo de fin de la emisi�n.
		 *	@param float fStartVelocity: Velocidad inicial de la emisi�n.
		 */
		ceEmitter3D(ceVector4D Position, ceVector4D Direction, int32 NumStartParticle, float fStartEmition, float fEndEmition, float fStartVelocity);

		/**
		 *	@brief Destructor Default.
		 */
		virtual ~ceEmitter3D();

		///************************************************************************/
		///*                     Variables miembro de la clase.					  */
		///************************************************************************/

		/**
		 *	@note Esta variable se usa para definir un �rea en el eje X del emisor.
		 *	@brief Variable para almacenar el ancho del emisor.
		 */
		float m_fWidth;

		/**
		 *	@note Esta variable se usa para definir un �rea en el eje Y del emisor.
		 *	@brief Variable para almacenar el alto del emisor.
		 */
		float m_fHeight;

		/**
		 *	@note Esta variable se usa para definir un �rea en el eje Z del emisor.
		 *	@brief Variable para almacenar la profundidad del emisor.
		 */
		float m_fDepth;
		
	};
}
