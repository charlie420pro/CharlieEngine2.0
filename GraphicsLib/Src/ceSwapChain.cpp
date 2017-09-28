#include "ceSwapChain.h"
#include "DX11Headers.h"

namespace ceEngineSDK
{
	//! Constructor default.
	ceSwapChain::ceSwapChain()
	{
		m_pSwapChain = nullptr;
		m_pSwapChain = new SwapChain();
		//! Asignamos memoria a los featurelevels.
		m_pFeatureLevel = new FeatureLevel();
		m_pFeatureLevel->m_DXFeatureLevel = D3D_FEATURE_LEVEL_11_0;
	}

	//! Destructor default.
	ceSwapChain::~ceSwapChain()
	{
		Destroy();
	}

	//! Funcion para liberar memoria del objeto.
	void ceSwapChain::Destroy()
	{
		if (m_pSwapChain != nullptr)
		{
			m_pSwapChain->Destroy();
			delete m_pSwapChain;
			m_pSwapChain = nullptr;
		}

		if (m_pFeatureLevel != nullptr)
		{
			delete m_pFeatureLevel;
			m_pFeatureLevel = nullptr;
		}
	}

	//! Funcion para crear el swapchain, el device y el device context.
	void ceSwapChain::CreateSwapChainAndDevice(uint32 uiScrenHandle, int32 iWidth,
		int32 iHeight, ceDevice& Device, ceDeviceContext& DeviceContext)
	{

		//! Arreglo de featurelevels.
		D3D_FEATURE_LEVEL featureLevels = D3D_FEATURE_LEVEL_11_0;

		//! Creamos el hr a modo de bandera.
		HRESULT hr = S_OK;

		/// Creamos el descriptor del swapchain.
		DXGI_SWAP_CHAIN_DESC sd;
		ZeroMemory(&sd, sizeof(DXGI_SWAP_CHAIN_DESC));
		sd.BufferCount = 1;
		sd.BufferDesc.Width = iWidth;
		sd.BufferDesc.Height = iHeight;
		sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		sd.BufferDesc.RefreshRate.Numerator = 60;
		sd.BufferDesc.RefreshRate.Denominator = 1;
		sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE;
		sd.BufferDesc.Scaling = DXGI_MODE_SCALING_STRETCHED;
		sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT | DXGI_USAGE_UNORDERED_ACCESS;
		sd.OutputWindow = reinterpret_cast<HWND>(uiScrenHandle);
		sd.SampleDesc.Count = 1;
		sd.SampleDesc.Quality = 0;
		sd.Windowed = true;
		sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		sd.Flags = 0;

		uint32 createDeviceFlags = 0;
#ifdef _DEBUG
		createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

		//! Creamos el device y el swapchain.
		hr = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr,
			createDeviceFlags, &featureLevels, 1, D3D11_SDK_VERSION, &sd,
			&m_pSwapChain->m_DXSwapChain, &Device.m_pDevice->m_DXDevice,
			&m_pFeatureLevel->m_DXFeatureLevel,
			&DeviceContext.m_pDeviceContext->m_pDXDeviceContext);

		//! Si fallo
		if (FAILED(hr))
			std::cout << "Fallo al crear SwapChain" << std::endl;
	}

}