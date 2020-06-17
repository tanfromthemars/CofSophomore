using System;

namespace Demo_Lab02_Bai03
{
    public static class Tienich
    {
        public static double TinhLuythua(int Coso, int Somu) => Math.Pow(Coso, Somu);
        public static int TimUCLN(int a, int b)
        {
            if (a == 0 || b == 0) return a + b;
            while (a != b)
            {
                if (a > b) a = a - b;
                else b = b - a;
            }
            return a;
        }
        public static int TimBCNN(int a, int b) => (a * b) / TimUCLN(a, b);
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Tienich.TinhLuythua(2, 3));
            Console.WriteLine($"UCLN cua 20 va 30 la: {Tienich.TimUCLN(20, 30)}");
            Console.WriteLine($"BCNN cua 20 va 30 la: {Tienich.TimBCNN(20, 30)}");
            Console.ReadLine();
        }
    }
}
