#pragma once
#include "cePrerequisitesGraphics.h"
#include <ceVector3D.h>
#include <ceVector4D.h>

namespace ceEngineSDK
{
	struct CE_GRAPHICS_EXPORT ceLight
	{
	public:
		/**
		 *	@brief Posicion de la luz.
		 */
		ceVector3D m_LightPosition;

		/**
		 *	@brief Color a pintar.
		 */
		ceVector4D m_Color;
	};
}