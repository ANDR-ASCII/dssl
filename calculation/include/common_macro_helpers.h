#pragma once

#include "assert_impl.h"

#define ASSERT(condition) if((condition) == false) \
::Calculation::doAssert(__FILE__, __LINE__, __FUNCTION__, #condition);

#ifdef NDEBUG

#define DEBUG_ASSERT(condition)
#define VERIFY(Connection) Connection

#else

#define DEBUG_ASSERT(condition) ASSERT(condition)
#define VERIFY(Connection) ASSERT(Connection)

#endif
