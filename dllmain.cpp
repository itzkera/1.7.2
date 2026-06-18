// dllmain.cpp : Defines the entry point for the DLL application.
#include "framework.h"
#include <Windows.h>
#include <thread>
#include <cstdio>
#include "MinHook.h"
#pragma comment(lib, "minhook.lib")
#include "Dih.h"

void Main()
{
    AllocConsole();
    FILE* file = nullptr;
    freopen_s(&file, "CONOUT$", "w", stdout);
    std::cout << "Starting 1.7.2" << std::endl;
    //sleep(5000);
    MH_Initialize();


    UKismetSystemLibrary::ExecuteConsoleCommand(UWorld::GetWorld(), L"open Athena_Terrain", nullptr); 
    

}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        std::thread(Main).detach();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}