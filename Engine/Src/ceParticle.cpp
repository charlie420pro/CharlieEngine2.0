#include "ceParticle.h"

namespace ceEngineSDK
{
	//! Constructor default.
	ceParticle::ceParticle()
	{
		SetPosition(ceVector4D(0,0,0,0));
		SetDirection(ceVector4D(0, 1, 0, 0));
		SetLifeTime(1.0f);
		SetVelocity(1.0f);
		m_bActivate = true;
	}

	ceParticle::ceParticle(ceVector4D Position, ceVector4D Direction, float fLifeTime, float fVelocity)
	{
		SetPosition(Position);
		SetDirection(Direction);
		SetLifeTime(fLifeTime);
		SetVelocity(fVelocity);
		m_bActivate = true;
	}

	//! Destructor default.
	ceParticle::~ceParticle()
	{
		Destroy();
	}

	//! Función para eliminar la particula.
	void ceParticle::Destroy()
	{
		
	}

	//! Función para actualizar la particula.
	void ceParticle::Update(float fTime)
	{
		/// Actualizamos el tiempo de vida de la particula.
		m_fLifeTime -= fTime;
		/// Actualizamos la posición de la particula.
		m_Position += m_Direction * fTime * m_fVelocity;

		/// Si el tiempo de vida es menor o igual a cero entonces destruirmos la particula.
		if (0 >= m_fLifeTime)
		{
			m_bActivate = false;
		}
	}
}
