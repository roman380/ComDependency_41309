using System;

namespace App
{
    class Program
    {
        [MTAThread]
        static void Main(string[] args)
        {
            LibLib.Obj obj = new LibLib.Obj();
            int a = 2;
            int b = 3;
            int c = obj.Add(a, b);
            Console.WriteLine($"{a} + {b} = {c}");
        }
    }
}
