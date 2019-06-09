using System;

namespace dotnet
{
    class Program
    {
        static void Main(string[] args)
        {
            string filepath = args[0];
            // System.Console.WriteLine(filepath);
            var reader = new Reader();
            reader.Read(filepath);
            reader.PrintDictionary();
            reader.PrintStatistics();
        }
    }
}
