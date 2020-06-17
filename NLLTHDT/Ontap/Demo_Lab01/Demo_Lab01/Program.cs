using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Demo_Lab01_Bai01
{
    class Program
    {
        class myclass
        {
            int a;
            public void set_a(int num)
            {
                a = num;
            }
            public int get_a()
            {
                return a;
            }
        }
        static void Main(string[] args)
        {
            myclass ob1 = new myclass();
            myclass ob2 = new myclass();
            ob1.set_a(10);
            ob2.set_a(99);
            Console.WriteLine("Gia tri a cua ob1: {0}", ob1.get_a());
            Console.WriteLine("Gia tri a cua ob2: {0}", ob2.get_a());
            Console.ReadLine();
        }
    }
}

/*
 * namespace Demo_Lab01_Bai01
 * {
 * public class MyClass
 * {
 * public int A { get; set; }
 * }
 * class Program
 * {
 * static void Main(string[] args)
 * {
 * var obj1 = new MyClass();
 * var obj2 = newMyClass();
 * 
 * obj1.A = 10;
 * pbj2.A = 99;
 * 
 * Console.WriteLine($"Gia tri cua doi tuong obj1: {obj1.A}");
 * Console.WriteLine($"Gia tri cua doi tuong obj2: {obj2.A}");
 * 
 * Console.ReadLine();
 * }
 * }
 * }
 */