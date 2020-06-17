using System;
using System.Collections.Generic;
using System.Text;

namespace Lab6
{
    class Dathuc
    {
        private readonly int n;
        private readonly double[] content;
        public int BacDathuc { get => n; }
        public Dathuc(int Baccaonhat)
        {
            this.n = Baccaonhat;
            content = new double[Baccaonhat + 1];
        }
        public Dathuc(params double[] DanhsachHeso)
        {
            this.n = DanhsachHeso.Length - 1;
            content = new double[n + 1];
            var index = 0;
            for (int i = n; i >= 0; i--)
                content[i] = DanhsachHeso[index++];
        }
        public void NhapDathucTuBanphim()
        {
            for (int i = n; i >= 0; i--)
            {
                Console.Write($"Nhap he so cho x^{i}: ");
                content[i] = double.Parse(Console.ReadLine());
            }
        }
        public static Dathuc operator +(Dathuc a, Dathuc b)
        {
            int BacDathucThaphon = (a.BacDathuc < b.BacDathuc) ? a.BacDathuc : b.BacDathuc;
            int BacDathucCaohon = (a.BacDathuc > b.BacDathuc) ? a.BacDathuc : b.BacDathuc;
            var DathucTong = new Dathuc(BacDathucCaohon);
            for (int i = 0; i <= BacDathucThaphon; i++)
            {
                DathucTong.content[i] = a.content[i] + b.content[i];
            }
            if(a.BacDathuc == BacDathucCaohon)
            {
                for (int i = BacDathucThaphon + 1; i <= BacDathucCaohon; i++)
                    DathucTong.content[i] = a.content[i];
            }
            else
            {
                for (int i = BacDathucThaphon + 1; i <= BacDathucCaohon; i++)
                    DathucTong.content[i] = b.content[i];
            }
            return DathucTong;
        }
        public static Dathuc operator -(Dathuc a, Dathuc b)
        {
            int BacDathucThaphon = (a.BacDathuc < b.BacDathuc) ? a.BacDathuc : b.BacDathuc;
            int BacDathucCaohon = (a.BacDathuc > b.BacDathuc) ? a.BacDathuc : b.BacDathuc;
            var DathucHieu = new Dathuc(BacDathucCaohon);
            for (int i = 0; i <= BacDathucThaphon; i++)
            {
                DathucHieu.content[i] = a.content[i] - b.content[i];
            }
            if (a.BacDathuc == BacDathucCaohon)
            {
                for (int i = BacDathucThaphon + 1; i <= BacDathucCaohon; i++)
                    DathucHieu.content[i] = a.content[i];
            }
            else
            {
                for (int i = BacDathucThaphon + 1; i <= BacDathucCaohon; i++)
                    DathucHieu.content[i] = (-b.content[i]);
            }
            return DathucHieu;
        }
        public override string ToString()
        {
            var builder = new StringBuilder();
            for (int i = n; i > 0; i--)
            {
                builder.Append(content[i]);
                builder.Append($"x^[i] + ");
            }
            builder.Append(content[0]);
            return base.ToString();
        }
    }
}