#pragma once

#ifdef __BORLANDC__
	#define __STD_ALGORITHM
#endif

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdarg>
#include <cmath>

#include <memory>

#include <vector>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <bitset>
#include <array>

#if (CE_COMPILER == CE_COMPILER_GNUC)
	#if CE_COMP_VER >= 430
		#include <tr1/unordered_map>
		#include <tr1/unordered_set>
	#elif (CE_PLATFORM== CE_PLATFORM_PS4)
		#include <unordered_map>
		#include <unordered_set>
	#else
		#include <ext/hash_map>
		#include <ext/hash_set>
#endif
#else
	#if (CE_COMPILER == CE_COMPILER_MSVC) && CE_COMP_VER >= 1600
		#include <unordered_map>
		#include <unordered_set>
	#else
		#include <hash_set>
		#include <hash_map>
	#endif
#endif

#include <algorithm>
#include <functional>
#include <limits>

#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

#ifdef __BORLANDC__
namespace ceEngineSDK
{
	using namespace std;
}
#endif

// C Types and Stats
extern "C"
{
	#include <sys/types.h>
	#include <sys/stat.h>
}

// Windows specifics
#if CE_PLATFORM == CE_PLATFORM_WIN32
	#undef min
	#undef max

	#if !defined(NOMINMAX) && defined(_MSC_VER)
		#define NOMINMAX
	#endif
	#if defined( __MINGW32__ )
		#include <unistd.h>
	#endif
#endif

// Linux specifics
#if CE_PLATFORM == CE_PLATFORM_LINUX
	extern "C"
	{
		#include <unistd.h>
		#include <dlfcn.h>
	}
#endif

// Apple specifics
#if CE_PLATFORM == CE_PLATFORM_APPLE
	extern "C"
	{
		#include <unistd.h>
		#include <sys/param.h>
		#include <CoreFoundation/CoreFoundation.h>
	}
#endif

#if CE_PLATFORM == CE_PLATFORM_PS4
	extern"C"
	{
		#include <unistd.h>
		#include <sys/param.h>
	}
#endif

namespace ceEngineSDK
{
	template<typename T, typename A = StdAlloc<T>>
	using Deque = std::deque<T, A>;

	template <typename T, typename A = StdAlloc<T>>
	using Vector = std::vector<T, A>;

	template <typename T, typename A = StdAlloc<T>>
	using List = std::list<T, A>;

	template <typename T, typename A = StdAlloc<T>>
	using Stack = std::stack<T, std::deque<T, A>>;

	template <typename T, typename A = StdAlloc<T>>
	using Queue = std::queue<T, std::deque<T, A>>;

	template <typename T, typename P = std::less<T>, typename A = StdAlloc<T>>
	using Set = std::set<T, P, A>;

	template <typename K, typename V, typename P = std::less<K>, typename A = StdAlloc < std::pair<const K, V>>>
	using Map = std::map<K, V, P, A>;

	template <typename K, typename V, typename P = std::less<K>, typename A = StdAlloc < std::pair<const K, V>>>
	using Multimap = std::multimap<K, V, P, A>;

	template <typename T, typename H = std::hash<T>, typename C = std::equal_to<T>, typename A = StdAlloc<T>>
	using UnorderedSet = std::unordered_set<T, H, C, A>;

	template <typename  K, typename V, typename H = std::hash<K>, typename C = std::equal_to<K>, typename A = StdAlloc<std::pair<const K, V>>>
	using UnorderedMap = std::unordered_map<K, V, H, C, A>;

	template <typename  K, typename V, typename H = std::hash<K>, typename C = std::equal_to<K>, typename A = StdAlloc<std::pair<const K, V >>>
	using UnorderedMultimap = std::unordered_multimap<K, V, H, C, A>;


	//template <typename T>
	//using SPtr = std::shared_ptr<T>;

	//template <typename T, typename Alloc = GenAlloc>
	//using UPtr = std::unique_ptr<T, decltype(&ce_delete<T, Alloc>)>;

	//template <class Type, class AllocCategory, class... Args>
	//SPtr<Type> ce_shared_ptr_new(Args&&... args)
	//{
	//	return std::allocate_shared<Type>(StdAlloc<Type, AllocCategory>(), std::forward<Args>(args)...);
	//}

	//template <class Type, class... Args>
	//SPtr<Type> ce_shared_ptr_new(Args&&... args)
	//{
	//	return std::allocate_shared<Type>(StdAlloc<Type, GenAlloc>(), std::forward<Args>(args)...);
	//}

	//template <class Type, class MainAlloc = GenAlloc, class PtrDataAlloc = GenAlloc>
	//SPtr<Type> ce_shared_ptr(Type* data)
	//{
	//	return std::shared_ptr<Type>(data, &ce_delete<Type, MainAlloc>, StdAlloc<Type, PtrDataAlloc>());
	//}

	//template <class Type, class Alloc = GenAlloc>
	//UPtr<Type, Alloc> ce_unique_ptr(Type* data)
	//{
	//	return std::unique_ptr<Type, decltype(&ce_delete<Type, Alloc>)>(data, ce_delete<Type, Alloc>);
	//}

	//template <class Type, class Alloc, class... Args>
	//UPtr<Type> ce_unique_ptr_new(Args &&... args)
	//{
	//	Type* rawPtr = ce_new<Type, Alloc>(std::forward<Args>(args)...);
	//	return ce_unique_ptr<Type, Alloc>(rawPtr);
	//}

	//template <class Type, class... Args>
	//UPtr<Type> ce_unique_ptr_new(Args &&... args)
	//{
	//	Type* rawPtr = ce_new<Type, GenAlloc>(std::forward<Args>(args)...);
	//	return ce_unique_ptr < Type, GenAlloc(rawPtr);
	//}
}

