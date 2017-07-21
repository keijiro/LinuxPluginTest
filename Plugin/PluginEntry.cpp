#include <cstdio>
#include "IUnityInterface.h"

extern "C"
{
    void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API UnityPluginLoad(IUnityInterfaces* unityInterfaces)
    {
        freopen("TestPlugin.log", "w", stdout);
        std::puts("Loaded");
    }

    void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API UnityPluginUnload()
    {
        std::puts("Unloaded");
    }

    int UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API TestMain()
    {
        std::puts("Test");
        return 12345;
    }
}
