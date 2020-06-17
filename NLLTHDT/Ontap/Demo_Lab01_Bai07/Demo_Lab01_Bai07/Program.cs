using System;

namespace Demo_Lab01_Bai07
{
    public class Phanso
    {
        private int _Tuso;
        private int _Mauso;
        public Phanso()
        {
            _Tuso = 0;
            _Mauso = 1;
        }
        public Phanso(int Tuso)
        {
            _Tuso = Tuso;
            _Mauso = 1;
        }
        public Phanso(int Tuso, int Mauso)
        {
            _Tuso = Tuso;
            _Mauso = Mauso;
        }
        public override string ToString() =>
            $"{_Tuso}/{_Mauso}";
    }
    class Program
    {
        static void Main(string[] args)
        {
            var Phanso_1 = new Phanso();
            Console.WriteLine($"Gia tri cua phan so 1: {Phanso_1}");

            var Phanso_2 = new Phanso(10);
            Console.WriteLine($"Gia tri cua phan so: {Phanso_2}");

            var Phanso_3 = new Phanso(10, 20);
            Console.WriteLine($"Gia tri cu phan so 3: {Phanso_3}");

            Console.ReadLine();
        }
    }
}
