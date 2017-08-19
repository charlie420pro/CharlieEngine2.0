#pragma once

#include <d3d11.h>
#include <dxgi.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{

	


	/**
	*	@brief Estructura para la utilizacion de texturas de DirectX11.
	*/
	struct Texture
	{
		/// Textura de directx11.
		ID3D11Texture2D* m_pDXTexture;

		/// Shader resource view.
		ID3D11ShaderResourceView* m_pDXShaderResourceView;

		/// Funcion para liberar la textura.
		void Destroy()
		{
			if (m_pDXTexture != nullptr)
				m_pDXTexture->Release();
			if (m_pDXShaderResourceView != nullptr)
				m_pDXShaderResourceView->Release();
		}
	};

	struct Sampler
	{
		ID3D11SamplerState* m_DXSamplerLinear;
		void Destroy() { m_DXSamplerLinear->Release(); }
	};

	/**
	*	@brief Estructura para utilizacion de blob.
	*/
	struct BlobDX
	{
		//! Puntero a un blob de DirectX.
		ID3DBlob* m_pDXBlob;

		//! Funcion para liberar memoria del blob.
		void Destroy() { if (m_pDXBlob != nullptr) m_pDXBlob->Release(); }
	};

}
