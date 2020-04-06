using System;

namespace vidu6
{
    class Program
    {
        class myclass
        {
            public static int i; //Giá trị mặc định cho i là 0
            public void seti(int n) { i = n; }
            public int geti() { return i; }
        }
        static void Main(string[] args)
        {
            myclass ob1 = new myclass();
            myclass ob2 = new myclass();

            ob1.seti(10);
            Console.WriteLine("Gia tri ob1: {0}", ob1.geti());
            Console.WriteLine("Gia tri ob2: {0}", ob2.geti());
        }
    }
}
