// CMake_test.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <Windows.h>

#ifdef UNICODE
#define CRLF 0x000a000d
#define toTCHAR(x) L##x 
#else
#define CRLF 0x00000a0d
#define toTCHAR(x) x
#endif // UNICODE

void WriteLn(LPTCH str);
BOOL CPUID_Suppoted();