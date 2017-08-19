#pragma once

#define CE_PLATFORM_WIN32	1							//Windows Platform
#define CE_PLATFORM_LINUX	2							//Linux Platform
#define CE_PLATFORM_APPLE	3							//Apple Platform
#define CE_PLATFORM_PS4		4							//PlayStation 4 Platform
		
#define CE_COMPILER_MSVC	1							//Visual Studio Compiler
#define CE_COMPILER_GNUC	2							//GCC Compiler
#define CE_COMPILER_INTEL	3							//intel Compiler
#define CE_COMPILER_CLANG	4							//Clang Compiler
		
#define CE_ARCHITECTURE_x86_32	1						//intel x86 32 Bits
#define CE_ARCHITECTURE_x86_64	2						//intel x86 64 Bits
		
#define CE_ENDIAN_LITTLE	1							//Little Endian
#define CE_ENDIAN_BIG	2								//Big Endian
		
#define CE_ENDIAN CE_ENDIAN_LITTLE						//Define the actual endian type(little endian)
		
#define CE_EDITOR_BUILD	1

/**/
/* Compiler type and version. */
/**/
#if defined( _MSC_VER )							//Visual Studio
	#define CE_COMPILER CE_COMPILER_MSVC				//Set as Actual Compiler
	#define CE_COMP_VER _MSC_VER						//Compiler version
	#define CE_THREADLOCAL __declspec(thread)				//Local Thread type
#elif defined( __GNUC__ )						//GCC Compiler
	#define CE_COMPILER CE_COMPILER_GNUC			//Set as ACtual Compiler
	#define CE_COMP_VER (((__GNUC__)*100) + (__GNUC_MINOR__*10) + __GNUC_PATCHLEVEL__)	//Compiler version
	#define CE_THREADLOCAL __thread					
#elif defined ( __INTEL_COMPILER )
	#define CE_COMPILER CE_COMPILER_INTEL
	#define CE_COMP_VER __INTEL_COMPILER

#elif defined ( __clang__ )
	#define CE_COMPILER CE_COMPILER_CLANG
	#define CE_COMP_VER __clang_major__
	#define CE_THREADLOCAL __thread
#else
	#pragma error "No known compiler."
#endif

/**/
/* See if we can use __forceinline or if we need to use __inline instead */
/**/
#if CE_COMPILER == CE_COMPILER_MSVC							//If we are compiling on Visual Studio
	#if CE_COMP_VER >= 1200									//If we are on Visual Studio 6 or higher
		#define FORCEINLINE __forceinline					//Set __forceinline
		#ifndef RESTRICT
			#define RESTRICT __restrict
		#endif
	#endif
#elif defined (__MINGW32__)
	#if !defined(FORCEINLINE)
		#define FORCEINLINE __inline
		#ifndef RESTRICT
			#define RESTRICT
		#endif
	#endif
#else
	#define FORCEINLINE __inline
	#ifndef RESTRICT
		#define RESTRICT __restrict
	#endif
#endif

/**/
/* Finds the current platform. */
/**/
#if defined(__WIN32__) || defined(_WIN32)
	#define CE_PLATFORM CE_PLATFORM_WIN32
#elif defined( __APPLE_CC__)
	#define CE_PLATFORM CE_PLATFORM_APPLE
#elif defined( __ORBIS__ )
	#define CE_PLATFORM CE_PLATFORM_PS4
#else
	#define CE_PLATFORM CE_PLATFORM_LINUX
#endif

/**/
/* Find the architecture type. */
/**/
#if defined (__x86_64__) || defined(_M_X64)
	#define CE_ARCH_TYPE CE_ARCHITECTURE_x86_64
#else
	#define CE_ARCH_TYPE CE_ARCHITECTURE_x86_32
#endif

/**/
/* Memory Alignment macros. */
/**/

#if CE_COMPILER == CE_COMPILER_MSVC
	#define MS_ALIGN(n)__declspec(align(n))
	#ifndef GCC_PACK
		#define GCC_PACK(n)
	#endif
	#ifndef GCC_ALIGN
		#define GCC_ALIGN(n)
	#endif
#elif ( CE_COMPILER == CE_COMPILER_GNUC && CE_PLATFORM == CE_PLATFORM_PS4)
	#define MS_ALIGN(n)
	#define GCC_PACK(n)
	#define GCC_ALIGN(n) __attribute__( (__aligned(n)) )
#else 
	#define MS_ALIGN(n)
	#define GCC_PACK(n) __attribute__( (packed, aligned(n)) )
	#define GCC_ALIGN(n) __attribute__( (aligned(n)) )
#endif

/*********************************************************************************************/
/* For throw override (deprecated on c++11 but Visual Studio does not have handle no expect. */
/*********************************************************************************************/
#if CE_COMPILER == CE_COMPILER_MSVC
	#define _NOEXCEPT noexcept
#elif CE_COMPILER == CE_COMPILER_INTEL
	#define _NOEXCEPT noexcept
#elif CE_COMPILER == CE_COMPILER_GNUC
	#define _NOEXCEPT noexcept
#else	
	#define _NOEXCEPT
#endif

/******************************/
/* Windows specific Settings. */
/******************************/
#if CE_PLATFORM == CE_PLATFORM_WIN32
	#if defined ( CE_STATIC_LIB )
		#define CE_UTILITY_EXPORT
	#else
		#if defined(CE_UTILITY_EXPORTS)
			#define CE_UTILITY_EXPORT __declspec( dllexport )
		#else
			#if defined( __MINGW32__ )
				#define CE_UTILITY_EXPORT
			#else
				#define CE_UTILITY_EXPORT __declspec( dllimport )
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

#if CE_PLATFORM == CE_PLATFORM_LINUX || CE_PLATFORM == CE_PLATFORM_APPLE
	#if defined (CE_GCC_VISIBILITY)
		#define CE_UTILITY_EXPORT __attribute__ ((visibility("default")))
	#else
		#define CE_UTILITY_EXPORT
	#endif

	#define stricmp strcasecmp

	#if defined(_DEBUG) || defined(DEBUG)
		#define CE_DEBUG_MODE 1
	#else 
		#define CE_DEBUG_MODE 0
	#endif

	#if CE_COMPILER ==CE_COMPILER_INTEL
		#define CE_THREADLOCAL__thread
	#endif
#endif

/**/
/* PS4 specific Settings*/
/**/
#if CE_PLATFORM == CE_PLATFORM_PS4
	#if defined ( CE_STATIC_LIB )
		#define CE_UTILITY_EXPORT
	#else
		#if defined(CE_UTILITY_EXPORTS)
			#define CE_UTILITY_EXPORT __declspec( dllexport )
		#else
		#if defined( __MINGW32__ )
			#define CE_UTILITY_EXPORT
		#else
			#define CE_UTILITY_EXPORT __declspec( dllimport )
		#endif
	#endif
#endif

	#if defined(_DEBUG) || defined(DEBUG)
		#define CE_DEBUG_MODE 1
	#else
		#define CE_DEBUG_MODE 0
	#endif
#endif

#if CE_DEBUG_MODE
	#define CE_DEBUG_ONLY(x)x
	#define CE_ASSERT(x) assert(x)
#else
	#define CE_DEBUG_ONLY(x)
	#define CE_ASSERT(x)
#endif


#ifndef CE_UNREFERENCED_PARAMETER
#define CE_UNREFERENCED_PARAMETER(P) void(P)
#endif


