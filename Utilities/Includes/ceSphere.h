#pragma once
#include "ceMath.h"
#include "ceVector3D.h"

/************************************************************************/
/* Inclusion de la clase en el espacio de nombre ceEngineSDK            */
/************************************************************************/
namespace ceEngineSDK
{
	class CE_UTILITY_EXPORT ceSphere
	{
	public:
		/************************************************************************/
		/* Constructor y Destructor                                             */
		/************************************************************************/
		 ceSphere();
		 ~ceSphere();
		 ceSphere(float fRadio) { m_fRadio = fRadio; } //! Constructor con radio inicial.
		 ceSphere(float fRadio, ceVector3D Position) { m_fRadio = fRadio; m_Position = Position; } //! Constructor con radio y posicion inicial.

		/************************************************************************/
		/*Variables miembro														*/
		/************************************************************************/
		float m_fRadio;			//! Radio de la esfera
		ceVector3D m_Position;	//! Posicion 
		
		bool Colicion(const ceSphere& Sph, const ceVector3D& Vec);
		

	};
}

