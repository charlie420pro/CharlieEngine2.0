#pragma once
#include "cePrerequisitesInput.h"

namespace ceEngineSDK
{
	///************************************************************************/
	///*         Declaracion por delante de estructuras en el cpp			  */
	///************************************************************************/
	struct ceInputJoyStick;

	/**
	*	@brief Clase para el uso de los distintos inputs de un joystick.
	*/
	class CE_INPUT_EXPORT ceJoyStick
	{
	public:
		///************************************************************************/
		///*                        Constructor y Destructor					  */
		///************************************************************************/

		/**
		*	@brief Constructor default.
		*/
		ceJoyStick();

		/**
		*	@brief Destructor default.
		*/
		~ceJoyStick();

		///************************************************************************/
		///*                     Variables Miembro								  */
		///************************************************************************/

		/**
		 *	@brief Variable para la utilizacion de JoyStick.
		 */
		ceInputJoyStick* m_pJoyStick;

		///************************************************************************/
		///*                     Funciones Miembro de Clase						  */
		///************************************************************************/

		/**
		 *	@brief Funcion para inicializar.
		 */
		void Init();

		/**
		 *	@brief Funcion para actualizar.
		 *	@param float fTime: Tiempo de actualizacion.
		 */
		void Update(float fTime);

		/**
		 *	@brief Funcion para liberar memoria.
		 */
		void Destroy();
		
	};
}