#pragma once

#include "Logger.h"

#define BIT(x) (1 << x)

#ifndef NDEBUG
// Defining platform specific debug break
#ifdef _MSC_VER
    /// Windows
#define DEBUG_BREAK __debugbreak()
#elif defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
    /// POSIX
#include <signal.h>
#define DEBUG_BREAK raise(SIGTRAP)
#elif
    /// OTHERS.... write equivalent macro definition
#define DEBUG_BREAK
#endif
// Defining ASSERT macros
#define AUTUMN_ASSERT(x, ...)                                                                                                                  \
        {                                                                                                                                      \
            if (!(x)) {                                                                                                                        \
                AUTUMN_ERROR("Assertion failed: {0}", __VA_ARGS__);                                                                            \
                DEBUG_BREAK;                                                                                                                   \
            }                                                                                                                                  \
        }
#define AUTUMN_CORE_ASSERT(x, ...)                                                                                                             \
        {                                                                                                                                      \
            if (!(x)) {                                                                                                                        \
                AUTUMN_ENGINE_ERROR("Assertion failed: {0}", __VA_ARGS__);                                                                     \
                DEBUG_BREAK;                                                                                                                   \
            }                                                                                                                                  \
        }
#else

#define AUTUMN_ASSERT(x, ...) do {} while(0)
#define AUTUMN_CORE_ASSERT(x, ...) do {} while(0)

#endif
