// CMake_test.cpp : Defines the entry point for the application.
//

#define UNICODE

#include "CMake_test.h"

HANDLE hstdOUT;
//HANDLE hstdIN;
//TCHAR  buff[256];

int main()
{
    hstdOUT = GetStdHandle(STD_OUTPUT_HANDLE);
    //	hstdIN  = GetStdHandle(STD_INPUT_HANDLE);

    WriteLn(toTCHAR("тест c++"));
 
    return 0;
}

void WriteLn(LPTCH str)
{
    DWORD Writen, endStr = CRLF;
    WriteConsole(hstdOUT, str, lstrlen(str), &Writen, NULL);
    WriteConsole(hstdOUT, &endStr, 2, &Writen, NULL);
}
