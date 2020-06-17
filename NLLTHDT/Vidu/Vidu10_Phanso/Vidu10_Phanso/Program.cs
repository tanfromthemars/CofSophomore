using System;

namespace Vidu10_Phanso
{
    class Phanso
    {
        int Tu, Mau;
        public Phanso()
        {
            Tu = 0;
            Mau = 1;
        }
        public Phanso(int x)
        {
            Tu = x;
            Mau = 1;
        }
        public Phanso(int t, int m)
        {
            Tu = t;
            Mau = m;
        }
        public void XuatPhanso()
        {
            Console.Write("({0}/{1})", Tu, Mau);
        }
        public Phanso Cong(Phanso PS2)
        {
            int TS = Tu * PS2.Mau + Mau * PS2.Tu;
            int MS = Mau * PS2.Mau;
            return new Phanso(TS, MS);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Phanso p1 = new Phanso();   //p1 = 0/1
            p1.XuatPhanso();
            Console.WriteLine();

            Phanso p2 = new Phanso();   //p2 = 3/1
            p2.XuatPhanso();
            Console.WriteLine();

            Console.WriteLine("Nhap tu so:");
            int ts = int.Parse(Console.ReadLine());
            Console.WriteLine("Nhap mau so:");
            int ms = int.Parse(Console.ReadLine());
        }
    }
}
