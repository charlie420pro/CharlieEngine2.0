#pragma once
#include "ceDevice.h"
#include "ceBlob.h"


namespace ceEngineSDK
{
	///************************************************************************/
	///*   Declaracion por delante de las estructuras definidas en DXHeaders  */
	///************************************************************************/
	struct PixelShader;

	/** 
	 *	@brief Clase para la utilizacion de shaders de pixeles.
	 */
	class CE_GRAPHICS_EXPORT cePixelShader
	{
		///************************************************************************/
		///*                     Friends de Clase.								  */
		///************************************************************************/

	private:
		friend class ceGraphicsAPI;

		///************************************************************************/
		///*                   Constructor y Destructor default					  */
		///************************************************************************/

	public:

		/**
		 *	@brief Constructor default.
		 */
		cePixelShader();

		/**
		 *	@brief Destructor default.
		 */
		~cePixelShader();

		///************************************************************************/
		///*                      Variables miembro de clase.					  */
		///************************************************************************/

		/** 
		 *	@brief Puntero al shader de pixeles.
		 */
		PixelShader* m_pPixelShader;

		///************************************************************************/
		///*                      Funciones de clase.							  */
		///************************************************************************/

		/**
		 *	@brief Funcion para liberar memoria del PixelShader.
		 */
		void Destroy();

		/** 
		 *	@brief Funcion para crear el shader de pixeles.
		 *	@param ceDevice* pDevice: Device para crear el shader.
		 *	@param ceBlob* pBlob: blob.
		 */
		void CreatePixelShader(ceDevice* pDevice, ceBlob* pBlob);
	};
}
