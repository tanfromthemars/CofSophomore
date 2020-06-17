using System;

namespace Vidu6_2
{
    class Program
    {
        class Myclass
        {
            public static int i; //Giá trị mặc định cho i là 0
            public void seti(int n) { i = n; }
            public int geti() { return i; }
        }
        static void Main(string[] args)
        {
            Myclass.i = 100;

            Myclass ob1 = new Myclass();
            Myclass ob2 = new Myclass();

            Console.WriteLine("Gia tri ob1: {0}", ob1.geti());  //ob1: 100
            Console.WriteLine("Gia tri ob2: {0}", ob2.geti());  //ob2: 100
        }
    }
}
