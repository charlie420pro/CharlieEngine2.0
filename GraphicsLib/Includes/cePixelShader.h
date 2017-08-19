#pragma once
#include "cePrerequisitesGraphics.h"
#include "ceBlob.h"


namespace ceEngineSDK
{
	/************************************************************************/
	/*   Declaracion por delante de las estructuras definidas en el CPP		*/
	/************************************************************************/
	struct PixelShader;

	//! Clase de shader de pixeles.
	class CE_GRAPHICS_EXPORT cePixelShader
	{
	public:
		/************************************************************************/
		/*                    Constructor y Destructor default.					*/
		/************************************************************************/

		//! Constructor default.
		cePixelShader();
		//! Destructor default.
		~cePixelShader();

		/************************************************************************/
		/*                      Variables miembro de clase.						*/
		/************************************************************************/

		//! Puntero al shader de pixeles.
		PixelShader* m_pPixelShader;

		/************************************************************************/
		/*                      Funciones de clase.								*/
		/************************************************************************/


		//! Funcion para crear el shader de pixeles.
		void CreatePixelShader(void* pDevice, ceBlob* pBlob);

		/************************************************************************/
		/*							Accesores.									*/
		/************************************************************************/

		//! Funcion para obtener por referencia el shader de pixeles.
		void** GetPixelShaderReference();
		//! Funcion para obtener el shader de pixeles.
		void* GetPixelShader();
		
	};
}
