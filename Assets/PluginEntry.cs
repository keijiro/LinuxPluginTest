using System;
using System.Runtime.InteropServices;

public static class PluginEntry
{
    [DllImport("TestPlugin")]
    public static extern int GetID();

    [DllImport("TestPlugin")]
    static extern void SetPrintFunction(IntPtr function);

    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    public delegate void PrintDelegate(string message);

    public static void SetPrintDelegate(PrintDelegate d)
    {
        SetPrintFunction(Marshal.GetFunctionPointerForDelegate(d));
    }
}
