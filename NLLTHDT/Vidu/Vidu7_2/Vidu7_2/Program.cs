using System;

namespace Vidu7_2
{
    class Program
    {
        static class Tienich
        {
            public static long LuyThua(int Coso, int Somu)
            {
                long Ketqua = 1;
                for (int i = 0; i < Somu; i++)
                {
                    Ketqua *= Coso;
                }
                return Ketqua;
            }
            public static int USCLN(int a, int b)
            {
                a = Math.Abs(a);
                b = Math.Abs(b);
                while (a != b)
                {
                    if (a > b)
                        a = a - b;
                    if (a < b)
                        b = b - a;
                }
                return a;
            }
        }
        static void Main(string[] args)
        {
            Console.WriteLine(Tienich.LuyThua(3, 3));
            Console.WriteLine(Tienich.USCLN(5, 3));
        }
    }
}
