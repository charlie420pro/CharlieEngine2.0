#pragma once
#include "ceAplication.h"


namespace ceEngineSDK
{
	//! Clase de mycustomapp hereda de aplicacion.
	class CE_CORE_EXPORT ceMyCustomApp : public ceAplication
	{
		//! Constructor default.
		ceMyCustomApp();
		//! Destructor default de la clase.
		virtual~ceMyCustomApp();

		/************************************************************************/
		/*						Funciones Virtuales								*/
		/************************************************************************/

		//! Funcion para pre inicializar.
		void OnPreInitialize() override;
		//! Funcion para el momento de inicializar.
		void OnInitialize() override;
		//! Funcion para utilizar despues de la inicializacion.
		void OnPosInitialize() override;
		//! Funcion para pre destruir.
		void OnPreDestroy() override;
		//! Funcion para utiliar antes de destruir.
		void OnDestroy() override;
		//! Funcion para actualizar.
		void UpDate(float fDelta) override;
		//! Funcion para renderear.
		void Render() override;
		//! Funcion para cambiar el tamaño.
		void OnSize() override;
	
	};

}