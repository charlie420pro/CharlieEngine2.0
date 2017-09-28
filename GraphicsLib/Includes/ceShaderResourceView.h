#pragma once
#include "cePrerequisitesGraphics.h"

namespace ceEngineSDK
{
	///************************************************************************/
	///*   Declaracion por delante de las estructuras definidas en DXHeaders  */
	///************************************************************************/
	struct ShaderResourceView;

	/** 
	 *	@brief Clase de shader resource view.
	 */
	class CE_GRAPHICS_EXPORT ceShaderResourceView
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
		ceShaderResourceView();

		/** 
		 *	@brief Destructor default.
		 */
		~ceShaderResourceView();

		///************************************************************************/
		///*                      Variables miembro de clase.					  */
		///************************************************************************/

		/** 
		 *	@brief Puntero al shader resource view.
		 */
		ShaderResourceView* m_pShaderResourceView;

		///************************************************************************/
		///*							Funciones de la clase.					  */
		///************************************************************************/

		/**
		 *	@brief Funcion para liberar memoria del objeto.
		 */
		void Destroy();
	};
}
