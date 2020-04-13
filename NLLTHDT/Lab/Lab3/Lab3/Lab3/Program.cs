using System;

namespace Lab3
{
    class program
    {
        static class TienIch
        {
            public static int NhapSonguyen()
            {
                int so;
                
                while (!Int32.TryParse(Console.ReadLine(), out so));
                {
                    Console.Write("");
                }
                return so;
            }
        }
        public class Tamthuc
        {
            private int a;
            private int b;
            private int c;
            public Tamthuc()
            {
                a = 0;
                b = 0;
                c = 0;
            }
            public Tamthuc(int a, int b, int c)
            {
                this.a = a;
                this.b = b;
                this.c = c;
            }
            public Tamthuc(Tamthuc ob)
            {
                this.a = ob.a;
                this.b = ob.b;
                this.c = ob.c;
            }
            public void NhapTamthuc()
            {
                Console.WriteLine("Nhap he so a: ");
                this.a = TienIch.NhapSonguyen();
                Console.WriteLine("Nhap he so b: ");
                this.b = TienIch.NhapSonguyen();
                Console.WriteLine("Nhap he so c: ");
                this.c = TienIch.NhapSonguyen();
            }
            public void show()
            {
                if (a == 0)
                {
                    Console.WriteLine("{0}x + {1}", b, c);
                }
                else if (b == 0)
                {
                    Console.WriteLine("{0}x^2 + {1}", a, c);
                }
                else if (c == 0)
                {
                    Console.WriteLine("{0}x^2 + {1}x", a, b);
                }
                else if (a == 0 && b == 0 && c == 0)
                {
                    Console.WriteLine("");
                }
                else
                {
                    Console.WriteLine("{0}x^2 + {1}x + {2}", a, b, c);
                }
                Console.ReadLine();
            }
            public static Tamthuc operator +(Tamthuc ob1, Tamthuc ob2)
            { 
                int A = ob1.a + ob2.a;
                int B = ob1.b + ob2.b;
                int C = ob1.c + ob2.c;

                return new Tamthuc(A, B, C);
            }
            public static Tamthuc operator -(Tamthuc ob1, Tamthuc ob2)
                => new Tamthuc(ob1.a - ob2.a, ob1.b - ob2.b, ob1.c - ob2.c);
            public static explicit operator bool(Tamthuc tamthuc)
            {
                return ((tamthuc.b * tamthuc.b - 4 * tamthuc.a * tamthuc.c) >= 0);
            }
            public static implicit operator Tamthuc (int num)
            {
                if (num < 0)
                    throw new ArgumentException("So nguyen phai lon hon 0!", nameof(num));

                int c = num % 10;
                num /= 10;
                int b = num % 10;
                num /= 10;
                int a = num % 10;

                return new Tamthuc(a, b, c);
            }
            public static Tamthuc operator *(Tamthuc ob1, int num)
                => new Tamthuc(ob1.a * num, ob1.b * num, ob1.c * num);
            public static Tamthuc operator ++(Tamthuc ob1)
                => new Tamthuc(ob1.a + 1, ob1.b + 1, ob1.c + 1);
            public static bool operator ==(Tamthuc ob1, Tamthuc ob2)
            {
                return (ob1.a == ob2.a && ob1.b == ob2.b && ob1.c == ob2.c);
            }
            public static bool operator !=(Tamthuc ob1, Tamthuc ob2)
            {
                return !(ob1 == ob2);
            }
           
        }
        static void Main(string[] args)
        {
            Console.WriteLine("Nhap 2 tam thuc: ");
            var TT1 = new Tamthuc();
            TT1.NhapTamthuc();
            Console.WriteLine("Tam thuc dau tien: ");
            TT1.show();

            Tamthuc TT2 = 123;
            Console.WriteLine("Tam thuc thu hai: ");
            TT2.show();

            Tamthuc TT3 = new Tamthuc();
            TT3 = TT1 + TT2;
            Console.Write("Tong: ");
            TT3.show();
            
            TT3 = TT1 - TT2;
            Console.Write("Hieu: ");
            TT3.show();

            Console.WriteLine("Ep kieu ngam dinh");
            TT3 = 999;
            TT3.show();

            Console.WriteLine("Kiem tra co nghiem khong (ep tuong minh)");
            if ((bool)TT1)
                Console.WriteLine("Tam thuc co nghiem");
            else
                Console.WriteLine("Tam thuc vo nghiem");

            TT3 = TT1 * 456;
            Console.Write("Tich: ");
            TT3.show();

            TT3 = TT1++;
            Console.Write("TT1++: ");
            TT3.show();

            if (TT1 != TT2)
                Console.WriteLine("Tam thuc TT1 khac TT2");
            else
                Console.WriteLine("Tam thuc TT1 bang TT2");
            Console.ReadLine();
            return;
        }
    }
}
