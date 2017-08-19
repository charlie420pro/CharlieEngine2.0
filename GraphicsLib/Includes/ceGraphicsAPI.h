#pragma once
#include "cePrerequisitesGraphics.h"

#include "ceDevice.h"
#include "ceDeviceContext.h"
#include "ceSwapChain.h"
#include "ceRenderTargetView.h"
#include "ceDepthStencilView.h"
#include "ceBlob.h"
#include "cePixelShader.h"
#include "ceVertexShader.h"
#include "ceTexture.h"
#include "ceInputLayaout.h"
#include "ceConstantBuffer.h"
#include "ceShaderResourceView.h"
#include "ceSampler.h"
#include "ceModel.h"
#include "ceCamera.h"

#include <cePlatformMath.h>
#include <ceVector2D.h>
#include <ceVector3D.h>
#include <ceVector4D.h>
#include <ceMatrix_4X4.h>

#include <ceString.h>


/**
 * @ namespace para incluir la clase dentro del espacio de nombre ceEngineSDK. 
 **/
namespace ceEngineSDK
{
	
	
	class CE_GRAPHICS_EXPORT ceGraphicsAPI
	{
		struct ceDiffuce
		{
			/**
			*	@brief Posicion de la luz.
			*/
			ceVector3D m_lightPosition;

			/**
			*	@brief Escala.
			*/
			float m_Scale;

			/**
			*	@brief Bias.
			*/
			float m_Bias;

			/**
			*	@brief Intensidad.
			*/
			float m_Intensity;

			/**
			*	@brief Sample radius.
			*/
			float m_SampleRadius;

			/**
			*	@brief Color a pintar.
			*/
			ceVector4D ClearColor;
		};

	public:
		///************************************************************************/
		///*               Constructor y Destructor de la Clase					  */
		///************************************************************************/

		/**
		 *	@brief Constructor Default de la Clase.
		 */
		ceGraphicsAPI();

		/**
		 *	@brief Destructor Default de la Clase.
		 */
		~ceGraphicsAPI();

		///************************************************************************/
		///*                Variables Miembro de Clase							  */
		///************************************************************************/

		/**
		 *	@brief Puntero a un Device.
		 */
		ceDevice* m_pDevice;

		/**
		 *	@brief Puntero a un Device Context.
		 */
		ceDeviceContext* m_pDeviceContext;

		/**
		 *	@brief Puntero al SwapChain.
		 */
		ceSwapChain* m_pSwapChain;

		/**
		 *	@brief Puntero a un objeto de RTV.
		 */
		ceRenderTargetView* m_pRenderTargetView;

		/** 
		 *	@brief Puntero a un objeto de DSV.
		 */
		ceDepthStencilView* m_pDepthStencilView;

		/** 
		 *	@brief Puntero a un PixelShader.
		 */
		cePixelShader* m_pPixelShader;

		/** 
		 *	@brief Puntero a un VertexShader.
		 */
		ceVertexShader* m_pVertexShader;

		/**
		 *	@brief Textura para el DepthStencilView.
		 */
		ceTexture* m_pTextureDSV;

		/**
		 *	@brief Textura para el RenderTargetView.
		 */
		ceTexture* m_pTextureRTV;

		/**
		 *	@brief Modelo.
		 */
		ceModel m_Model;

		/**
		 *	@brief Input Layout.
		 */
		ceInputLayaout* m_pInputLayaout;

		/**
		 *	@brief Shader Resource View.
		 */
		ceShaderResourceView* m_pShaderResourceView;

		/**
		 *	@brief Lista de constant buffers.
		 */
		Vector<ceConstantBuffer*> m_pConstantBuffers;


		/**
		 *	@brief Sampler.
		 */
		ceSampler* m_pSampler;

		/** 
		 *	@brief Blob.
		 */
		ceBlob* m_pBlob;

		/**
		 *	@brief Variable para almacenar el handle a la ventana.
		 */
		uint32 m_uiScreenHandle;

		/**
		 *	@brief Variable para almacenar el hancho de la ventana.
		 */
		int32 m_iWidth;

		/**
		 *	@brief Variable para almacenar el alto de la ventana.
		 */
		int32 m_iHeight;

		/**
		 *	@brief Matriz de Mundo.
		 */
		ceMatrix_4X4 m_World;

		/**
		 *	@brief Camera para vizualizer en la ventana con la matriz de vista y de mundo.
		 */
		ceCamera m_Camera;

		/**
		 *	@brief Vector de modelos.
		 */
		Vector<ceModel> m_ModelList;

		/**
		 *
		 */
		ceDiffuce m_Diffuse;


		///************************************************************************/
		///*						Funcion Miembro de la Clase					  */
		///************************************************************************/

		/** 
		 *	@brief Funcion para inicializar el GraphicsAPI.
		 *	@param uint32 uiScreenHandle: Handle a la ventana.
		 *	@param int32 iWidth: Ancho de la ventana.
		 *	@param int32 iHeight: Alto de la ventana.
		 */
		void Init(uint32 uiScreenHandle, int32 iWidth, int32 iHeight);

		/**
		 *	@brief Funcion para renderear.
		 */
		void Render();

		/**
		 *	@brief Funcion para actualizar.
		 *	@param float fTime: Tiempo de actualizacion.
		 */
		void Update(float fTime);

		/**
		 *	@brief Funcion para destruir.
		 */
		void Destroy();

		///************************************************************************/
		///*								Funciones de Creacion				  */
		///************************************************************************/

		/**
		 *	@brief Funcion para crear el dispositivo.
		 */
		void CreateDevice();

		/**
		 *	@brief Funcion para crear el contexto del dispositivo.
		 */
		void CreateDeviceContext();

		/**
		 *  @brief Funcion para crear el swapchain.
		 *	@param uint32 uiScreenHandle: Handle de la ventana.
		 *	@param int32 iWidth: Ancho de la ventana.
		 *	@param int32 iHeight: Alto de la ventana.
		 *	@param void** ppDevice: Puntero a un Device.
		 *	@param void** ppDeviceContext: Puntero a un DeviceContext.
		 */
		void CreateSwapChain(uint32 uiScreenHandle, int32 iWidth, int32 iHeight, void** ppDevice, void** ppDeviceContext);
		
		/**
		 *	@brief Funcion para Crear el Render Target View.
		 *	@param void* pSwapChain: Puntero al Swapchain.
		 *	@param void* pDevice: Puntero al Device.
		 *	@param ceTexture& pTexture: Textura.
		 */
		void CreateRenderTargetView(void* pSwapChain, void* pDevice, ceTexture& pTexture);

		//! Funcion para crear el DepthStencilView.
		void CreateDepthStencilView(void* pDevice, ceTexture& pTexture);
		
		//! Funcion para crear el Shader de Vertices.
		void CreateVertexShader(void* pDevice);
		//! Funcion para crear el Shader de Pixeles.
		void CreatePixelShader(void* pDevice);
		
		//! Funcion para crear el InputLayout.
		void CreateInputLayout(void* pDevice);
	
		//! Funcion para crear los Buffers Constantes.
		void CreateConstantBuffers(void* pDevice, const int32 iNumBuffers);

		//! Funcion para crear el Sampler.
		void CreateSample(void* pDevice);

		///************************************************************************/
		///*							 Funciones de Seteo						  */
		///************************************************************************/

		//! Funcion para setear la topologia.
		void SetPrimitiveTopology();
		
		//! Funcion para setear los Render Targets.
		void SetRenderTargets();
		//! Funcion para setear el ViewPort.
		void SetViewPort(void* pDeviceContext);
		//! Funcion para setear el InputLayout
		void SetInputLayaout();

		//! Funcion para setear los shaders.
		void SetShaders(void* pDeviceContext, void* pPixelShader, void* pVertexShader);
	

		///************************************************************************/
		///*							 Funciones de Ayuda						  */
		///************************************************************************/

		//! Funcion para cargar un shader desde un archivo.
		void CompileShaderFromFile(const char* szFileName, const String szEntryPoint32, const String szShaderModel, ceBlob* ppBlobOut);

		
	};
}