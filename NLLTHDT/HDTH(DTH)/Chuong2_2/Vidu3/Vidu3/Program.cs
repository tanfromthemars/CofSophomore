using System;

namespace Vidu3
{
    class Program
    {
        public class Phanso
        {
            int Tuso;
            int Mauso;
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
            Phanso A = new Phanso(1, 4); //Truyền giá trị cho tham số hàm constructor
            A.show();   //Phân số: 1/4
            Console.ReadLine();
            return;
        }
    }
}