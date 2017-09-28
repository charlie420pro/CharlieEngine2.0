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

#include "ceInputLayout.h"
#include "ceConstantBuffer.h"
#include "ceShaderResourceView.h"
#include "ceSampler.h"

#include "ceLight.h"

#include "ceTexture.h"

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
		 *	@brief Input Layout.
		 */
		ceInputLayout* m_pInputLayout;

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
		 *	@brief Variable para el uso de luz diffusa.
		 */
		ceLight m_Diffuse;


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
		 */
		void CreateSwapChain(uint32 uiScreenHandle, int32 iWidth, int32 iHeight);
		
		/**
		 *	@brief Funcion para Crear el Render Target View.
		 */
		void CreateRenderTargetView();

		/**
		 *	@brief Funcion para crear el depth stencil view.
		 */
		void CreateDepthStencilView();
		
		/**
		 *	@brief Funcion para crear el Shader de Vertices.
		 */
		void CreateVertexShader();

		/** 
		 *	@brief Funcion para crear el Shader de Pixeles.
		 */
		void CreatePixelShader();
		
		/** 
		 *	@brief Funcion para crear el InputLayout.
		 */
		void CreateInputLayout();
	
		/**
		 *	@brief Funcion para crear los Buffers Constantes.
		 */
		void CreateConstantBuffers();

		/**
		 *	@brief Funcion para crear buffers constantes de luces.
		 *	@param uint32 uiSize: Tamaño del buffer.
		 */
		void CreateConstantBuffersLight(uint32 uiSize);

		/** 
		 *	@brief Funcion para crear el Sampler.
		 */
		void CreateSample();

		/**
		 *	@brief Funcion para crear luces.
		 */
		void CreateLight();

		///************************************************************************/
		///*					Funciones de Seteo					         	  */
		///************************************************************************/

		/** 
		 *	@brief Funcion para setear la topologia.
		 */
		void SetPrimitiveTopology();
		
		/** 
		 *	@brief Funcion para setear los Render Targets.
		 */
		void SetRenderTargets();

		/** 
		 *	@brief Funcion para setear el ViewPort.
		 */
		void SetViewPort();

		/** 
		 *	@brief Funcion para setear el InputLayout.
		 */
		void SetInputLayout();

		/**
		 *	@brief Funcion para setear los shaders.
		 */
		void SetShaders();

		/**
		 *	@brief Funcion para setear los buffers constantes.
		 *	@param ceMatrix_4X4 matProjectionCamera: Matriz de projeccion de la camara.
		 *	@param ceMatrix_4X4 matViewCamera: Matriz de vista de la camara.
		 */
		void SetConstantBuffers(ceMatrix_4X4* matProjectionCamera, ceMatrix_4X4* matViewCamera);

		/**
		 *	@brief Funcion para setear los samplers.
		 */
		void SetSamplers();
	

		///************************************************************************/
		///*							 Funciones de Ayuda						  */
		///************************************************************************/

		/**
		 *	@brief Funcion para cargar un shader desde un archivo.
		 *	@param const char* szFileName: Ruta del archivo.
		 *	@param const String szEntryPoint: Nombre de entrada del shader.
		 *	@param const String szShaderModel: Modelo de shader.
		 *	@param ceBlob* pBlobOut: Blob de salida.
		 */
		void CompileShaderFromFile(const char* szFileName,
			const String szEntryPoint, const String szShaderModel, ceBlob* pBlobOut);

		
	};
}