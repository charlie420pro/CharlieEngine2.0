#pragma once
#include "cePrerequisitesGraphics.h"
#include <ceVector3D.h>
#include <ceVector2D.h>

namespace ceEngineSDK
{
	//! Clase de vertices.
	struct CE_GRAPHICS_EXPORT ceVertex
	{
	public:

		/************************************************************************/
		/*           Variables miembro de la Clase								*/
		/************************************************************************/

		//! Vector 3D para la posicion del vertice.
		ceVector3D m_Position;
		//! Vector 2D para la coordenada de textura.
		ceVector2D m_TexCoord;
		//! Vector 3D para las normales.
		ceVector3D m_Normals;
	
	};
}