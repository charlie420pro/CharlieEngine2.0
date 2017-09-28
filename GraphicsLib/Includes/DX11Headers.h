#pragma once

#include <d3d11.h>
#include <dxgi.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	/**
	 *	@brief Estrucura para el uso de un device.
	 */
	struct Device
	{
		/**
		 *	@brief Device de DirectX11.
		 */
		ID3D11Device* m_DXDevice;

		/**
		 *	@brief Funcion para liberar la memoria del Device.
		 */
		void Destroy() 
		{ 
			if(m_DXDevice != nullptr)
			m_DXDevice->Release();
		}
	};

	/**
	 *	@brief Estructura para el uso de un devicecontext.
	 */
	struct DeviceContext
	{
		/**
		 *	@brief DeviceContext de DirectX11.
		 */
		ID3D11DeviceContext* m_pDXDeviceContext;

		/**
		 *	@brief Funcion para liberar memoria del DeviceContext.
		 */
		void Destroy() 
		{ 
			if (m_pDXDeviceContext != nullptr)
			m_pDXDeviceContext->Release(); 
		}
	};

	/**
	 *	@brief Estructura para el uso de un InputLayout.
	 */
	struct InputLayout
	{
		/**
		 *	@brief InputLayout de DirectX11.
		 */
		ID3D11InputLayout* m_DXInputLayout;

		/**
		 *	@brief Funcion para liberar memoria del InputLayout.
		 */
		void Destroy()
		{ 
			if(m_DXInputLayout != nullptr)
			m_DXInputLayout->Release();
		}
	};

	/**
	 *	@brief Estructura que contiene un SwapChain.
	 */
	struct SwapChain
	{
		/**
		 *	@brief Puntero a un objeto SwapChain de DirectX.
		 */
		IDXGISwapChain* m_DXSwapChain;

		/**
		 *	@brief Funcion para liberar memoria del objeto.
		 */
		void Destroy()
		{
			if (m_DXSwapChain != nullptr)
				m_DXSwapChain->Release();
		}
	};

	/**
	 *	@brief Estructura para utilizacion de FeaturesLevels.
	 */
	struct FeatureLevel
	{
		/**
		 *	@brief FeatureLevel de DirectX.
		 */
		D3D_FEATURE_LEVEL m_DXFeatureLevel;
	};

	/**
	 *	@brief Estructura para el buffer de DirectX11.
	 */
	struct Buffer
	{
		/**
		 *	@brief Buffer de DirectX11.
		 */
		ID3D11Buffer*  m_pDXBuffer;

		/**
		 *	@brief Funcion para liberar memoria del buffer.
		 */
		void Destroy() { if (m_pDXBuffer != nullptr) m_pDXBuffer->Release(); }
	};


	/**
	 *	@brief Estructura para la utilizacion de texturas de DirectX11.
	 */
	struct Texture
	{
		/**
		 *	@brief Textura de DirectX11.
		 */
		ID3D11Texture2D* m_pDXTexture;

		/**
		 *	@brief Shader Resource View de DirectX11.
		 */
		ID3D11ShaderResourceView* m_pDXShaderResourceView;

		/**
		 *	@brief Funcion para liberar memoria de los objetos de Texture.
		 */
		void Destroy()
		{
			if (m_pDXTexture != nullptr)
				m_pDXTexture->Release();
			if (m_pDXShaderResourceView != nullptr)
				m_pDXShaderResourceView->Release();
		}
	};


	/**
	 *	@brief Estructura para el uso de Sampler de DirectX11.
	 */
	struct Sampler
	{
		/**
		 *	@brief Sampler de DirectX11.
		 */
		ID3D11SamplerState* m_DXSampler;

		/**
		 *	@brief Funcion para liberar memoria del Sampler.
		 */
		void Destroy() 
		{
			if(m_DXSampler != nullptr)
				m_DXSampler->Release();
		}
	};

	/**
	 *	@brief Estructura para utilizacion de Blob.
	 */
	struct Blob
	{
		/**
		 *	@brief Blob de DirectX11.
		 */
		ID3DBlob* m_pDXBlob;

		/**
		 *	@brief Funcion para liberar memoria del Blob.
		 */
		void Destroy() 
		{ 
			if (m_pDXBlob != nullptr) 
				m_pDXBlob->Release();
		}
	};

	/**
	 *	@brief Estructura para la utilizacion de DepthStencilView. 
	 */
	struct DepthStencilView
	{
		/**
		 *	@brief DepthStencilView de DirectX11.
		 */
		ID3D11DepthStencilView* m_DXDepthStencilView;

		/**
		 *	@brief Funcion para liberar memoria del DepthStencilView.
		 */
		void Destroy() 
		{ 
			if(m_DXDepthStencilView != nullptr)
			m_DXDepthStencilView->Release();
		}
	};

	/**
	 *	@brief Estructura para la utilizacion de RenderTargetView.
	 */
	struct RenderTargetView
	{
		/**
		 *	@brief RenderTargetView de DirectX11.
		 */
		ID3D11RenderTargetView* m_DXRenderTargetView;

		/**
		 *	@brief Funcion para liberar memoria del RenderTargetView.
		 */
		void Destroy()
		{
			if (m_DXRenderTargetView != nullptr)
				m_DXRenderTargetView->Release();
		}
	};

	/**
	 *	@brief Estructura para la utilizacion de ShaderResourceView.
	 */
	struct ShaderResourceView
	{
		/**
		 *	@brief ShaderResourceView de DirectX11.
		 */
		ID3D11ShaderResourceView* m_DXShaderResourceView;

		/**
		 *	@brief Funcion para liberar memoria del RenderTargetView.
		 */
		void Destroy()
		{
			if (m_DXShaderResourceView != nullptr)
				m_DXShaderResourceView->Release();
		}
	};

	/**
	 *	@brief Estructura para la utilizacion de PixelShader.
	 */
	struct PixelShader
	{
		/**
		 *	@brief PixelShader de DirectX11.
		 */
		ID3D11PixelShader* m_DXPixelShader;

		/**
		 *	@brief Funcion para liberar memoria del PixelShader.
		 */
		void Destroy()
		{
			if(m_DXPixelShader != nullptr)
			m_DXPixelShader->Release(); 
		}
	};

	/**
	 *	@brief Estructura para la utilizacion de VertexShader.
	 */
	struct VertexShader
	{
		/**
		 *	@brief VertexShader de DirectX11.
		 */
		ID3D11VertexShader* m_DXVertexShader;

		/**
		 *	@brief Funcion para liberar memoria del VertexShader.
		 */
		void Destroy() 
		{
			if (m_DXVertexShader != nullptr)
			m_DXVertexShader->Release();
		}
	};

}
