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
            public Phanso(Phanso ob)
            {
                Tuso = ob.Tuso;
                Mauso = ob.Mauso;
            }
        }
        static void Main(string[] args)
        {
            Phanso ob1 = new Phanso(2, 5);
            ob1.show(); //Phân số: 2/5

            Phanso ob2 = new Phanso(ob1);
            ob2.show(); //Phân số: 2/5

            Console.ReadLine();
            return;
        }
    }
}