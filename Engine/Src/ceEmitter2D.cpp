#include "ceEmitter2D.h"

namespace ceEngineSDK
{

	//! Constructor default.
	ceEmitter2D::ceEmitter2D()
	{
		__super::ceEmitterBase();
	}

	//! Constructor con parametros.
	ceEmitter2D::ceEmitter2D(ceVector4D Position, ceVector4D Direction, int32 iNumStartParticle, float fStartEmition, float fEndEmition, float fStartVelocity)
	{
		__super::ceEmitterBase(Position, Direction, iNumStartParticle, fStartEmition, fEndEmition, fStartVelocity);
	}

	//! Destructor default.
	ceEmitter2D::~ceEmitter2D()
	{
		__super::ceEmitterBase();
	}

}