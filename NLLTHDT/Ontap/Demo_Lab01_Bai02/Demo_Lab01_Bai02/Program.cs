using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Demo_Lab01_Bai02
{
    class Program
    {
        class myclass
        {
            public int a;
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
            ob1.a = 10;
            ob2.set_a(99);
            Console.WriteLine("Gia tri a cua ob1 la: {0}", ob1.a);
            Console.WriteLine("Gia tri a cua ob2 la: {0}", ob2.get_a());
            Console.ReadLine();
            return;
        }
    }
}
/*
 * namespace Demo_Lab01_Bai01
 * {
 * public class MyClass
 * {
 * public int A;
 * public void Set_a(int num) => A = num;
 * public int Get_A() => A;
 * }
 * class Program
 * {
 * static void Main(string[] args)
 * {
 * var obj1 = new MyClass();
 * var obj2 = new MyClass();
 * 
 * obj1.A = 10;
 * obj2.Set_A(99);
 * 
 * Console.WriteLine($"Gia tri a cua obj1 la: {obj1.A}");
 * Console.WriteLine($"Gia tri a cua obj2 la: {obj2.Get_A}");
 * 
 * Console.ReadLine();
 * }
 * }
 * }
 */