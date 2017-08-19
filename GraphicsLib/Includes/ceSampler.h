#pragma once
#include "cePrerequisitesGraphics.h"

namespace ceEngineSDK
{
	/************************************************************************/
	/*   Declaracion por delante de las estructuras definidas en el CPP		*/
	/************************************************************************/
	struct Sampler;

	//! Clase para sampler.
	class CE_GRAPHICS_EXPORT ceSampler
	{
	private:
		friend class ceGraphicsAPI;
	public:
		/************************************************************************/
		/*                       Constructor y Destructor						*/
		/************************************************************************/

		//! Constructor default.
		ceSampler();
		//! Destructor default.
		~ceSampler();

		/************************************************************************/
		/*                      Variables miembro de clase.						*/
		/************************************************************************/

		//! Puntero al sampler.
		Sampler* m_pSampler;

		/************************************************************************/
		/*                      Funciones de clase.								*/
		/************************************************************************/

		/**
		 *	@brief Funcion para liberar memoria del objeto.
		 */
		void Destroy();

		//! Funcion para crear el sampler.
		void CreateSampler(void* pDevice);

		/************************************************************************/
		/*							Accesores.									*/
		/************************************************************************/

		//! Funcion para obtener por referencia el sampler.
		void** GetSamplerReference();
		//! Funcion para obtener el sampler.
		void* GetSampler();
		
	};

}