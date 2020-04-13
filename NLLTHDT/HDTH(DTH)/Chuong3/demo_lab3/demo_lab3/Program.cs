using System;

namespace demo_lab3
{
    class program
    {
        public class tienich
        {
            public static int Nhapsonguyen()
            {
                int so;

                while (!Int32.TryParse(Console.ReadLine(), out so)) ;
                {
                    Console.Write("");
                }
                return so;
            }
        }
        public class tamthuc
        {
            private int a;
            private int b;
            private int c;
            public tamthuc()
            {

            }
            public tamthuc(int a, int b, int c)
            {
                this.a = a;
                this.b = b;
                this.c = c;
            }
            public tamthuc(tamthuc ob)
            {
                this.a = ob.a;
                this.b = ob.b;
                this.c = ob.c;
            }
            public void Nhaptamthuc()
            {
                bool kiemtra = false;
                Console.WriteLine("Nhap cac he so cua tam thuc: ");
                Console.Write("He so A: ");
                kiemtra = Int32.TryParse(Console.ReadLine(), out a);
                while (!kiemtra)
                {
                    Console.WriteLine("Gia tri khong phu hop vui long nhap lai: ");
                    kiemtra = Int32.TryParse(Console.ReadLine(), out a);
                }
                Console.Write("Nhap b: ");
                kiemtra = Int32.TryParse(Console.ReadLine(), out b);
                while (!kiemtra)
                {
                    Console.Write("Gia tri b khong hop le, vui long nhap lai: ");
                    kiemtra = Int32.TryParse(Console.ReadLine(), out b);
                }
                Console.Write("Nhap c: ");
                kiemtra = Int32.TryParse(Console.ReadLine(), out c);
                while (!kiemtra)
                {
                    Console.Write("Gia tri c khong hop le, vui long nhap lai: ");
                    kiemtra = Int32.TryParse(Console.ReadLine(), out c);
                }
            }
            public static tamthuc operator +(tamthuc x, tamthuc y)
            {

            }
            public static explicit operator bool(tamthuc T)
            {
                return (T.b * T.b - 4 * T.a * T.c >= 0);
            }
        }
        static void Main(string[] args)
        {
            tamthuc T1 = new tamthuc();
            tamthuc T2 = new tamthuc();
            tamthuc T3 = new tamthuc();

            T1.Nhaptamthuc();
            T2.Nhaptamthuc();
            Console.WriteLine("Cac tam thuc da nhap: ");
            T1.XUat;
            T2.Xuat;

            Console.WriteLine("Tong hai tam thuc: ");
            T3 = T1 + T2;
            T3.Xuat();

            Console.WriteLine("Tong tam thuc voi 456");
            T3 = T1 + 456;

            Console.WriteLine("Kiem tra tam thuc co nghiem");
            if ((bool)T1)
                Console.WriteLine("Tam thuc co nghiem");
            Console.ReadLine();
        }
    }
}    