#include <windows.h>

int WINAPI wWinMain(HINSTANCE hi, HINSTANCE hpi, PWSTR cmd, int ns)
{
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    CHAR dfdir[1024];

    if (GetFullPathNameA("..", 1024, dfdir, NULL) == 0)
    {
        MessageBoxA(NULL, "could not get current directory", NULL, 0);
        exit(1);
    }

    if (SetCurrentDirectoryA(dfdir) == 0)
    {
        MessageBoxA(NULL, "could not change to DF directory", NULL, 0);
        exit(1);
    }

    if (CreateProcessA("Dwarf Fortress.exe",
        NULL,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi) == 0)
    {
        MessageBoxA(NULL, "could not launch 'Dwarf Fortress.exe'", NULL, 0);
        exit(1);
    }

    exit(0);
}
