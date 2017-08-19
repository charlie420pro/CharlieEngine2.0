#pragma once
#include "cePrerequisitesInput.h"

namespace ceEngineSDK
{
	///************************************************************************/
	///*         Declaracion por delante de estructuras en el cpp			  */
	///************************************************************************/
	struct ceInputKeyBoard;
	/**
	*	@brief Clase para el uso de los distintos inputs del teclado.
	*/
	class CE_INPUT_EXPORT ceKeyBoard
	{
	public:
		///************************************************************************/
		///*                        Constructor y Destructor					  */
		///************************************************************************/

		/**
		*	@brief Constructor default.
		*/
		ceKeyBoard();

		/**
		*	@brief Destructor default.
		*/
		~ceKeyBoard();

		///************************************************************************/
		///*        Variables Miembro de la Clase								  */
		///************************************************************************/

		/**
		 *	@brief Variable para el uso del teclado.
		 */
		ceInputKeyBoard* m_pKeyBoard;


		bool m_bKeys[NUM_KEYS];
		bool m_bPrevKeys[NUM_KEYS];

		///************************************************************************/
		///*                     Funciones Miembro de Clase						  */
		///************************************************************************/

		/**
		 *	@brief Funcion para inicializar.
		 *	@param void* pInterface: Interface de inputs.
		 *	@param void* pScreenHandle: Handle a la ventana.
		 *	@return verdadero si se creo exitosamente falso en caso contrario.
		 */
		bool Init(void* pInterface, void* pScreenHandle);

		/**
		 *	@brief Funcion para actualizar.
		 */
		void Update();

		/**
		 *	@brief Funcion para liberar memoria.
		 */
		void Destroy();

		/**
		 *	@brief Funcion para leer el teclado.
		 *	@return verdadero si hubo una entrada, falso en caso contrario.
		 */
		bool ReadKeyBoard();

		///************************************************************************/
		///*                     Funciones de Ayuda.							  */
		///************************************************************************/

		/**
		 *	@brief Funcion para retornar el input del teclado por referencia.
		 *	@return input del teclado interpretado como void**.
		 */
		void** GetKeyBoardReference();

		/**
		 *	@brief Funcion para retornar el input del teclado.
		 *	@return input del teclado interpretado como void*.
		 */
		void* GetKeyBoard();

		/**
		 *	@brief Funcion para leer si una tecla se presiono.
		 *	@param uint32 uiInput: Tecla presionada.
		 *	@return verdadero si se presiono la tecla falso en caso contrario.
		 */
		bool IsKeyDown(uint32 uiInput);

		/**
		 *	@brief Funcion para leer si una tecla se solto.
		 *	@param uint32 uiInput: Tecla presionada.
		 *	@return verdadero si se solto la tecla falso en caso contrario.
		 */
		bool IsKeyUp(uint32 uiInput);
	};
}