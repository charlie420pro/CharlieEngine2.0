#include "ceInterface.h"
#include <windows.h>
#include <dinput.h>

namespace ceEngineSDK
{

	/**
	 *	@brief Estructura para la utilizacion de inputs de directX11.
	 */
	struct ceInputInterface
	{
		IDirectInput8* m_DXDirectInput;
		void Destroy() { if (m_DXDirectInput != nullptr)m_DXDirectInput->Release(); };
	};

	//! Constructor default de la clase.
	ceInterface::ceInterface()
	{
		m_pInput = nullptr;
	}

	//! Destructor default de la clase.
	ceInterface::~ceInterface()
	{

	}

	//! Funcion para inicializar los inputs.
	bool ceInterface::Init(void* phInstance, void* pScreenHandle, int32 iWidth, int32 iHeight)
	{
		Destroy();
		m_pInput = new ceInputInterface();
		HRESULT hr;

		m_iWidht = iWidth;
		m_iHeight = iHeight;

		
		/// Inicializamos la interfaz de input de DirectX
		hr = DirectInput8Create(reinterpret_cast<HINSTANCE>(phInstance), DIRECTINPUT_VERSION,
			IID_IDirectInput8, (void**)&m_pInput->m_DXDirectInput, nullptr);

		if (FAILED(hr))
		{
			return false;
		}

		m_KeyBoard.Init(reinterpret_cast<void*>(m_pInput->m_DXDirectInput), pScreenHandle);
		m_Mouse.Init(reinterpret_cast<void*>(m_pInput->m_DXDirectInput), pScreenHandle);
		m_JoyStick.Init();

		return true;
	}

	bool ceInterface::Update()
	{
		
		bool bResult;
		bResult = m_KeyBoard.ReadKeyBoard();
		if (!bResult)
		{
			return false;
		}

		bResult = m_Mouse.ReadMouse();
		if (!bResult)
		{
			return false;
		}

		return true;
		
	}

	void ceInterface::Destroy()
	{
	}

	void** ceInterface::GetInterfaceReference()
	{
		return reinterpret_cast<void**>(&m_pInput->m_DXDirectInput);
	}

	void * ceInterface::GetInterface()
	{
		return reinterpret_cast<void*>(m_pInput->m_DXDirectInput);
	}
}