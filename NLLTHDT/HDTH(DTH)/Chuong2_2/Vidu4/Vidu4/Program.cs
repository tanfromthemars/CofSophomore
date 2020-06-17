using System;

namespace Vidu4
{
    class Program
    {
        public class Phanso
        {
            int Tuso;
            int Mauso;
            public Phanso()
            {   //Hàm constructor không có tham số
                Tuso = 0;
                Mauso = 1;
            }
            public Phanso(int x)
            {   //Hàm constructor có 1 tham số
                Tuso = x;
                Mauso = 1;
            }
            public Phanso(int x, int y)
            {   //Hàm constructor có 2 tham số
                Tuso = x;
                Mauso = y;
            }
            public void show()
            {
                Console.WriteLine("Phan so: {0}/{1}", Tuso, Mauso);
            }
        }
        static void Main(string[] args)
        {
            Phanso ob1 = new Phanso();
            ob1.show(); //Phân số: 0/1

            Phanso ob2 = new Phanso(5);
            ob2.show(); //Phân số: 5/1

            Phanso ob3 = new Phanso(1, 4);
            ob3.show(); //Phân số: 1/4
            Console.ReadLine();
            return;
        }
    }
}