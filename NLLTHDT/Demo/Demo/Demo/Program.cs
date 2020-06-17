using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Threading.Tasks;

namespace Demo
{
    class Program
    {
        struct Sohang
        {
            public int Hs;
            public int Mu;
        };
        public class Dathuc
        {
            int Sopt;
            Sohang[] DT;
            public Dathuc()
            {
                Sopt = 0;
                DT = new Sohang[100];
            }
            public void ThemSohang(int Heso, int Somu)
            {
                DT[Sopt].Hs = Heso;
                DT[Sopt].Mu = Somu;
                Sopt++;
            }
            public void NhapDathuc()
            {
                int Heso;
                int Somu;
                do
                {
                    Console.WriteLine("Nhap vao he so va so mu, khi ket thuc nhap hs = 0");
                    Heso = Int32.Parse(Console.ReadLine());
                    Somu = Int32.Parse(Console.ReadLine());
                    if (Heso != 0)
                    {
                        ThemSohang(Heso, Somu);
                    }
                } while (Heso != 0);
            }
            public void XuatDathuc()
            {
                Console.WriteLine("Da thuc: ");
                for (int i = 0; i < Sopt; i++)
                    Console.Write("{0}x^{1} + ", DT[i].Hs, DT[i].Mu);
            }
            public int BacDathuc
            {
                get => DT[Sopt].Hs;
            }
            public static Dathuc operator +(Dathuc a, Dathuc b)
            {
                
                int BacDathucThaphon = (a.BacDathuc < b.BacDathuc) ? a.BacDathuc : b.BacDathuc;
                int BacDathucCaohon = (a.BacDathuc > b.BacDathuc) ? a.BacDathuc : b.BacDathuc;
                var DathucTong = new Dathuc();
                for (int i = 0; i <= BacDathucThaphon; i++)
                {
                    DathucTong.DT[i] = a.DT[i] + b.DT[i];
                }
                if (a.BacDathuc == BacDathucCaohon)
                {
                    for (int i = BacDathucThaphon + 1; i <= BacDathucCaohon; i++)
                        DathucTong.DT[i] = a.DT[i];
                }
                else
                {
                    for (int i = BacDathucThaphon + 1; i <= BacDathucCaohon; i++)
                        DathucTong.DT[i] = b.DT[i];
                }
                return DathucTong;
            }
            public static Dathuc operator -(Dathuc a, Dathuc b)
            {

                int BacDathucThaphon = (a.BacDathuc < b.BacDathuc) ? a.BacDathuc : b.BacDathuc;
                int BacDathucCaohon = (a.BacDathuc > b.BacDathuc) ? a.BacDathuc : b.BacDathuc;
                var DathucHieu = new Dathuc();
                for (int i = 0; i <= BacDathucThaphon; i++)
                {
                    DathucHieu.DT[i] = a.DT[i] - b.DT[i];
                }
                if (a.BacDathuc == BacDathucCaohon)
                {
                    for (int i = BacDathucThaphon + 1; i <= BacDathucCaohon; i++)
                        DathucHieu.DT[i] = a.DT[i];
                }
                else
                {
                    for (int i = BacDathucThaphon + 1; i <= BacDathucCaohon; i++)
                        DathucHieu.DT[i] = b.DT[i];
                }
                return DathucHieu;
            }
        }
        static void Main(string[] args)
        {
            Dathuc T1 = new Dathuc();
            T1.NhapDathuc();
            T1.XuatDathuc();
            Dathuc T2 = new Dathuc();
            T2.NhapDathuc();
            T2.XuatDathuc();

            Console.WriteLine("Da thuc 1 + Da thuc 2 = {0} ", (T1 + T2));
            Console.WriteLine("Da thuc 1 - Da thuc 2 = {0}", (T1 - T2));
            Console.ReadLine();
        }
    }
}
