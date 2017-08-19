#include "cePrerequisitesUtil.h"

namespace ceEngineSDK
{
	CE_THREADLOCAL uint64 MemoryCounter::m_Allocs = 0;
	CE_THREADLOCAL uint64 MemoryCounter::m_Frees = 0;
}