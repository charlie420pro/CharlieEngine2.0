#include "ceBlob.h"
#include "DX11Headers.h"


namespace ceEngineSDK
{
	

	/**
	 *	@brief Constructor default de la clase.
	 **/
	ceBlob::ceBlob()
	{
		m_pBlob = nullptr;
		m_pBlob = new BlobDX();
	}

	/**
	 *	@brief Destructor default de la clase.
	 **/
	ceBlob::~ceBlob()
	{
		Destroy();
	}

	/**
	 *	@brief Funcion para obtener una referencia del blob.
	 *	@return referencia al blob.
	 **/
	void ** ceBlob::GetBlobReference()
	{
		//! Regresa el Blob por referencia reint32erpretado como void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pBlob->m_pDXBlob);
	}
	
	/**
	 *	@bref Funcion para obtener el puntero al buffer del blob.
	 *	@return bufferpoint32er
	 **/
	const void * ceBlob::GetBufferPointer()
	{
		return m_pBlob->m_pDXBlob->GetBufferPointer();
	}

	/**
	 *	@brief Funcion para obtener el tamaño del buffer.
	 *	@return tamaño del buffer.
	 **/
	SIZE_T ceBlob::GetBufferSize()
	{
		return m_pBlob->m_pDXBlob->GetBufferSize();
	}

	void ceBlob::Destroy()
	{
		if (m_pBlob != nullptr)
		{
			m_pBlob->Destroy();
			delete m_pBlob;
			m_pBlob = nullptr;
		}
	}

	/**
	 *	@brief Funcion para obtener el blob.
	 *	@return blob.
	 **/
	void * ceBlob::GetBlob()
	{
		//! Regresa el blob  reint32erpretado como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pBlob->m_pDXBlob);
	}
}