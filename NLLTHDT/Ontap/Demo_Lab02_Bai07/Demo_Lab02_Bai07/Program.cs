using System;

namespace Demo_Lab02_Bai07
{
    public class Phanso
    {
        private readonly int Tuso;
        private readonly int Mauso;
        public Phanso(int Tuso, int Mauso)
        {
            if (Mauso == 0)
                throw new ArgumentException("Mau so phai khac 0", nameof(Mauso));
            this.Tuso = Tuso;
            this.Mauso = Mauso;
        }
        public static Phanso operator +(Phanso a, Phanso b)
        {
            var Tuso = a.Tuso * b.Mauso + b.Tuso * a.Mauso;
            var Mauso = a.Mauso * b.Mauso;
            return new Phanso(Tuso, Mauso);
        }
        public static Phanso operator +(Phanso a) => a;
        public static Phanso operator -(Phanso a, Phanso b)
            => a + (-b);
        public static Phanso operator -(Phanso a) => new Phanso(-a.Tuso, a.Mauso);
        public static Phanso operator *(Phanso a, Phanso b)
            => new Phanso(a.Tuso * b.Tuso, a.Mauso * b.Mauso);
        public static Phanso operator /(Phanso a, Phanso b)
        {
            if (b.Tuso == 0)
                throw new DivideByZeroException();
            return new Phanso(a.Tuso * b.Mauso, b.Tuso * a.Mauso);
        }
        public static bool operator ==(Phanso a, Phanso b)
        {
            var c = a - b;
            return Math.Abs(c.Tuso) == 0;
        }
        public static bool operator !=(Phanso a, Phanso b)
            => !(a == b);
        public static Phanso operator ++(Phanso a)
            => a + new Phanso(1, 1);
        public static Phanso operator --(Phanso a)
            => a - new Phanso(1, 1);
        public override string ToString()
            => $"{Tuso} / {Mauso}";
    }
    class Program
    {
        static void Main(string[] args)
        {
            var a = new Phanso(2, 3);
            var b = new Phanso(3, 4);

            Console.WriteLine($"Phan so a: {a}");
            Console.WriteLine($"Phan so b: {b}");

            Console.WriteLine("-a : {0}", -a);
            Console.WriteLine("++a: {0}", ++a);
            Console.WriteLine("--a: {0}", --a);
            Console.WriteLine("a + b: {0}", a + b);
            Console.WriteLine("a - b: {0}", a - b);
            Console.WriteLine("a * b: {0}", a * b);
            Console.WriteLine("a / b: {0}", a / b);
            Console.WriteLine("a == b: {0}", a == b);
            Console.WriteLine("a != b: {0}", a != b);
        }
    }
}
