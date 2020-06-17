using System;

namespace Demo_Lab01_Bai04
{
    public class Phanso
    {
        private int _Tuso;
        private int _Mauso;
        public void Nhap()
        {
            Console.WriteLine("Nhap vao tu so: ");
            _Tuso = int.Parse(Console.ReadLine());

            Console.WriteLine("Nhap vao mau so: ");
            _Mauso = int.Parse(Console.ReadLine());
        }
        public override string ToString() => $"{_Tuso}/{_Mauso}";
    }
    class Program
    {
        static void Main(string[] args)
        {
            var Phanso = new Phanso();
            Phanso.Nhap();
            Console.WriteLine($"Phan so vua nhap: {Phanso}");
        }
    }
}