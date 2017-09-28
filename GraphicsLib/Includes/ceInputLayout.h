#pragma once
#include "ceDevice.h"
#include "ceBlob.h"

namespace ceEngineSDK
{
	///************************************************************************/
	///*   Declaracion por delante de las estructuras definidas en DXHeaders  */
	///************************************************************************/

	struct InputLayout;

	/**
	 *	@brief Clase inputlayaout.
	 */
	class CE_GRAPHICS_EXPORT ceInputLayout
	{
		///************************************************************************/
		///*                     Friends de Clase.								  */
		///************************************************************************/

	private:
		friend class ceGraphicsAPI;

		///************************************************************************/
		///*                   Constructor y Destructor de la clase.			  */
		///************************************************************************/

	public:

		/** 
		 *	@brief Constructor default.
		 */
		ceInputLayout();

		/** 
		 *	@brief Destructor default.
		 */
		~ceInputLayout();

		///************************************************************************/
		///*                     Variables miembro de la clase.					  */
		///************************************************************************/

		/**
		 *	@brief Puntero al InputLayout.
		 */
		InputLayout* m_pInputLayout;

		///************************************************************************/
		///*                     Funciones de clase.							  */
		///************************************************************************/

		/**
		 *	@brief Funcion para liberar memoria del objeto.
		 */
		void Destroy();

		/** 
		 *	@brief Funcion para crear el IL.
		 *	@param ceDevice* pDevice: Device para crear el InputLayout.
		 *	@param ceBlob* pBlob: Puntero a un blob.
		 */
		void CreateILO(ceDevice* pDevice, ceBlob* pBlob);

	};
}
