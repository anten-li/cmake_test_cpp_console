// CMake_test.cpp : Defines the entry point for the application.

//#define UNICODE

#include "CMake_test.h"

HANDLE hstdOUT;

int main()
{
    hstdOUT = GetStdHandle(STD_OUTPUT_HANDLE);

    WriteLn(toTCHAR("Check support CPUID:"));
    if (CPUID_Suppoted())
    {
        WriteLn(toTCHAR("  Ok"));
    }
    else
    {
        WriteLn(toTCHAR("  Fail"));
        return 1;
    }
 
    return 0;
}

void WriteLn(LPTCH str)
{
    DWORD Writen, endStr = CRLF;
    WriteConsole(hstdOUT, str, lstrlen(str), &Writen, NULL);
    WriteConsole(hstdOUT, &endStr, 2, &Writen, NULL);
}

BOOL CPUID_Suppoted()
{
    __asm {
        pushfd                              //Save EFLAGS
        pushfd                              //Store EFLAGS
        xor dword ptr [esp], 0x00200000     //Invert the ID bit in stored EFLAGS
        popfd                               //Load stored EFLAGS(with ID bit inverted)
        pushfd                              //Store EFLAGS again(ID bit may or may not be inverted)
        pop EAX                             //eax = modified EFLAGS(ID bit may or may not be inverted)
        xor EAX, [esp]                      //eax = whichever bits were changed
        popfd                               //Restore original EFLAGS
        and EAX, 0x00200000
    };
}
