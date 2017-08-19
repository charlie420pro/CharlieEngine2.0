#pragma once
#include "cePrerequisitesGraphics.h"
#include "ceTexture.h"

namespace ceEngineSDK
{
	/************************************************************************/
	/*   Declaracion por delante de las estructuras definidas en el CPP		*/
	/************************************************************************/
	struct ceDSV;

	//! Clase para la utilizacion de depthstencilview.
	class CE_GRAPHICS_EXPORT ceDepthStencilView
	{
	public:
		//! Constructor default de la clase.
		ceDepthStencilView();
		//! Destructor default de la clase.
		~ceDepthStencilView();

		/************************************************************************/
		/*							Funciones de la clase						*/
		/************************************************************************/

		/**
		 *	@brief Funcion para liberar memoria del objeto.
		 */
		void Destroy();

		//! Funcionpara crear el Depth Stencil View.
		void CreateDSV(void* pDevice, ceTexture& pTexture, int32 iWidth, int32 iHeight);

		/************************************************************************/
		/*								Accesores								*/
		/************************************************************************/

		//! Funcion para obtener Depthstencilview por referencia.
		void** GetDepthStencilViewReference();
		//! Funcion para obtener el Depthstencilview como puntero.
		void* GetDepthStencilView();
		

		/************************************************************************/
		/*                      Variables miembro de la clase					*/
		/************************************************************************/

		//! Puntero a un DepthStencilView.
		ceDSV* m_pDepthStencilView;
	};
}

