#include "ceScene.h"
#include <dinput.h>
#include <windows.h>

namespace ceEngineSDK
{
	//! Constructor default.
	ceScene::ceScene()
	{
		m_iCameraCount = 0;
		m_iModelCount = 0;
		m_pInput = nullptr;
		m_pDeviceContext = nullptr;
	}

	//! Destructor default.
	ceScene::~ceScene()
	{
	}

	//! Funcion para inicializar la escena.
	void ceScene::Init()
	{

	}

	//! Funcion para actualizar la escena.
	void ceScene::Update(float fDelta)
	{
		for (int32 i = 0; i < m_pCameraVector.size(); ++i)
		{
			/// Actualizar para cada camara
			if (m_pInput->Update())
			{

				if (m_pInput->m_KeyBoard.IsKeyDown(DIK_A) ||
					m_pInput->m_KeyBoard.IsKeyDown(DIK_LEFTARROW))
				{
					ceVector4D Direccion = { -1,0,0,0 };
					Direccion *= fDelta * m_pCameraVector[i]->m_fSpeed;
					m_pCameraVector[i]->MoveCamera(Direccion);
				}
				if (m_pInput->m_KeyBoard.IsKeyDown(DIK_D) ||
					m_pInput->m_KeyBoard.IsKeyDown(DIK_RIGHTARROW))
				{
					ceVector4D Direccion = { 1,0,0,0 };
					Direccion *= fDelta * m_pCameraVector[i]->m_fSpeed;
					m_pCameraVector[i]->MoveCamera(Direccion);
				}

				if (m_pInput->m_KeyBoard.IsKeyDown(DIK_W) ||
					m_pInput->m_KeyBoard.IsKeyDown(DIK_UPARROW))
				{
					ceVector4D Direccion = { 0,1,0,0 };
					Direccion *= fDelta * m_pCameraVector[i]->m_fSpeed;
					m_pCameraVector[i]->MoveCamera(Direccion);
				}

				if (m_pInput->m_KeyBoard.IsKeyDown(DIK_S) ||
					m_pInput->m_KeyBoard.IsKeyDown(DIK_DOWNARROW))
				{
					ceVector4D Direccion = { 0,-1,0,0 };
					Direccion *= fDelta * m_pCameraVector[i]->m_fSpeed;
					m_pCameraVector[i]->MoveCamera(Direccion);
				}
			}
			m_pCameraVector[i]->Update();
		}
	}

	//! Funcion para destruir la escena.
	void ceScene::Destroy()
	{
		if (m_pInput != nullptr)
		{
			m_pInput->Destroy();
			delete m_pInput;
			m_pInput = nullptr;
		}

		if (m_iCameraCount != 0)
		{
			Vector<ceCamera*>::iterator itt;
			for (; m_iCameraCount > 0; --m_iCameraCount)
			{
				itt = m_pCameraVector.begin();
				(*itt)->Destroy();
				m_pCameraVector.erase(itt);
			}
		}

		if (m_iModelCount != 0)
		{
			Vector<ceModel*>::iterator itt;
			for (; m_iModelCount > 0; --m_iModelCount)
			{
				itt = m_pModelVector.begin();
				(*itt)->Destroy();
				m_pModelVector.erase(itt);
			}
		}

		if (m_pDeviceContext != nullptr)
		{
			m_pDeviceContext = nullptr;
		}
	}

	//! Funcion para renderear la escena.
	void ceScene::Render()
	{
		for (int32 i = 0; i < m_pModelVector.size(); ++i)
		{
			m_pModelVector[i]->Render(m_pDeviceContext);
		}
	}

	//! Funcion para inicializar el sistema de inputs.
	void ceScene::InitInputs(void* phInstance, void* pHwnd, int32 iWidth, int32 iHeight)
	{
		/// Inicializamos los inputs.
		m_pInput = new ceInterface();
		m_pInput->Init(reinterpret_cast<void*>(phInstance),
			reinterpret_cast<void*>(pHwnd), iWidth, iHeight);
		m_pInput->Update();
	}

	//! Funcion para crear una camara.
	void ceScene::CreateCamera(uint32 uiScreenHandle)
	{
		RECT rc;
		GetClientRect(reinterpret_cast<HWND>(uiScreenHandle), &rc);//! Guardamos las dimensiones de la ventana en el RECT
		uint32 width = rc.right - rc.left;
		uint32 height = rc.bottom - rc.top;


		ceVector4D EyePosition(5.0f, 3.0f, -10.0f, 0.0f);
		ceVector4D At(0.0f, 3.0f, 0.0f, 0.0f);
		ceVector4D Up(0.0f, 1.0f, 0.0f, 0.0f);

		ceCamera* pNewCamera = new ceCamera();
		pNewCamera->m_fAspectRatio = (float)width / (float)height;
		pNewCamera->Init(EyePosition, At, Up);
		m_pCameraVector.push_back(pNewCamera);
		m_iCameraCount++;
	}

	//! Funcion para crear un modelo.
	void ceScene::CreateModel(String sFileName, ceDevice* pDevice, ceDeviceContext* pDeviceContext)
	{
		m_pDeviceContext = pDeviceContext;
		ceModel* pNewModel = new ceModel();
		pNewModel->Init(sFileName, pDevice);
		pNewModel->SetBuffers(pDeviceContext);
		m_pModelVector.push_back(pNewModel);
		m_iModelCount++;
	}
}
