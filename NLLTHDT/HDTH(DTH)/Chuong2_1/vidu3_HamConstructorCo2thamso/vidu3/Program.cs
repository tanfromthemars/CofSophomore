using System;

namespace vidu3
{
    class Program
    {
        public class PhanSo
        {
            int tuso;
            int mauso;
            public PhanSo(int x, int y)
            { //Hàm constructor có tham số
                tuso = x;
                mauso = y;
            }
            public void show()
            {
                Console.WriteLine("Gia tri a la: {0}/{1}", tuso, mauso);
            }
        }

        static void Main(string[] args)
        {
            PhanSo ob = new PhanSo(1, 4);    //truyền giá trị cho tham số hàm constructor
            ob.show();  //Giá trị a là: 1/4
            Console.ReadLine();
            return;
        }
    }
}
