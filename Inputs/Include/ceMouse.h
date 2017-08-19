#pragma once
#include "cePrerequisitesInput.h"

namespace ceEngineSDK
{

	///************************************************************************/
	///*        Variables Miembro de la Clase								  */
	///************************************************************************/

	struct ceInputMouse;
	/**
	*	@brief Clase para el uso de los distintos inputs del mouse.
	*/
	class CE_INPUT_EXPORT ceMouse
	{
	public:
		///************************************************************************/
		///*                        Constructor y Destructor					  */
		///************************************************************************/

		/**
		*	@brief Constructor default.
		*/
		ceMouse();

		/**
		*	@brief Destructor default.
		*/
		~ceMouse();


		///************************************************************************/
		///*        Variables Miembro de la Clase								  */
		///************************************************************************/

		/**
		 *	@brief Puntero a un objeto ceInputMouse para uso del mouse.
		 */
		ceInputMouse* m_pMouse;

		/**
		 *	@brief Posicion en X del mouse.
		 */
		int32 m_iPositionX;


		/**
		 *	@brief Posicion en Y del mouse.
		 */
		int32 m_iPositionY;

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
		 *	@brief Funcion para obtener la posicion del mouse.
		 *	@param int32& iX: Posicion en X del mouse.
		 *	@param int32& iY: Posicion en Y del mouse.
		 */
		void GetMousePosition(int32& iX, int32& iY);


		/**
		 *	@brief Funcion para leer el mouse.
		 *	@return verdadero si hubo una entrada, falso en caso contrario.
		 */
		bool ReadMouse();

		/**
		*	@brief Funcion para retornar el input del mouse por referencia.
		*	@return input del mouse interpretado como void**.
		*/
		void** GetMouseReference();

		/**
		*	@brief Funcion para retornar el input del mouse.
		*	@return input del mouse interpretado como void*.
		*/
		void* GetMouse();

	};
}