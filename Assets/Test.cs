using UnityEngine;

public class Test : MonoBehaviour
{
    void Start()
    {
        PluginEntry.SetPrintDelegate(Print);
        Debug.Log(PluginEntry.GetID());
    }

    static void Print(string message)
    {
    #if UNITY_EDITOR
        Debug.Log(message);
    #else
        System.Console.WriteLine(message);
    #endif
    }
}
