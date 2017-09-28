#include "ceBlob.h"
#include "DX11Headers.h"


namespace ceEngineSDK
{
	//! Constructor default de la clase.
	ceBlob::ceBlob()
	{
		m_pBlob = nullptr;
		m_pBlob = new Blob();
	}

	//! Destructor default de la clase.
	ceBlob::~ceBlob()
	{
		Destroy();
	}

	//! Funcion para liberar memoria del blob.
	void ceBlob::Destroy()
	{
		if (m_pBlob != nullptr)
		{
			m_pBlob->Destroy();
			delete m_pBlob;
			m_pBlob = nullptr;
		}
	}

	//! Funcion para regresar un puntero al buffer.
	const void* ceBlob::GetBufferPointer()
	{
		
		return reinterpret_cast<void*>(m_pBlob->m_pDXBlob->GetBufferPointer());
	}

	//! Funcion para obtener el tamaño del buffer.
	SIZE_T ceBlob::GetBufferSize()
	{
		return m_pBlob->m_pDXBlob->GetBufferSize();
	}

	//! Funcin para agregar referencia.
	uint64 ceBlob::AddRef()
	{
		return m_pBlob->m_pDXBlob->AddRef();
	}

}