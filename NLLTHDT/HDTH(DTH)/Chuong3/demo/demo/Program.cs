using System;

namespace Vidu
{
    class Program
    {
        public class PhanSo
        {
            int TuSo; // -1/-5 = 1/5
            int MauSo; //
            bool Dau; // true --> + , false --> - 1/5
            public PhanSo()
            {
                TuSo = 0;
                MauSo = 1;
                Dau = true;

            }
            public PhanSo(int ts)
            {
                if (ts >= 0)
                    Dau = true;
                else
                    Dau = false;

                TuSo = System.Math.Abs(ts);
                MauSo = 1;
            }
            public PhanSo(int TuSo, int MauSo)
            {
                if (TuSo < 0 && MauSo > 0 || TuSo > 0 && MauSo < 0)
                {
                    Dau = false;
                }
                else Dau = true;

                this.TuSo = System.Math.Abs(TuSo);

                this.MauSo = System.Math.Abs(MauSo);
            }
            public PhanSo(PhanSo ob)
            {
                TuSo = ob.TuSo;
                MauSo = ob.MauSo;
                Dau = ob.Dau;
            }
            public static PhanSo NhapPhanSo()
            {
                int Ts, Ms;
                bool KiemTra = false;

                Console.WriteLine("Ban nhap vao một Phan so:");

                do
                {
                    Console.Write("Tu So =");
                    KiemTra = Int32.TryParse(Console.ReadLine(), out Ts);
                }
                while (!KiemTra);

                do
                {
                    Console.Write("Mau So =");
                    KiemTra = Int32.TryParse(Console.ReadLine(), out Ms);
                    if (Ms == 0)
                        KiemTra = false;
                }
                while (!KiemTra);

                return new PhanSo(Ts, Ms);
            }

            public void XuatPhanSo()
            {
                Console.Write("Phân Số: ");
                if (!Dau)
                    Console.Write("-");
                Console.WriteLine(TuSo.ToString() + "/" + MauSo.ToString()); /// 1/-5 -1/5
            }
            public PhanSo Cong(PhanSo Ps)
            {
                if (!Dau)
                    TuSo = -TuSo;
                if (!Ps.Dau)
                    Ps.TuSo = -Ps.TuSo;

                int Ts = this.TuSo * Ps.MauSo + this.MauSo * Ps.TuSo;
                int Ms = this.MauSo * Ps.MauSo;

                return new PhanSo(Ts, Ms);
            }
            /* public PhanSo Cong(PhanSo Ps)
            {
            if (!Dau)
            TuSo = -TuSo;
            if (!Ps.Dau)
            Ps.TuSo = -Ps.TuSo;

            int Ts = this.TuSo * Ps.MauSo + this.MauSo * Ps.TuSo;
            int Ms = this.MauSo * Ps.MauSo;

            return new PhanSo(Ts, Ms);
            }*/
            public static PhanSo operator +(PhanSo Ps1, PhanSo Ps2)
            {
                if (!Ps1.Dau)
                    Ps1.TuSo = -Ps1.TuSo;
                if (!Ps2.Dau)
                    Ps2.TuSo = -Ps2.TuSo;

                int Ts = Ps1.TuSo * Ps2.MauSo + Ps1.MauSo * Ps2.TuSo;
                int Ms = Ps1.MauSo * Ps2.MauSo;

                return new PhanSo(Ts, Ms);
            }
        }
        static void Main(string[] args)
        {
            PhanSo P1 = new PhanSo();
            PhanSo P2 = new PhanSo(-5); // TuSo=5; Mauso =1, dau=false

            P1 = PhanSo.NhapPhanSo();
            P1.XuatPhanSo();

            Console.WriteLine("------------------");
            P2 = PhanSo.NhapPhanSo();
            P2.XuatPhanSo();
            Console.WriteLine("------------------");
            PhanSo P3 = new PhanSo();

            //P3 = P1.Cong(P2);
            P3 = P1 + P2;

            Console.Write("Tong : ");
            P3.XuatPhanSo();
        }
    }
}