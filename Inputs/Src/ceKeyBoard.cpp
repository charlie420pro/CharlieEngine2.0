#include "ceKeyBoard.h"
#include "windows.h"
#include <dinput.h>

namespace ceEngineSDK
{
	/**
	 *	@brief Estructura para el uso del teclado de directX11.
	 */
	struct ceInputKeyBoard
	{
		IDirectInputDevice8* m_DXKeyBoard;
		void Destroy() { if (m_DXKeyBoard != nullptr)m_DXKeyBoard->Unacquire(); m_DXKeyBoard->Release(); };
	};

	//! Constructor default.
	ceKeyBoard::ceKeyBoard()
	{
		m_pKeyBoard = nullptr;
		memset(m_bKeys, 0, sizeof(bool) * NUM_KEYS);
	}

	//! Destructor default.
	ceKeyBoard::~ceKeyBoard()
	{
		Destroy();
	}

	//! Funcion para inicializar.
	bool ceKeyBoard::Init(void* pInterface,void* pScreenHandle)
	{
		Destroy();
		m_pKeyBoard = new ceInputKeyBoard();

		HRESULT hr;
		/// Inicializamos la interfaz de teclado.
		hr =  reinterpret_cast<IDirectInput8*>(pInterface)->CreateDevice(GUID_SysKeyboard,
			&m_pKeyBoard->m_DXKeyBoard, nullptr);

		if (FAILED(hr))return false;
		
		/// Seteamos el formato para el teclado.
		hr = m_pKeyBoard->m_DXKeyBoard->SetDataFormat(&c_dfDIKeyboard);

		if (FAILED(hr)) return false;

		hr = m_pKeyBoard->m_DXKeyBoard->SetCooperativeLevel(
			reinterpret_cast<HWND>(pScreenHandle),
			DISCL_FOREGROUND | DISCL_EXCLUSIVE);

		if (FAILED(hr)) return false;

		hr = m_pKeyBoard->m_DXKeyBoard->Acquire();

		if (FAILED(hr)) return false;
	}

	//! Funcion para actualizar.
	void ceKeyBoard::Update()
	{
	}

	//! Funcion para destruir.
	void ceKeyBoard::Destroy()
	{
		if (m_pKeyBoard != nullptr)
		{
			m_pKeyBoard->Destroy();
			delete m_pKeyBoard;
		}
	}

	bool ceKeyBoard::ReadKeyBoard()
	{
		memcpy(&m_bPrevKeys, m_bKeys, sizeof(bool) * NUM_KEYS);
		HRESULT hr;
		

		hr = m_pKeyBoard->m_DXKeyBoard->GetDeviceState(sizeof(m_bKeys), (LPVOID)&m_bKeys);
		if (FAILED(hr))
		{
			if ((hr == DIERR_INPUTLOST) || (hr == DIERR_NOTACQUIRED))
			{
				m_pKeyBoard->m_DXKeyBoard->Acquire();
			}
			else
			{
				return false;
			}
		}
		return true;
	}

	bool ceKeyBoard::IsKeyDown(uint32 uiInput)
	{
		return m_bKeys[uiInput];
	}

	bool ceKeyBoard::IsKeyUp(uint32 uiInput)
	{
		return m_bKeys[uiInput] && !m_bPrevKeys[uiInput];
	}

	void ** ceKeyBoard::GetKeyBoardReference()
	{
		return reinterpret_cast<void**>(&m_pKeyBoard->m_DXKeyBoard);
	}

	void * ceKeyBoard::GetKeyBoard()
	{
		return reinterpret_cast<void*>(m_pKeyBoard->m_DXKeyBoard);
	}
}