#pragma once
#include "cePrerequisitesUtil.h"
#include <wchar.h>

namespace ceEngineSDK
{
	template<typename T>
	using BasicString = std::basic_string<T, std::char_traits<T>, StdAlloc<T>>;// si no funciona alloc implementar std::allocator<T>

	template <typename T>
	using BasicStringStream = std::basic_stringstream<T, std::char_traits<T>, StdAlloc<T>>;

	typedef BasicString<UNICHAR> WString;

	typedef BasicString<ANSICHAR> String;

	typedef BasicStringStream<UNICHAR> WStringStream;

	typedef BasicStringStream<ANSICHAR> StringStream;

}