using System;

namespace Demo_Lab02_Bai01
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
        public Phanso(Phanso obj)
        {
            _Tuso = obj._Tuso;
            _Mauso = obj._Mauso;
        }
        public override string ToString()
        => $"{_Tuso}/{_Mauso}";
    }
    class Program
    {
        static void Main(string[] args)
        {
            var ps1 = new Phanso(2, 5);
            Console.WriteLine($"Gia tri cua phan so 1: {ps1}");
            var ps2 = new Phanso(ps1);
            Console.WriteLine($"Gia tri cua phan so 2: {ps2}");
            Console.ReadLine();
        }
    }
}
