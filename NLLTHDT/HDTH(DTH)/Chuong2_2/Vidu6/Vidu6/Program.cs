using System;

namespace Vidu6
{
    class Program
    {
        class Myclass
        {
            private static int i;   //Giá trị mặc định cho i là 0
            public void seti(int n) { i = n; }
            public int geti() { return i; }
        }
        static void Main(string[] args)
        {
            Myclass ob1 = new Myclass();
            Myclass ob2 = new Myclass();

            ob1.seti(10);
            Console.WriteLine("Gia tri ob1: {0}", ob1.geti()); //Hiển thị 10
            Console.WriteLine("Gia tri ob2: {0}", ob2.geti()); //Hiển thị 10
        }
    }
}
