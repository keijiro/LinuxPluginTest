#include <cstdio>
#include "IUnityInterface.h"

extern "C"
{
    typedef void(*PrintFunction)(const char*);
    PrintFunction printFunction_;

    void UnityLog(const char* message)
    {
        if (printFunction_ != nullptr) printFunction_(message);
    }

    void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API UnityPluginLoad(IUnityInterfaces* unityInterfaces)
    {
        UnityLog("TestPlugin - Loaded");
    }

    void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API UnityPluginUnload()
    {
        UnityLog("TestPlugin - Unloaded");
    }

    int UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API GetID()
    {
        UnityLog("TestPlugin - GetID Called");
        return 12345;
    }

    void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API SetPrintFunction(PrintFunction p)
    {
        printFunction_ = p;
    }
}
