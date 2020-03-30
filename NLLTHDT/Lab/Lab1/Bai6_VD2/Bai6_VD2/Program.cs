using System;

namespace Bai6_VD2
{
    class Program
    {
        public class phanso
        {
            int tuso;
            int mauso;
            public phanso(int x, int y)
            {   //Hàm constructor có tham số
                tuso = x;
                mauso = y;
            }
            public void show()
            {
                Console.WriteLine("Phan so: {0}/{1}", tuso, mauso);
            }
        }
        static void Main(string[] args)
        {
            phanso A = new phanso(1, 4);    //Truyền giá trị cho tham số hàm constructor
            A.show();   //Giá trị a là: 1/4
            Console.ReadLine();
            return;
        }
    }
}
