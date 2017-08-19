#pragma once
#include <cePrerequisitesUtil.h>

/******************************/
/* Windows specific Settings. */
/******************************/
#if CE_PLATFORM == CE_PLATFORM_WIN32
#if defined ( CE_STATIC_LIB )
#define CE_GRAPHICS_EXPORT
#else
#if defined(CE_GRAPHICS_EXPORTS)
#define CE_GRAPHICS_EXPORT __declspec( dllexport )
#else
#if defined( __MINGW32__ )
#define CE_GRAPHICS_EXPORT
#else
#define CE_GRAPHICS_EXPORT __declspec( dllimport )
#endif
#endif
#endif

#if defined(_DEBUG) || defined(DEBUG)
#define CE_DEBUG_MODE 1
#else
#define CE_DEBUG_MODE 0
#endif

#if CE_COMPILER == CE_COMPILER_INTEL
#define CE_THREADLOCAL __declspec(thread)
#endif
#endif