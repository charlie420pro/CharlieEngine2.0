#pragma once

#include "cePrerequisitesInput.h"
#include "ceMouse.h"
#include "ceKeyBoard.h"
#include "ceJoyStick.h"

namespace ceEngineSDK
{
	///************************************************************************/
	///*   Declaracion por delante de las estructuras definidas en el CPP.	  */
	///************************************************************************/

	struct ceInputInterface;
	/**
	*	@brief Clase para el uso de los distintos inputs.
	*/
	class CE_INPUT_EXPORT ceInterface
	{
	public:
		///************************************************************************/
		///*                        Constructor y Destructor					  */
		///************************************************************************/

		/**
		*	@brief Constructor default.
		*/
		ceInterface();

		/**
		*	@brief Destructor default.
		*/
		~ceInterface();

		///************************************************************************/
		///*                       Variables miembro de Clase					  */
		///************************************************************************/

		/**
		 *	@brief Variable para el uso de inputs.
		 */
		ceInputInterface* m_pInput;

		/**
		 *	@brief Variable para uso del teclado.
		 */
		ceKeyBoard m_KeyBoard;

		/**
		 *	@brief Variable para uso del mouse.
		 */
		ceMouse m_Mouse;

		/**
		 *	@brief Variable para uso de un JoyStick.
		 */
		ceJoyStick m_JoyStick;

		/**
		 *	@brief Variable para almacenar el ancho de la ventana.
		 */
		int32 m_iWidht;

		/**
		 *	@brief Variable para almacenar el alto de la ventana.
		 */
		int32 m_iHeight;

		///************************************************************************/
		///*                       Funciones de la Clase						  */
		///************************************************************************/
		
		/**
		 *	@brief Funcion para inicializar los inputs.
		 *	@param void* phInstance: Instancia.
		 *	@param void* pScreenHandle: Handle a la ventana.
		 *	@param int32 iWidth: Ancho de la ventana.
		 *	@param int32 iHeight: Alto de la ventana.
		 *	@return verdadero si se creo con exito los inputs, falso en caso contrario.
		 */	
		bool Init(void* phInstance, void* pScreenHandle, int32 iWidth, int32 iHeight);

		/**
		 *	@brief Funcion para actualizar.
		 *	@return si se recibio algun input regresa verdadero, caso contrario falso.
		 */
		bool Update();

		/**
		 *	@brief Funcion para liberar memoria.
		 */
		void Destroy();

		///************************************************************************/
		///*                     Funciones de Ayuda.							  */
		///************************************************************************/

		/**
		 *	@brief Funcion para retornar la interface de inputs por referencia.
		 *	@return input del teclado interpretado como void**.
		 */
		void **GetInterfaceReference();
	
		/**
		 *	@brief Funcion para retornar  la interface de inputs.
		 *	@return input del teclado interpretado como void*.
		 */
		void* GetInterface();
	};
}
