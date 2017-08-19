#include "ceJoyStick.h"
#include <dinput.h>

namespace ceEngineSDK
{
	/**
	 *	@brief Variable para la utilizacion de JoyStick de DirectX.
	 */
	struct ceInputJoyStick
	{
		
		void Destroy() {};
	};

	//! Constructor default.
	ceJoyStick::ceJoyStick()
	{
		m_pJoyStick = nullptr;
	}

	//! Destructor default.
	ceJoyStick::~ceJoyStick()
	{
		Destroy();
	}

	//! Funcion para inicializar.
	void ceJoyStick::Init()
	{
		Destroy();
		m_pJoyStick = new ceInputJoyStick();
	}

	//! Funcion para actualizar.
	void ceJoyStick::Update(float fTime)
	{

	}

	//! Funcion para destruir.
	void ceJoyStick::Destroy()
	{
		if (m_pJoyStick != nullptr)
		{
			m_pJoyStick->Destroy();
			delete m_pJoyStick;
		}
	}
}