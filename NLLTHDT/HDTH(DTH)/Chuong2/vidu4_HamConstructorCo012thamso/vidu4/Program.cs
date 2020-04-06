using System;

namespace vidu4
{
    class Program
    {
        public class PhanSo
        {
            int tuso;
            int mauso;
            public PhanSo()
            { //Hàm constructor không có tham số
                tuso = 0;
                mauso = 1;
            }
            public PhanSo(int x)
            { //Hàm constructor có 1 tham số
                tuso = x;
                mauso = 1;
            }
            public PhanSo(int x, int y)
            { //Hàm constructor có 2 tham số
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
            PhanSo ob1 = new PhanSo();
            ob1.show(); //Giá trị a là: 0/1
            PhanSo ob2 = new PhanSo(5);
            ob2.show(); //Giá trị a là: 5/1
            PhanSo ob3 = new PhanSo(1, 4); 
            ob3.show();  //Giá trị a là: 1/4
            Console.ReadLine();
            return;
        }
    }
}