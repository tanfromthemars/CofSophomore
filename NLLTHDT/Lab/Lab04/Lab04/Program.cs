using System;

namespace Lab04
{
    class Program
    {
        class Sophuc
        {
            public double Phanthuc;
            public double Phanao;

            public Sophuc()
            {

            }
            public Sophuc(double thuc, double ao)
            {
                this.Phanthuc = thuc;
                this.Phanao = ao;
            }
            public Sophuc(Sophuc a)
            {
                this.Phanthuc = a.Phanthuc;
                this.Phanao = a.Phanao;
            }
            public void Nhap_Sophuc()
            {
                Console.Write("Nhap phan thuc: ");
                this.Phanthuc = double.Parse(Console.ReadLine());
                while(this.Phanthuc == 0)
                {
                    Console.WriteLine("So thuan ao~!");
                    Console.ReadLine();
                }
                Console.Write("Nhap phan ao: ");
                this.Phanao = double.Parse(Console.ReadLine());
                while(this.Phanao == 0)
                {
                    Console.WriteLine("So thuc!");
                    Console.ReadLine();
                }
            }
            public override string ToString()
            {
                if (this.Phanao < 0)
                    return this.Phanthuc.ToString() + " + " + Math.Abs(this.Phanao).ToString() + "i";
                return this.Phanthuc.ToString() + " + " + this.Phanao.ToString() + "i";
            }
            public static string Cong(Sophuc a, Sophuc b)
            {
                double Phanthuc = a.Phanthuc + b.Phanthuc;
                double Phanao = a.Phanao + b.Phanao;
                if (Phanao < 0)
                    return Phanthuc.ToString() + " - " + Math.Abs(Phanao).ToString() + "i";
                return Phanthuc.ToString() + " + " + Phanao.ToString() + "i";
            }
            public static string Tru(Sophuc a, Sophuc b)
            {
                double Phanthuc = a.Phanthuc - b.Phanthuc;
                double Phanao = a.Phanao - b.Phanao;
                if (Phanao < 0)
                    return Phanthuc.ToString() + " - " + Math.Abs(Phanao).ToString() + "i";
                return Phanthuc.ToString() + " + " + Phanao.ToString() + "i";
            }
            public static string Nhan(Sophuc a, Sophuc b)
            {
                double Phanthuc = a.Phanthuc * b.Phanthuc - a.Phanao * b.Phanao;
                double Phanao = a.Phanthuc * b.Phanao + a.Phanao * b.Phanthuc;
                if (Phanao < 0)
                    return Phanthuc.ToString() + " - " + Math.Abs(Phanao).ToString() + "i";
                return Phanthuc.ToString() + " + " + Phanao.ToString() + "i";
            }
            public static string Chia(Sophuc a, Sophuc b)
            {
                Sophuc lienhop_b = new Sophuc();
                return Nhan(a, lienhop_b) + "\n-------------\n" + Nhan(b, b);
            }
            public static bool operator ==(Sophuc a, Sophuc b)
            {
                return (a.Phanao * b.Phanthuc == a.Phanthuc * b.Phanao);
            }
            public static bool operator !=(Sophuc a, Sophuc b)
            {
                return !(a == b);
            }
        }
        static void Main(string[] args)
        {
            Sophuc a = new Sophuc();
            Console.WriteLine("Nhap so phuc dau tien:");
            a.Nhap_Sophuc();

            Sophuc b = new Sophuc();
            Console.WriteLine("Nhap so phuc thu hai:");
            b.Nhap_Sophuc();

            Console.WriteLine("(" + a.ToString() + ")" + " + " + "(" + b.ToString() + ")" + " = " + Sophuc.Cong(a, b));
            Console.WriteLine("(" + a.ToString() + ")" + " - " + "(" + b.ToString() + ")" + " = " + Sophuc.Tru(a, b));
            Console.WriteLine("(" + a.ToString() + ")" + " * " + "(" + b.ToString() + ")" + " = " + Sophuc.Nhan(a, b));
            Console.WriteLine("(" + a.ToString() + ")" + " / " + "(" + b.ToString() + ")" + " = " + Sophuc.Cong(a, b));
            Console.WriteLine("Hai so phuc co bang nhau khong? {0}", a == b);
        }
    }
}
