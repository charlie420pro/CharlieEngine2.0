#pragma once
#include "ceBuffer.h"

namespace ceEngineSDK
{
	/**
	 *	@brief Clase de buffers constantes, hereda de buffer.
	 */
	class CE_GRAPHICS_EXPORT ceConstantBuffer : public ceBuffer 
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
		ceConstantBuffer();

		/**
		 *	@brief Destructor default.
		 */
		virtual ~ceConstantBuffer();

		///************************************************************************/
		///*                    Funciones de la clase							  */
		///************************************************************************/

		
		/**
		 *	@brief Funcion para crear un buffer.
		 *	@param ceDevice* pDevice: Device para creacion de buffer.
		 *	@param uint32 uiSize: Tamaño del buffer.
		 *	@return verdadero si se creo con exito, falso en caso contrario.
		 */
		bool CreateBuffer(ceDevice* pDevice, uint32 uiSize);

		/**
		 *	@brief Funcion para setear un buffer.
		 *	@param ceDeviceContext* pDeviceContext: DeviceContext para setear el buffer constante.
		 *	@param uint32 StartSlot: Posicion en la que se seteara el buffer.
		 */
		void SetBuffer(ceDeviceContext* pDeviceContext, uint32 StartSlot);

		///************************************************************************/
		///*                         Funciones heredadas						  */
		///************************************************************************/

		/**
		 *	@brief Funcion para liberar memoria del buffer.
		 */
		virtual void Destroy();

		/**
		 *	@brief Funcin para mapear un buffer.
		 *	@param ceDeviceContext* pDeviceContext: El device context que se requiere para mapear el buffer.
		 *	@return recurso mapeado visto como void*.
		 */
		virtual void* MapBuffer(ceDeviceContext* pDeviceContext);

		/**
		 *	@brief Funcion de un map para el buffer.
		 *	@param ceDeviceContext* pDeviceContext: El device context que se requiere llamar la funcion de unmap.
		 */
		virtual void UnMapBuffer(ceDeviceContext* pDeviceContext);
	};

}