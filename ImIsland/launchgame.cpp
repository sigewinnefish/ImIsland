#include <Windows.h>
#include <pathcch.h>
#include <string>
#pragma comment(lib, "Pathcch.lib")

static void launchGameImpl(char* path)
{
    STARTUPINFOW si{};
    PROCESS_INFORMATION pi{};
    si.cb = sizeof(si);

    WCHAR workdir[MAX_PATH];
    std::wstring wpath = std::wstring(path, path + strlen(path));;

    wcsncpy_s(workdir, wpath.c_str(), MAX_PATH);
    PathCchRemoveFileSpec(workdir, MAX_PATH);
    BOOL started = CreateProcess(wpath.c_str(), NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, workdir, &si, &pi);

    WCHAR dllPath[MAX_PATH];
    GetModuleFileNameW(NULL, dllPath, MAX_PATH);
    PathCchRemoveFileSpec(dllPath, MAX_PATH);
    PathCchCombine(dllPath, MAX_PATH, dllPath, L"Snap.Hutao.UnlockerIsland.dll");

    HANDLE hOpenProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, pi.dwProcessId);
    LPVOID ptr = VirtualAllocEx(hOpenProcess, NULL, 4096, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    BOOL iswrite = WriteProcessMemory(hOpenProcess, ptr, dllPath, wcslen(dllPath) * 2 + 2, NULL);

    HMODULE hm = GetModuleHandleW(L"kernel32.dll");
    FARPROC hp = GetProcAddress(hm, "LoadLibraryW");

    HANDLE hcrt = CreateRemoteThread(hOpenProcess, NULL, NULL, (LPTHREAD_START_ROUTINE)hp, ptr, NULL, NULL);
    WaitForSingleObject(hcrt, INFINITE);
    BOOL free = VirtualFreeEx(hOpenProcess, ptr, 0, MEM_RELEASE);
    CloseHandle(hcrt);
    FreeLibrary(hm);
    ResumeThread(pi.hThread);
}

DWORD WINAPI launchGame(LPVOID lpParameter)
{
    launchGameImpl((char*)lpParameter);
    return 0;
}

