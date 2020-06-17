using System;

namespace vidu5 
{
    class Program
    {
        public class PhanSo
        {
            int tuso;
            int mauso;
            public PhanSo(int x, int y)
            { //Hàm constructor có 2 tham số
                tuso = x;
                mauso = y;
            }
            public void show()
            {
                Console.WriteLine("Gia tri a la: {0}/{1}", tuso, mauso);
            }
            public PhanSo(PhanSo ob)
            {
                tuso = ob.tuso;
                mauso = ob.mauso;
            }
            public void Nhap(int x, int y)
            {
                tuso = x;
                mauso = y;
                return;
            }
        }

        static void Main(string[] args)
        {
            PhanSo ob1 = new PhanSo(2, 5);
            ob1.show(); //Giá trị a là: 2/5
            PhanSo ob2 = new PhanSo(ob1);
            ob2.show(); //Giá trị a là: 2/5
            ob2.Nhap(3, 6);
            ob2.show();
            Console.ReadLine();
            return;
        }
    }
}