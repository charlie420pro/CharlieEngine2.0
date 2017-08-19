#pragma once

/**/
/* Includes*/
/**/
#include "cePlatformDefines.h"

#if CE_PLATFORM == CE_PLATFORM_PS4
	#include <scebase.h>
#endif

namespace ceEngineSDK
{
	typedef unsigned char	uint8;
	typedef unsigned short	uint16;
	typedef unsigned int	uint32;
#if CE_COMPILER == CE_COMPILER_MSVC
	typedef unsigned __int64	uint64;
#else
	typedef unsigned long	uint64;
#endif

	typedef signed char	int8;
	typedef signed short int16;
	typedef signed int	int32;
#if CE_COMPILER == CE_COMPILER_MSVC
	typedef signed __int64	int64;
#else
	typedef signed long	int64;
#endif
	MS_ALIGN(16) class QWord
	{
	public:
		uint64	m_lower;
		int64	m_upper;

		operator int64()const 
		{
			return m_lower;
		}

		QWord() : m_lower(0), m_upper(0)
		{

		}

		QWord(bool from) : m_lower(from), m_upper(0)
		{
		
		}

		QWord(uint8 from) : m_lower(from), m_upper(0)
		{

		}

		QWord(uint16 from) : m_lower(from), m_upper(0)
		{

		}

		QWord(uint32 from) : m_lower(from), m_upper(0)
		{

		}

		QWord(uint64 from) : m_lower(from), m_upper(0)
		{

		}

		QWord(int8 from) : m_lower(from), m_upper(0)
		{

		}

		QWord(int16 from) : m_lower(from), m_upper(0)
		{

		}

		QWord(int32 from) : m_lower(from), m_upper(0)
		{

		}

		QWord(int64 from) : m_lower(from), m_upper(0)
		{

		}

		QWord(float from) : m_lower((uint64)from), m_upper(0)
		{

		}

		QWord(double from) : m_lower((uint64)from), m_upper(0)
		{

		}

	}GCC_ALIGN(16);

	typedef QWord int128;
	typedef QWord uint128;

#if CE_COMPILER == CE_COMPILER_MSVC || CE_PLATFORM== CE_PLATFORM_PS4
	typedef wchar_t	WCHAR;
#else
	typedef unsigned short WCHAR;
#endif
	typedef char	ANSICHAR;
	typedef WCHAR	UNICHAR;

	typedef int TYPE_OF_NULL;

#if ((CE_ARCH_TYPE ==CE_ARCHITECTURE_x86_64) && (CE_COMPILER == CE_COMPILER_MSVC))
	typedef unsigned __int64	SIZE_T;
#else
	typedef unsigned long	SIZE_T;
#endif

}