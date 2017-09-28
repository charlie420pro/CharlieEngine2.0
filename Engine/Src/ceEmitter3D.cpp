#include "ceEmitter3D.h"

namespace ceEngineSDK
{
	//! Constructor default.
	ceEmitter3D::ceEmitter3D()
	{
		__super::ceEmitterBase();
	}

	//! Constructor con parametros.
	ceEmitter3D::ceEmitter3D(ceVector4D Position, ceVector4D Direction, int32 NumStartParticle, float fStartEmition, float fEndEmition, float fStartVelocity)
	{
		__super::ceEmitterBase(Position, Direction, NumStartParticle, fStartEmition, fEndEmition, fStartVelocity);
	}

	//! Destructor default.
	ceEmitter3D::~ceEmitter3D()
	{
		__super::ceEmitterBase();
	}
}
