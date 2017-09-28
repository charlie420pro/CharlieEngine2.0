#pragma once
#include "ceVertex.h"
#include "ceBuffer.h"

namespace ceEngineSDK
{
	/** 
	 *	@brief Clase para la utilizacion de vertexbuffer, hereda de buffer.
	 */
	class CE_GRAPHICS_EXPORT ceVertexBuffer : public ceBuffer
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
		ceVertexBuffer();

		/**
		 *	@brief Destructor default.
		 */
		virtual ~ceVertexBuffer();

		///************************************************************************/
		///*                    Funciones de la clase							  */
		///************************************************************************/

		/**
		 *	@brief Funcion para crear un buffer.
		 *	@param ceDevice* pDevice: Device para creacion de buffer.
		 *	@param Vector<ceVertex>& Vertex: Vector de vertices.
		 *	@return verdadero si se creo con exito, falso en caso contrario.
		 */
		bool CreateBuffer(ceDevice* pDevice, Vector<ceVertex>& Vertex);

		/**
		 *	@brief Funcion para setear un buffer.
		 *	@param ceDeviceContext* pDeviceContext: DeviceContext para setear el buffer constante.
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