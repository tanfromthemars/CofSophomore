using System;

namespace Phanso_Dieukien
{
    public static class Tienich
    {
        public static int Nhapsonguyen(string msg)
        {
            int kq;
            while (true)
            {
                Console.Write(msg);
                bool isValid = int.TryParse(Console.ReadLine(), out kq);
                if (isValid) break;
            }
            return kq;
        }
        public static int Tim_USCLN(int a, int b)
        {
            if (a == 0 || b == 0) return 1;
            //USCLN luon duong
            a = a < 0 ? Math.Abs(a) : a;
            b = b < 0 ? Math.Abs(b) : b;
            while (a != b)
            {
                if (a > b) a = a - b;
                else b = b - a;
            }
            return a;
        }
    }
    public class Phanso
    {
        private int Tuso;
        private int Mauso;
        public int tuso { get => Tuso; }
        public int mauso { get => Mauso; }
        public Phanso()
        {
            Tuso = 0;
            Mauso = 1;
        }
        public Phanso(int tuSo)
        {
            this.Tuso = tuSo;
            this.Mauso = 1;
        }
        public Phanso(int tuSo, int mauSo)
        {
            if (mauSo == 0)
                throw new ArgumentException("Mau so khong the bang 0!", nameof(mauSo));
            this.Tuso = tuSo;
            this.Mauso = mauSo;
        }
        public Phanso (Phanso ps)
        {
            this.Tuso = ps.Tuso;
            this.Mauso = ps.Mauso;
        }
        public void Nhaptubanphim()
        {
            Tuso = Tienich.Nhapsonguyen("Nhap vao tu so: ");
            do
            {
                Mauso = Tienich.Nhapsonguyen("Nhap vao mau so: ");
                if (Mauso == 0)
                    Console.WriteLine("Mau so khong the bang 0!");
            } while (Mauso == 0);
        }
        public static Phanso Rutgonphanso(Phanso ps)
        {
            int ucln = Tienich.Tim_USCLN(ps.Tuso, ps.Mauso);
            var tusorutgon = ps.tuso / ucln;
            var mausorutgon = ps.mauso / ucln;
            if (tusorutgon < 0 && mausorutgon < 0)
            {
                tusorutgon = Math.Abs(tusorutgon);
                mausorutgon = Math.Abs(mausorutgon);
            }
            return new Phanso(tusorutgon, mausorutgon);
        }
        public static Phanso operator +(Phanso ps1) => ps1;
        public static Phanso operator -(Phanso ps1) => new Phanso(-ps1.tuso, ps1.tuso);
        public static Phanso operator +(Phanso ps1, Phanso ps2)
        {
            Phanso tong = new Phanso(ps1.tuso * ps2.tuso + ps1.mauso, ps1.mauso * ps2.mauso);
            return Phanso.Rutgonphanso(tong);
        }
        public static Phanso operator -(Phanso ps1, Phanso ps2)
            => Phanso.Rutgonphanso(ps1 + (-ps2));
        public static Phanso operator *(Phanso ps1, Phanso ps2)
            => Phanso.Rutgonphanso(new Phanso(ps1.tuso * ps2.tuso, ps1.mauso * ps1.mauso));
        public static Phanso operator /(Phanso ps1, Phanso ps2)
        {
            if (ps2.Tuso == 0)
                throw new DivideByZeroException();
            return Phanso.Rutgonphanso(new Phanso(ps1.tuso * ps2.mauso, ps1.mauso * ps2.tuso));
        }
        public static Phanso operator ++(Phanso ps1)
            => Phanso.Rutgonphanso(ps1 + ps1);
        public static bool operator ==(Phanso ps1, Phanso ps2)
        {
            var ps1_toigian = Phanso.Rutgonphanso(ps1);
            var ps2_toigian = Phanso.Rutgonphanso(ps2);
            if (ps1_toigian.tuso == ps2_toigian.tuso && ps1_toigian.mauso == ps2_toigian.mauso)
                return true;
            return false;
        }
        public static bool operator !=(Phanso ps1, Phanso ps2)
        => !(ps1 == ps2);
        public override string ToString()
        {
            if (tuso == 0) return "0";
            if (mauso == 1) return tuso.ToString();
            return $"({this.tuso}/{this.mauso})";
        }
        public override bool Equals(object obj)
        {
            return obj is Phanso so;                
        }
        public override int GetHashCode()
        {
            return HashCode.Combine(Tuso, Mauso, tuso, mauso);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            var ps1 = new Phanso();
            var ps2 = new Phanso();

            Console.WriteLine("Nhap vao phan so thu nhat");
            ps1.Nhaptubanphim();
            Console.WriteLine("Nhap vao phan so thu hai");
            ps2.Nhaptubanphim();

            Console.WriteLine($"Phan so dau tien: ${ps1}");
            Console.WriteLine($"Phan so thu hai: ${ps2}");

            Console.WriteLine(-ps1);
            Console.WriteLine($"{ps1} + {ps2} = {ps1 + ps2}");
            Console.WriteLine($"{ps1} - {ps2} = {ps1 - ps2}");
            Console.WriteLine($"{ps1} * {ps2} = {ps1 * ps2}");
            Console.WriteLine($"{ps1} / {ps2} = {ps1 / ps2}");
            Console.WriteLine($"++{ps1} = {++ps1}");
            Console.WriteLine($"{ps1} == {ps2} ? {ps1 == ps2}");
            Console.WriteLine($"{ps1} != {ps2} ? {ps1 != ps2}");
        }

    }
}
