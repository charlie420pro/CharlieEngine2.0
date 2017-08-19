#pragma once
#include "ceMath.h"
#include "ceVector3D.h"

/************************************************************************/
/* Inclusion de la clase en el espacio de nombre ceEngineSDK            */
/************************************************************************/
namespace ceEngineSDK
{
	class CE_UTILITY_EXPORT ceRay
	{
	public:
		/************************************************************************/
		/* Constructor y Destructor                                             */
		/************************************************************************/
		ceRay();
		~ceRay();
		/************************************************************************/
		/* Variables miembro                                                    */
		/************************************************************************/
		 ceVector3D m_Position;
		 ceVector3D m_Direccion;
		 float m_fDistance;


	};
}

