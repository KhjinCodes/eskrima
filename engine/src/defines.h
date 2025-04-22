#ifndef DEFINES_H
#define DEFINES_H

// Unsigned int types
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;

// Signed int types
typedef unsigned char sint8;
typedef unsigned short sint16;
typedef unsigned int sint32;
typedef unsigned long long sint64;

// Floating point variables
typedef float float32;
typedef double float64;

// Boolean
typedef uint8 boolean;
typedef uint32 boolean32;

#define TRUE 1
#define FALSE 0

// Properly define static assertions
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

// Ensure all types are of the correct size
STATIC_ASSERT(sizeof(uint8) == 1, "Expected uint8 to be 1 bytes.");
STATIC_ASSERT(sizeof(uint16) == 2, "Expected uint8 to be 2 bytes.");
STATIC_ASSERT(sizeof(uint32) == 4, "Expected uint8 to be 4 bytes.");
STATIC_ASSERT(sizeof(uint64) == 8, "Expected uint8 to be 8 bytes.");

STATIC_ASSERT(sizeof(sint8) == 1, "Expected sint8 to be 1 bytes.");
STATIC_ASSERT(sizeof(sint16) == 2, "Expected sint16 to be 2 bytes.");
STATIC_ASSERT(sizeof(sint32) == 4, "Expected sint32 to be 4 bytes.");
STATIC_ASSERT(sizeof(sint64) == 8, "Expected sint64 to be 8 bytes.");

STATIC_ASSERT(sizeof(float32) == 4, "Expected float32 to be 4 bytes.");
STATIC_ASSERT(sizeof(float64) == 8, "Expected float64 to be 8 bytes.");

// Platform detection
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
    #define EPLATFORM_WINDOWS 1
    #ifndef _WIN64
        #error "64-bit is required on Windows!"
    #endif
#elif defined(__linux__) || defined(__gnu_linux__)
    // Linux OS
    #define EPLATFORM_LINUX 1
    #if defined(__ANDROID__)
        #define EPLATFORM_ANDROID 1
    #endif
#elif defined(__unix__)
    // Catch anything not caught by above
    #define EPLATFORM_UNIX 1
#elif defined(_POSIX_VERSION_)
    #define EPLATFORM_POSIX 1
#endif

// Exporting and importing functions
#ifdef EEXPORT
    // Exports  
    #ifdef _MSC_VER
        #define EAPI __declspec(dllexport)
    #else
        #define EAPI __attribute__((visibility("default")))
    #endif
#else
    // Imports
    #ifdef _MSC_VER
        #define EAPI __declspec(dllimport)
    #else
        #define EAPI
    #endif
#endif

#endif // DEFINES_H