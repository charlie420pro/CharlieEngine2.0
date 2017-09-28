#pragma once
#include "cePrerequisitesEngine.h"
#include "ceCamera.h"
#include "ceModel.h"

#include <ceInterface.h>

namespace ceEngineSDK
{
	class CE_ENGINE_EXPORT ceScene
	{
	public:
		///************************************************************************/
		///*               Constructor y Destructor de la Clase					  */
		///************************************************************************/

		/**
		 *	@brief Constructor Default de la Clase.
		 */
		ceScene();

		/**
		 *	@brief Destructor Default de la Clase.
		 */
		~ceScene();

		///************************************************************************/
		///*                Variables Miembro de Clase							  */
		///************************************************************************/

	private:

		/**
		 *	@brief Contador para saber cuantas camaras hay en la escena.
		 */
		int32 m_iCameraCount;

		/**
		 *	@brief Contador para saber cuantos modelos hay en la escena.
		 */
		int32 m_iModelCount;

		/**
		 *	@brief Vector de modelos.
		 */
		Vector<ceModel*> m_pModelVector;

		/**
		 *	@brief Variable para la utilizacion de Inputs.
		 */
		ceInterface* m_pInput;

		/**
		 *	@brief Puntero al device context.
		 */
		ceDeviceContext* m_pDeviceContext;

	public:
		/**
		 *	@brief Vector para almacenar las camaras de la escena.
		 */
		Vector<ceCamera*> m_pCameraVector;

		///************************************************************************/
		///*						Funcion Miembro de la Clase					  */
		///************************************************************************/

	public:

		/**
		 *	@brief Funcion para inicializar la escena.
		 */
		void Init();

		/**
		 *	@brief Funcion para actualizar la escena.
		 *	@param float fTime: Tiempo de actualizacion.
		 */
		void Update(float fTime);

		/**
		 *	@brief Funcion para destruir la escena.
		 */
		void Destroy();

		/**
		 *	@brief Funcion para renderear la escena.
		 */
		void Render();

		/**
		 *	@brief Funcion para correr la escena.
		 */
		void Run();

		///************************************************************************/
		///*						Funcion de Ayuda.							  */
		///************************************************************************/

		/**
		 *	@brief Funcion para inicializar el sistema de inputs.
		 *	@param void* phInstance: Puntero a la instancia.
		 *	@param void* pHwnd: Puntero a una ventana.
		 *	@param int32 iWidth: Ancho de la ventana.
		 *	@param int32 iHeight: Alto de la ventana.
		 */
		void InitInputs(void* phInstance, void* pHwnd, int32 iWidth, int32 iHeight);


		/**
		 *	@brief Funcion para crear una camara.
		 *	@param uint32 uiScreenHandle: Handle a la ventana.
		 */
		void CreateCamera(uint32 uiScreenHandle);

		/**
		 *	@brief Funcion para crear un modelo.
		 *	@param String sFileName: Direccion del archivo del modelo.
		 *	@param ceDevice* pDevice: Device.
		 *	@param ceDeviceContext* pDeviceContext: El Contexto del dispositivo.
		 */
		void CreateModel(String sFileName, ceDevice* pDevice, ceDeviceContext* pDeviceContext);

		///************************************************************************/
		///*						Accesores.									  */
		///************************************************************************/
		/**
		 *	@brief Funcion para obtener el input.
		 */
		ceInterface* GetInputInterface() { return m_pInput; }
	};
}

