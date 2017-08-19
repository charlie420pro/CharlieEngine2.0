#pragma once
#include "cePrerequisitesGraphics.h"
#include "ceBlob.h"

namespace ceEngineSDK
{
	/************************************************************************/
	/*   Declaracion por delante de las estructuras definidas en el CPP		*/
	/************************************************************************/
	struct VertexShader;

	//! Clase de shader de vertices.
	class CE_GRAPHICS_EXPORT ceVertexShader
	{
	public:
		/************************************************************************/
		/*                       Constructor y Destructor						*/
		/************************************************************************/

		//! Constructor default.
		ceVertexShader();
		//! Destructor default.
		~ceVertexShader();

		/************************************************************************/
		/*                      Variables miembro de clase.						*/
		/************************************************************************/

		//! Puntero al shader de vertices.
		VertexShader* m_pVertexShader;

		/************************************************************************/
		/*                      Funciones de clase.								*/
		/************************************************************************/

		//! Funcion para destruir.
		void Destroy();

		//! Funcion para crear el VS.
		void CreateVertexShader(void* pDevice, ceBlob* pBlob);

		/************************************************************************/
		/*							Accesores.									*/
		/************************************************************************/

		//! Funcion para obtener por referencia el shader de vertices.
		void** GetVertexShaderReference();
		//! Funcion para obtener el shader de vertices.
		void* GetVertexShader();
		

	};
}
