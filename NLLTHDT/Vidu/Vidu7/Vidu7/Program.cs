using System;

namespace Vidu7
{
    class Program
    {
        class Tienich
        {
            public static long Luythua(int Coso, int Somu)
            {
                long Ketqua = 1;
                for (int i = 0; i < Somu; i++)
                {
                    Ketqua *= Coso;
                }
                return Ketqua;
            }
        }
        static void Main(string[] args)
        {
            Console.WriteLine(Tienich.Luythua(3, 3));
            Console.ReadLine();
        }
    }
}
