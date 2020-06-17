using System;

namespace vidu7
{
    class Program
    {
        class TienIch
        {
            public static long Luythua(int CoSo, int SoMu)
            {
                long KetQua = 1;
                for (int i = 0; i < SoMu; i++)
                {
                    KetQua *= CoSo;
                }
                return KetQua;
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
            Console.WriteLine(TienIch.Luythua(3, 3));
            Console.WriteLine(TienIch.USCLN(5, 3));
            Console.ReadLine();
        }
    }
}
