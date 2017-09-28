#pragma once
#include "cePrerequisitesGraphics.h"
#include "ceDevice.h"

namespace ceEngineSDK
{
	///************************************************************************/
	///*Declaracion por delante de las estructuras definidas en el DX11Headers*/
	///************************************************************************/
	struct Sampler;

	/**
	 *	@brief Clase para sampler.
	 */
	class CE_GRAPHICS_EXPORT ceSampler
	{

		///************************************************************************/
		///*                     Friends de Clase.								  */
		///************************************************************************/

	private:
		friend class ceGraphicsAPI;

		///************************************************************************/
		///*                       Constructor y Destructor						  */
		///************************************************************************/

	public:

		/** 
		 *	@brief Constructor default.
		 */
		ceSampler();

		/**
		 *	@brief Destructor default.
		 */
		~ceSampler();

		///************************************************************************/
		///*                      Variables miembro de clase.				      */
		///************************************************************************/

		/**
		 *	@brief Puntero a un sampler.
		 */
		Sampler* m_pSampler;

		///************************************************************************/
		///*                      Funciones de clase.							  */
		///************************************************************************/

		/**
		 *	@brief Funcion para liberar memoria del objeto.
		 */
		void Destroy();

		/**
		 *	@brief Funcion para crear el sampler.
		 *	@param ceDevice* pDevice: Device  para crear el sampler.
		 */
		void CreateSampler(ceDevice* pDevice);		
	};

}