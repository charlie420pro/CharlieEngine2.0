#pragma once

#include "cePrerequisitesGraphics.h"
#include <ceVector4D.h>
#include <ceMatrix_4X4.h>

namespace ceEngineSDK
{
	class CE_GRAPHICS_EXPORT ceCamera
	{
	public:
		///************************************************************************/
		///*                     Constructor y Destructor						  */
		///************************************************************************/

		/**
		 *	@brief Contructor default.
		 */
		ceCamera();

		/**
		 *	@brief Destructor default.
		 */
		~ceCamera();

		///************************************************************************/
		///*                 Variables miembro de la clase						  */
		///************************************************************************/

		/**
		 *	@brief Variable que sirve para saber cual es el aspectratio de la camara.
		 */
		float m_fAspectRatio;

		/**
		 *	@brief Variable para el Field of View de la camara.
		 */
		float m_fFOV;

		/**
		 *	@brief Variable para la velocidad de la camara.
		 */
		float m_fSpeed;

		/**
		 *	@brief Vector que define la posicion de la camara en el mundo.
		 */
		ceVector4D m_Position;

		/**
		 *	@brief Vector que define el objetivo de la camara.
		 */ 
		ceVector4D m_Target;

		/**
		 *	@brief Vector que define hacia donde es arriba para la camara.
		 */
		ceVector4D m_Up;

		/**
		 *	@brief Vector que define hacia donde es enfrente para la camara.
		 */
		ceVector4D m_Front;

		/**
		 *	@brief Vector que define hacia donde es derecha para la camara.
		 */
		ceVector4D m_Right;


		/**
		 *	@brief Matriz de vista de la camara.
		 */
		ceMatrix_4X4 m_View;

		/**
		 *	@brief Matriz de proyeccion de la camara.
		 */
		ceMatrix_4X4 m_Projection;

		///************************************************************************/
		///*                Funciones de la clase								  */
		///************************************************************************/

		/**
		 *	@brief Funcion para crear la camara.
		 *	@param ceVector4D vPosition: Posicion inicial de la camara en el mundo.
		 *	@param ceVector4D vObjetivo: Objetivo de la camara.
		 *	@param ceVector4D Up: Arriba.
		 */
		void Init(ceVector4D vPosition, ceVector4D vObjetivo, ceVector4D Up);

		/**
		 *	@brief Funcion para actualizar.
		 *	@param float fTime: Tiempo de actualizacion.
		 */
		void Update();

		/**
		 *	@brief Funcion para destruir.
		 */
		void Destroy();

		/**
		 *	@brief Funcion para setear la posicion de la camara.
		 *	@param ceVector4D vPosition: La posicion inicial de la camara en el mundo.
		 */
		void SetPosition(ceVector4D vPosition);

		/**
		 *	@brief Funcion para setear el objetivo de la camara.
		 *	@param ceVector4D vTarget: Objetivo de la camara en el mundo.
		 */
		void SetTarget(ceVector4D vTarget);

		/**
		 *	@brief Funcion para setear el up de la camara.
		 *	@param ceVector4D Up: Vector de up de la camara en el mundo.
		 */
		void SetUp(ceVector4D Up);

		/**
		 *	@brief Funcion para rotar la camara en el eje X.
		 *	@param float fValueX: cuanto se va a rotar en el eje X.
		 */
		void Pitch(float fValueX);

		/**
		 *	@brief Funcion para rotar la camara en el eje Y.
		 *	@param float fValueY: cuanto se va a rotar en el eje Y.
		 */
		void Yaw(float fValueY);

		/**
		 *	@brief Funcion para rotar la camara en el eje Z.
		 *	@param float fValueZ: cuanto se va a rotar en el eje Z.
		 */
		void Roll(float fValueZ);

		///************************************************************************/
		///*                Funciones de Ayuda									  */
		///************************************************************************/

		/**
		 *	@brief Funcion para mover el objetivo de la camara.
		 *	@param ceVector4D vPosition: Posicion a donde se va a mover el vTarget.
		 */
		void LookAt(ceVector4D vPosition);

		/**
		 *	@brief Funcion para mover la camara.
		 *	@param ceVector4D vPosition: Posicion a donde se va a mover la camara.
		 */
		void MoveCamera(ceVector4D vPosition);

		/**
		 *	@brief Funcion para panear.
		 *	@param ceVector4D vDireccion: Vector de direccion para panear.
		 */
		void Paneo(ceVector4D vDireccion);

		/**
		 *	@brief Funcion para Rotar el objetivo.
		 *	@param ceVector4D vAxis: Vector que contiene en que eje se va a rotar el objetivo de la camara.
		 */
		void Rotate(ceVector4D vAxis);

		/**
		 *	@brief Funcion para rotar la camara alrededor del objetivo.
		 *	@param ceVector4D vAxis: Vector que contiene en que eje se va a rotar la camara con respecto al objetivo.
		 */
		void Orbitate(ceVector4D vAxis);
	};

}