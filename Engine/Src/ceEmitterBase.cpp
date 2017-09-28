#include "ceEmitterBase.h"

namespace ceEngineSDK
{
	//! Constructor default.
	ceEmitterBase::ceEmitterBase()
	{
		SetPosition(ceVector4D(0, 0, 0, 0));
		SetDirection(ceVector4D(0, 1, 0, 0));
		SetMaxParticles(20);
		SetStartEmition(0.5f);
		SetEndEmition(10.0f);
		SetStartVelocity(0.5f);
		m_iParticleCount = 0;
	}

	//! Constructor con parametros.
	ceEmitterBase::ceEmitterBase(ceVector4D Position, ceVector4D Direction, int32 NumStartParticle, float fStartEmition, float fEndEmition, float fStartVelocity)
	{
		SetPosition(Position);
		SetDirection(Direction);
		SetMaxParticles(NumStartParticle);
		SetStartEmition(fStartEmition);
		SetEndEmition(fEndEmition);
		SetStartVelocity(fStartVelocity);
		m_iParticleCount = 0;
	}

	//! Destructor con parametros.
	ceEmitterBase::~ceEmitterBase()
	{
		Destroy();
	}

	//! Función para inicializar el emisor.
	void ceEmitterBase::Init()
	{

	}

	//! Funcion para eliminar recursos.
	void ceEmitterBase::Destroy()
	{
		if (0 != m_iParticleCount)
		{
			Vector<ceParticle*>::iterator itt;
			for (; m_iParticleCount > 0; --m_iParticleCount)
			{
				itt = m_pParticleVector.begin();
				(*itt)->Destroy();
				m_pParticleVector.erase(itt);
				delete (*itt);
			}
		}
	}

	//! Función para actualizar el emisor.
	void ceEmitterBase::Update(float fTime)
	{
		for (int32 i = 0; i < m_pParticleVector.size(); ++i)
		{
			m_pParticleVector[i]->Update(fTime);
		}
	}

	//! Función para crear una particula.
	void ceEmitterBase::CreateParticle()
	{
		ceParticle* pNewParticle = new ceParticle();
		m_pParticleVector.push_back(pNewParticle);
		m_iParticleCount++;
	}

	//! Funcion para crear una particula.
	void ceEmitterBase::CreateParticle(ceVector4D Position, ceVector4D Direction, float fLifeTime, float fVelocity)
	{
		ceParticle* pNewParticle = new ceParticle(Position, Direction, fLifeTime, fVelocity);
		m_pParticleVector.push_back(pNewParticle);
		m_iParticleCount++;
	}
}