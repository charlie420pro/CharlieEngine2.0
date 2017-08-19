#pragma once

#undef min
#undef max

#include <new>
#include <atomic>
#include <limits>
#include <utility>

namespace ceEngineSDK
{
	class CE_UTILITY_EXPORT MemoryAllocatorBase;


	class MemoryCounter
	{
	public:
		static CE_UTILITY_EXPORT uint64 GetNumAllocs()
		{
			return m_Allocs;
		}
		static CE_UTILITY_EXPORT uint64 GetNumFrees()
		{
			return m_Frees;
		}
	private:
		friend class MemoryAllocatorBase;

		static CE_UTILITY_EXPORT void IncrementAllocCount() { m_Allocs++; }
		static CE_UTILITY_EXPORT void IncrementFreeCount() { m_Frees++; }

		static CE_THREADLOCAL uint64 m_Allocs;
		static CE_THREADLOCAL uint64 m_Frees;
	};

	class MemoryAllocatorBase
	{
	protected:
		static void IncrementAllocCount() { MemoryCounter::IncrementAllocCount(); }
		static void IncrementFreeCount() { MemoryCounter::IncrementFreeCount(); }
	};

	template<class T>
	class MemoryAllocator : public MemoryAllocatorBase
	{
	public:
		static inline void* Allocate(SIZE_T bytes)
		{
#if CE_PROFILING_ENABLED
			IncrementAllocCount();
#endif
			return malloc(bytes);
		}
		static inline void* AllocateArray(SIZE_T bytes, uint32 count)
		{
#if CE_PROFILING_ENABLED
			IncrementAllocCount();
#endif
			return malloc(bytes*count);
		}
		static inline void Free(void* ptr)
		{
#if CE_PROFILING_ENABLED
			IncrementFreeCount();
#endif
			::free(ptr);
		}
		static inline void FreeArray(void* ptr, uint32 count)
		{
			CE_UNREFERENCED_PARAMETER(count);
#if CE_PROFILING_ENABLED
			IncrementFreeCount();
#endif
			::free(ptr);
		}
	};

	class GenAlloc
	{
	
	};

	template<class Alloc>
	inline void* ce_alloc(SIZE_T count)
	{
		return MemoryAllocator<Alloc>::Allocate(count);
	}

	template<class T, class Alloc>
	inline T* ce_alloc()
	{
		return (T*)MemoryAllocator<Alloc>::Allocate(sizeof(T));
	}

	template<class T, class Alloc>
	inline T* ce_newN(uint32 count)
	{
		T* ptr = (T*)MemoryAllocator<Alloc>::AllocateArray(sizeof(T), count);
		for (uint32 i = 0; i < count; i++)
		{
			new((void*)&ptr[i]) T;
		}
		return ptr;
	}

	template<class Type, class Alloc, class... Args>
	Type* ce_new(Args&&... args)
	{
		return new(ce_alloc<Alloc>(sizeof(Type))) Type(std::forward<Args>(args)...);
	}

	template<class Alloc>
	inline void ce_free(void* ptr)
	{
		MemoryAllocator<Alloc>::Free(ptr);
	}

	template<class T, class Alloc = GenAlloc>
	inline void ce_delete(T* ptr)
	{
		(ptr)->~T();
		MemoryAllocator<Alloc>::Free(ptr);
	}

	template<class T, class Alloc = GenAlloc>
	inline void ce_deleteN(T* ptr, uint32 count)
	{
		for (uint32 i = 0; i < count; i++)
		{
			ptr[i].~T();
		}

		MemoryAllocator<Alloc>::FreeArray(ptr, count);
	}

	inline void* ce_alloc(SIZE_T count)
	{
		return MemoryAllocator<GenAlloc>::Allocate(count);
	}

	template<class T>
	inline T* ce_alloc()
	{
		return (T*)MemoryAllocator<GenAlloc>::Allocate(sizeof(T));
	}

	template<class T>
	inline T*ce_newN(uint32 count)
	{
		T* ptr = (T*)MemoryAllocator<GenAlloc>::AllocateArray(sizeof(T), count);
		for (uint32 i = 0; i < count; i++)
		{
			new((void*)&ptr[i]) T;
		}

		return ptr;
	}

	template<class Type, class... Args>
	Type* ce_new(Args&&... args)
	{
		return new(ce_alloc<GenAlloc>(sizeof(Type))) Type(std::forward<Args>(args)...);
	}

	inline void ce_free(void* ptr)
	{
		MemoryAllocator<GenAlloc>::Free(ptr);
	}

#define CE_PVT_DELETE(T, ptr)	\
	(ptr)->~T();				\
	MemoryAllocator<GenAlloc>::Free(ptr);

#define CE_PVT_DELETE_A(T, ptr, Alloc)	\
	(ptr)->~T();						\
	MemoryAllocator<Alloc>::Free(ptr);
}

namespace ceEngineSDK
{
	template <class T, class Alloc= GenAlloc>
	class StdAlloc
	{
	public:
		typedef T value_type;
		StdAlloc() _NOEXCEPT {}
		template<class T, class Alloc> StdAlloc(const StdAlloc<T, Alloc>&) _NOEXCEPT {}
		template<class T, class Alloc>  bool operator==(const StdAlloc<T, Alloc>&) const _NOEXCEPT { return true; }
		template<class T, class Alloc>	bool operator!=(const StdAlloc<T, Alloc>&) const _NOEXCEPT { return false; }

		T* allocate(const size_t num) const 
		{
			if (num == 0)
			{
				return nullptr;
			}

			if (num > static_cast<size_t>(-1) / sizeof(T))
			{
				throw std::bad_array_new_length();
			}

			void* const pv = ce_alloc<Alloc>((uint32)(num * sizeof(T)));
			if (!pv)
			{
				throw std::bad_alloc();
			}

			return static_cast<T*>(pv);
		}

		void deallocate(T* p, size_t) const _NOEXCEPT
		{
			ce_free<Alloc>((void*)p);
		}
	};
}

//namespace ceEngineSDK
//{
//	template <class T, class Alloc = GenAlloc>
//	class StdAlloc {};
//}