using System;
using System.Net.Http.Headers;

namespace Demo_Lab03
{
    public class Tamthuc
    {
        private int a;
        private int b;
        private int c;
        public Tamthuc()
        {
            a = b = c = 0;
        }
        public Tamthuc(int a, int b, int c)
        {
            this.a = a;
            this.b = b;
            this.c = c;
        }
        public Tamthuc(Tamthuc obj)
        {
            a = obj.a;
            b = obj.b;
            c = obj.c;
        }
        public void Nhap()
        {
            Console.WriteLine("Nhap he so a: ");
            a = int.Parse(Console.ReadLine());

            Console.WriteLine("Nhap he so b: ");
            b = int.Parse(Console.ReadLine());

            Console.WriteLine("Nhap he so c: ");
            c = int.Parse(Console.ReadLine());
        }
        public override string ToString()
            => $"{a}x^2 + {b}x + {c} = 0";
        public static Tamthuc operator +(Tamthuc t1, Tamthuc t2)
            => new Tamthuc(t1.a + t2.a, t1.b + t2.b, t1.c + t2.c);
        public static Tamthuc operator -(Tamthuc t1, Tamthuc t2)
            => new Tamthuc(t1.a - t2.a, t1.b - t2.b, t1.c - t2.c);
        public static Tamthuc operator *(Tamthuc t, int num)
            => new Tamthuc(t.a * num, t.b * num, t.c * num);
        public static bool operator ==(Tamthuc t1, Tamthuc t2)
            => (t1.a == t2.a) && (t1.b == t2.b) && (t1.c == t2.c);
        public static bool operator !=(Tamthuc t1, Tamthuc t2)
            => !(t1 == t2);
        public static implicit operator Tamthuc(int num)
        {
            var Ketqua = new Tamthuc();
            Ketqua.c = num % 10; num /= 10;
            Ketqua.b = num % 10; num /= 10;
            Ketqua.a = num % 10;
            return Ketqua;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            var t1 = new Tamthuc(1, 2, 3);
            Console.WriteLine(t1 + 123);
        }
    }
}
