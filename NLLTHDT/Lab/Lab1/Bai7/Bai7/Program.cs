using System;

namespace Bai7
{
    class Program
    {
        public class phanso
        {
            int tuso;
            int mauso;
            public phanso()
            {   //Hàm constructor không có tham số
                tuso = 0;
                mauso = 1;
            }
            public phanso(int x)
            {   //Hàm constructor có 1 tham số
                tuso = x;
                mauso = 1;
            }
            public phanso(int x, int y)
            {   //Hàm constructor có 2 tham số
                tuso = x;
                mauso = y;
            }
            public void show()
            {
                Console.WriteLine("{0}/{1}", tuso, mauso);
            }
            static void Main(String[] args)
            {
                phanso ob1 = new phanso();
                ob1.show();
                phanso ob2 = new phanso(1);
                ob2.show();
                phanso ob3 = new phanso(1, 6);
                ob3.show();
                Console.ReadLine();
                return;
            }
        }
    }
}
