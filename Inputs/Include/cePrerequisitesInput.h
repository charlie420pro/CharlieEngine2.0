#pragma once
#include <cePrerequisitesUtil.h>

#define DIRECTINPUT_VERSION 0x0800

#define NUM_KEYS 256

/******************************/
/* Windows specific Settings. */
/******************************/
#if CE_PLATFORM == CE_PLATFORM_WIN32
#if defined ( CE_STATIC_LIB )
#define CE_INPUT_EXPORT
#else
#if defined(CE_INPUT_EXPORTS)
#define CE_INPUT_EXPORT __declspec( dllexport )
#else
#if defined( __MINGW32__ )
#define CE_INPUT_EXPORT
#else
#define CE_INPUT_EXPORT __declspec( dllimport )
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