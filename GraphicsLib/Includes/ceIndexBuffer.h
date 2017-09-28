#pragma once
#include "ceBuffer.h"

namespace ceEngineSDK
{
	/**
	 *	@brief Clase de buffers de indices hereda de buffer.
	 */
	class CE_GRAPHICS_EXPORT ceIndexBuffer : public ceBuffer
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
		ceIndexBuffer();

		/**
		 *	@brief Destructor default.
		 */
		virtual ~ceIndexBuffer();

		///************************************************************************/
		///*                    Funciones de la clase							  */
		///************************************************************************/

		/**
		 *	@brief Funcion para crear un buffer.
		 *	@param ceDevice* pDevice: Device para creacion de buffer.
		 *	@param Vector<uint32>& Indices: Vector de indices.
		 *	@return verdadero si se creo con exito, falso en caso contrario.
		 */
		bool CreateBuffer(ceDevice* pDevice, Vector<uint32>& Indices);

		/**
		 *	@brief Funcion para setear un buffer.
		 *	@param void* pDeviceContext: DeviceContext para setear el buffer constante.
		 */
		void SetBuffer(ceDeviceContext* pDeviceContext);


		///************************************************************************/
		///*                         Funciones heredadas						  */
		///************************************************************************/

		/**
		 *	@brief Funcion para liberar memoria del buffer.
		 */
		virtual void Destroy();

		/**
		 *	@brief Funcin para mapear un buffer.
		 *	@param void* pDeviceContext: El device context que se requiere para mapear el buffer.
		 *	@return recurso mapeado visto como void*.
		 */
		virtual void* MapBuffer(ceDeviceContext* pDeviceContext);

		/**
		 *	@brief Funcion de un map para el buffer.
		 *	@param void* pDeviceContext: El device context que se requiere llamar la funcion de unmap.
		 */
		virtual void UnMapBuffer(ceDeviceContext* pDeviceContext);
	};
}
