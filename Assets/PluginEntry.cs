using System;
using System.Runtime.InteropServices;

public static class PluginEntry
{
    [DllImport("TestPlugin", EntryPoint="TestMain")]
    public static extern int Test();
}
