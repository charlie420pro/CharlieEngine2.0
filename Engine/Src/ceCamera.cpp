#include "ceCamera.h"

#define Z_FAR 10000.0f
#define Z_NEAR 1.0f


namespace ceEngineSDK
{
	//! Constructor default.
	ceCamera::ceCamera()
	{
		m_fFOV = ceMath::PI_HALF / 2;
		m_fSpeed = 5.0f;
	}

	//! Destructor default.
	ceCamera::~ceCamera()
	{
	}

	//! Funcion para crear la camara.
	void ceCamera::Init(ceVector4D vPosition, ceVector4D vTarget, ceVector4D Up)
	{
		SetPosition(vPosition);
		SetTarget(vTarget);
		SetUp(Up);

		m_View = ceMatrix_4X4::Zero();
		m_View.LookAtLeftH(m_Position, m_Target, m_Up);

		m_Projection = ceMatrix_4X4::Zero();	
		m_Projection.PerspectiveFOVLH(Z_NEAR, Z_FAR, m_fFOV, m_fAspectRatio);
	}

	void ceCamera::Update()
	{
		m_View.LookAtLeftH(m_Position, m_Target, m_Up);
	}

	void ceCamera::Destroy()
	{
	}

	//! La posicion inicial de la camara en el mundo.
	void ceCamera::SetPosition(ceVector4D vPosition)
	{
		m_Position = vPosition;
	}

	//! Funcion para setear el objetivo de la camara.
	void ceCamera::SetTarget(ceVector4D vTarget)
	{
		m_Target = vTarget;
	}

	void ceCamera::SetUp(ceVector4D Up)
	{
		m_Up = Up;
	}

	//! Funcion para rotar la camara en el eje X.
	void ceCamera::Pitch(float fValueX)
	{
		ceVector4D TempPosition = m_Position;
		m_Position -= m_Position;
		m_View = ceMatrix_4X4::RotateX(fValueX);
	}

	//! Funcion para rotar la camara en el eje Y.
	void ceCamera::Yaw(float fValueY)
	{
		ceVector4D TempPosition = m_Position;
		m_Position -= m_Position;
		m_View = ceMatrix_4X4::RotateY(fValueY);
	}

	//! Funcion para rotar la camara en el eje Z.
	void ceCamera::Roll(float fValueZ)
	{
		m_View = ceMatrix_4X4::RotateZ(fValueZ);
	}

	//! Funcion para mover el objetivo de la camara.
	void ceCamera::LookAt(ceVector4D vPosition)
	{

	}

	//! Funcion para mover la camara.
	void ceCamera::MoveCamera(ceVector4D vPosition)
	{
		m_Position += vPosition;
		
	}

	//! Funcion para panear.
	void ceCamera::Paneo(ceVector4D vDireccion)
	{
	}

	//! Funcion para Rotar el objetivo.
	void ceCamera::Rotate(ceVector4D vAxis)
	{
	}

	//! Funcion para rotar la camara alrededor del objetivo.
	void ceCamera::Orbitate(ceVector4D vAxis)
	{
	}

}