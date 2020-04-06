using System;

namespace phanso
{
    class PhanSo
    {
        int Tu, Mau;
        public PhanSo()
        {
            Tu = 0;
            Mau = 1;
        }
        public PhanSo(int x)
        {
            Tu = x;
            Mau = 1;
        }
        public PhanSo(int t, int m)
        {
            Tu = t;
            Mau = m;
        }
        public void XuatPhanSo()
        {
            Console.Write("({0}/{1})", Tu, Mau);
        }
        public PhanSo Cong(PhanSo PS2)
        {
            int TS = Tu * PS2.Mau + Mau * PS2.Tu;
            int MS = Mau + PS2.Mau;

            return new PhanSo(TS, MS);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            PhanSo p1 = new PhanSo();   //p1 = 0/1
            p1.XuatPhanSo(); Console.WriteLine();

            PhanSo p2 = new PhanSo(3);  //p2 = 3/1
            p2.XuatPhanSo(); Console.WriteLine();

            Console.WriteLine("Nhap tu so: ");
            int Ts = int.Parse(Console.ReadLine());
            Console.WriteLine("Nhap mau so: ");
            int Ms = int.Parse(Console.ReadLine());

            PhanSo p3 = new PhanSo(Ts, Ms);
            p3.XuatPhanSo(); Console.WriteLine();

            p1 = p2.Cong(p3);
            p1.XuatPhanSo();
        }
    }
}
