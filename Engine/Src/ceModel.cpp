#include "ceModel.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <DX11Headers.h>

namespace ceEngineSDK
{
	
	/**
	 *	@brief Constructor default de la clase.
	 **/
	ceModel::ceModel()
	{

	}

	/**
	 *	@brief Destructor default de la clase.
	 **/
	ceModel::~ceModel()
	{

	}

	/**
	 *	@brief Funcion para inicializar el modelo.
	 *	@param String fileName: Nombre del archivo.
	 *	@param ceDevice* pDevice: Device.
	 **/
	void ceModel::Init(String fileName, ceDevice* pDevice)
	{
		ImportModel(fileName, pDevice);			/// Importamos el modelo.
		CreateVertexBuffers(pDevice);	/// Creamos los buffers de vertices.
		CreateIndexBuffers(pDevice);	/// Creamos los buffers de indices.
	}

	/**
	 *	@brief Funcion para actualizar.
	 *	@param float fTime tiempo de actualizacion.
	 **/
	void ceModel::Update(float fTime)
	{
	}

	/**
	 *	@brief Funcion para destruir.
	 **/
	void ceModel::Destroy()
	{
	}

	/**
	 *	@brief Funcion para renderear el modelo.
	 *	@param void* pDeviceContext para mandar el drawindex.
	 **/
	void ceModel::Render(ceDeviceContext* pDeviceContext)
	{
		/// Si la lista de meshes del modelo es diferente de 0.
		if (m_pMeshesVector.size() != 0)
		{
			/// Iteramos por cada mesh en la lista de mehses del modelo.
			for (uint32 i = 0; i < m_pMeshesVector.size(); i++)
			{
				/// Mandamos llamar el drawindex.
				pDeviceContext->m_pDeviceContext->m_pDXDeviceContext->DrawIndexed
				(m_pMeshesVector[i]->GetIndexSize(), 0, 0);
			}
		}
	}

	/**
	 *	@brief Funcion para crear los buffers de vertices.
	 *	@param void* pDevice para crear los buffers.
	 **/
	void ceModel::CreateVertexBuffers(ceDevice* pDevice)
	{
		/// Si la lista de meshes del modelo es diferente de 0 creamos los buffers.
		if (m_pMeshesVector.size() != 0)
		{
			/// Iteramos por cada mesh en la lista de mehses del modelo.
			for (uint32 i = 0; i < m_pMeshesVector.size(); i++)
			{
				/// Creamos una bandera para saber si se crearon los buffers.
				bool bSucced = false;
				/// Damos memoria al vertexbuffer del mesh actual.
				m_pMeshesVector[i]->m_pVertexBuffer = new ceVertexBuffer();
			
				/// Creamos el vertexbuffer.
				bSucced = m_pMeshesVector[i]->m_pVertexBuffer->CreateBuffer(pDevice, m_pMeshesVector[i]->m_VertexList);
				/// Si no se creo la funcion se retorna.
				if (!bSucced)
					return;
			}
		}
	}

	/**
	 *	@brief Funcion para crear los buffers de indices.
	 *	@param void* pDevice para crear los indices.
	 **/
	void ceModel::CreateIndexBuffers(ceDevice * pDevice)
	{
		/// Si la lista de meshes del modelo es diferente de 0 creamos los buffers.
		if (m_pMeshesVector.size() != 0)
		{
			/// Iteramos por cada mesh en la lista de mehses del modelo.
			for (uint32 i = 0; i < m_pMeshesVector.size(); i++)
			{
				/// Creamos una bandera para saber si se crearon los buffers.
				bool bSucced = false;
				/// Damos memoria al Indexbuffer del mesh actual.
				m_pMeshesVector[i]->m_pIndexBuffer = new ceIndexBuffer();
				/// Creamos el IndexBuffer.
				bSucced = m_pMeshesVector[i]->m_pIndexBuffer->CreateBuffer(pDevice, m_pMeshesVector[i]->m_IndicesList);
				/// Si no se creo la funcion se retorna.
				if (!bSucced)
					return;
			}
		}
	}

	void ceModel::SetBuffers(ceDeviceContext * pDeviceContext)
	{
		/// Si la lista de meshes del modelo es diferente de 0.
		if (m_pMeshesVector.size() != 0)
		{
			/// Iteramos por cada mesh en la lista de mehses del modelo.
			for (uint32 i = 0; i < m_pMeshesVector.size(); i++)
			{

				/// Seteamos el index buffer del mesh actual.
				m_pMeshesVector[i]->m_pIndexBuffer->SetBuffer(pDeviceContext);
				/// Seteamos el vertex buffer del mesh actual.
				m_pMeshesVector[i]->m_pVertexBuffer->SetBuffer(pDeviceContext);

				/// Seteamos la textura del mesh
				pDeviceContext->m_pDeviceContext->m_pDXDeviceContext->PSSetShaderResources(i, 1,
					&m_pMeshesVector[i]->m_pMaterial->m_pTexture->m_pTexture->m_pDXShaderResourceView);

			}
		}
	}


	/**
	 *	@brief Funcion para leer el archivo.
	 *	@param String fileName: Nombre del archivo.
	 **/
	void ceModel::ImportModel(String fileName, ceDevice* pDevice)
	{
		/// Guardamos el nombre del modelo para futuras referencias.
		m_sName = fileName;

		/// Creamos el importer de assimp.
		Assimp::Importer importer;

		/// Creamos las constantes de asimp para cargar el mesh.
		const aiScene* pScene = nullptr;
		const aiMesh* pActualMesh = nullptr;

		/// Importamos el modelo con assimp.
		pScene = importer.ReadFile(fileName.c_str(),
			aiProcess_FlipUVs |
			aiProcess_FlipWindingOrder |
			aiProcess_MakeLeftHanded |
			aiProcess_GenSmoothNormals |
			aiProcess_CalcTangentSpace |
			aiProcess_Triangulate |
			aiProcess_JoinIdenticalVertices |
			aiProcess_SortByPType);

		/// Checamos que la escena exista.
		if (pScene != nullptr)
		{
			/// Hacemos un recorrido por cada uno de los meshes de la escena.
			for (uint32 i = 0; i < pScene->mNumMeshes; i++)
			{
				/// Creamos un nuevo mesh de nuestros objeto mesh.
				ceMesh* pNewMesh = new ceMesh();

				/// Asignamos el puntero a mesh con el mesh actual.
				pActualMesh = pScene->mMeshes[i];

				/// Recorremos la lista de vertices del mesh para asignar los valores al de la lista de meshes.
				for (uint32 j = 0; j < pActualMesh->mNumVertices; j++)
				{
					///  Creamos un nuevo vertice y seteamos su posicion.
					ceVertex TempVertex;

					auto Pos = pActualMesh->mVertices[j];

					TempVertex.m_Position = ceVector3D(Pos.x,
											Pos.y,
											Pos.z);

					/// Si tiene cordenadas de textura las seteamos.
					if (pActualMesh->HasTextureCoords(0))
					{
						auto TexCoord = pActualMesh->mTextureCoords[0][j];
						TempVertex.m_TexCoord = ceVector2D(TexCoord.x,TexCoord.y);
					}
					/// Si no las seteamos default en 0.
					else
					{
						TempVertex.m_TexCoord = ceVector2D(0, 0);
					}

					/// Si tiene cordenadas de textura las seteamos.
					if (pActualMesh->HasNormals())
					{
						auto Normals = pActualMesh->mNormals;
						TempVertex.m_Normals = ceVector3D(Normals->x, Normals->y, Normals->z);
					}
					/// Si no las seteamos default en 0.
					else
					{
						TempVertex.m_Normals = ceVector3D(0, 0, 0);
					}

					/// Guardamos el vertice en la lista de vertices del mesh.
					pNewMesh->m_VertexList.push_back(TempVertex);

				}
				for (uint32 j = 0; j < pActualMesh->mNumFaces; j++)
				{
					/// Checamos su cara para guardar los indices.
					const aiFace& Face = pActualMesh->mFaces[j];
					if (3 == Face.mNumIndices)
					{
						/// Guardamos los indices en la lista de indices del mesh.
						pNewMesh->m_IndicesList.push_back(Face.mIndices[0]);
						pNewMesh->m_IndicesList.push_back(Face.mIndices[1]);
						pNewMesh->m_IndicesList.push_back(Face.mIndices[2]);

					}
				}


				/// Si la escena tiene materiales.
				if (pScene->HasMaterials())
				{
					/*aiMaterial* Material;
					aiString fileName;

					Material = pScene->mMaterials[pActualMesh->mMaterialIndex];
					Material->GetTexture(aiTextureType_DIFFUSE, 0, &fileName, nullptr, nullptr, nullptr, nullptr);*/

					String ImagePath = "C:\\Users\\carlo\\OneDrive\\Documentos\\Visual Studio 2015\\Projects\\MyEngine\\Bin\\Mewtow_Difuse.png";
					pNewMesh->m_pMaterial->LoadTexture(ImagePath, pDevice);
	
				}
				/// Insertamos el mesh en la lista de meshes.
				m_pMeshesVector.push_back(pNewMesh);
			}


		}
	}
}