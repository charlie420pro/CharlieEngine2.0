#include "ceMouse.h"
#include "windows.h"
#include <dinput.h>

namespace ceEngineSDK
{
	/**
	 *	@brief Estructura para el uso del mouse de directX11.
	 */
	struct ceInputMouse
	{
		IDirectInputDevice8* m_DXMouse;
		DIMOUSESTATE m_DXMouseState;
		void Destroy() { if (m_DXMouse != nullptr)m_DXMouse->Unacquire(); m_DXMouse->Release(); };
	};

	//! Constructor default.
	ceMouse::ceMouse()
	{
		m_pMouse = nullptr;
		m_iPositionX = 0;
		m_iPositionY = 0;
	}

	ceMouse::~ceMouse()
	{

	}

	//! Funcion para actualizar.
	bool ceMouse::Init(void* pInterface, void* pScreenHandle)
	{
		Destroy();
		m_pMouse = new ceInputMouse();
		HRESULT hr;


		/// Inicializamos la interfaz del mouse.
		hr = reinterpret_cast<IDirectInput8*>(pInterface)->CreateDevice(GUID_SysMouse,
			&m_pMouse->m_DXMouse,
			nullptr);

		if (FAILED(hr)) return false;

		/// Seteamos el formato del mouse.
		hr = m_pMouse->m_DXMouse->SetDataFormat(&c_dfDIMouse);

		if (FAILED(hr)) return false;

		hr = m_pMouse->m_DXMouse->SetCooperativeLevel(
			reinterpret_cast<HWND>(pScreenHandle),
			DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);


		if (FAILED(hr)) return false;

		hr = m_pMouse->m_DXMouse->Acquire();

		if (FAILED(hr)) return false;

		return true;
	}

	//! Funcion para actualizar.
	void ceMouse::Update()
	{

	}

	//! Funcion para destruir.
	void ceMouse::Destroy()
	{
		if (m_pMouse != nullptr)
		{
			m_pMouse->Destroy();
			delete m_pMouse;
		}
		m_iPositionX = 0;
		m_iPositionY = 0;
	}

	void ceMouse::GetMousePosition(int32& iX, int32& iY)
	{
		iX = m_iPositionX;
		iY = m_iPositionY;
	}

	bool ceMouse::ReadMouse()
	{
		/*if (m_pMouse->m_DXMouse == nullptr)
		{
			reinterpret_cast<IDirectInput8*>(InputInterface.GetInterface())->CreateDevice(
				GUID_SysMouse, &m_pMouse->m_DXMouse, nullptr);

			return false;
		}*/

		HRESULT hr;
		hr = m_pMouse->m_DXMouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&m_pMouse->m_DXMouseState);
		if (FAILED(hr))
		{
			if ((hr == DIERR_INPUTLOST) || (hr == DIERR_NOTACQUIRED))
			{
				m_pMouse->m_DXMouse->Acquire();
			}
			else
			{
				return false;
			}
		}
		return true;
	}

	void ** ceMouse::GetMouseReference()
	{
		return reinterpret_cast<void**>(&m_pMouse->m_DXMouse);
	}

	void * ceMouse::GetMouse()
	{
		return reinterpret_cast<void*>(m_pMouse->m_DXMouse);
	}
}