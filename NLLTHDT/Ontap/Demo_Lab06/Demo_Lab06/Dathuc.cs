using System;
using System.Collections.Generic;
using System.Net.Http.Headers;
using System.Text;

namespace Demo_Lab06
{
    public class Dathuc
    {
        private readonly int n;
        private readonly double[] content;
        public int BacDathuc { get => n; }
        public Dathuc(int BacCaonhat)
        {
            this.n = BacCaonhat;
            content = new double[BacCaonhat + 1];
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
                Console.Write($"Nhap he so cua x^{i} >> ");
                content[i] = double.Parse(Console.ReadLine());
            }
        }
        public static Dathuc operator +(Dathuc a, Dathuc b)
        {
            int BacDathucCaohon = (a.BacDathuc > b.BacDathuc) ? a.BacDathuc : b.BacDathuc;
            int BacDathucThaphon = (a.BacDathuc < b.BacDathuc) ? a.BacDathuc : b.BacDathuc;
            var DathucTong = new Dathuc(BacDathucCaohon);

            for (int i = 0; i <= BacDathucThaphon; i++)
            {
                DathucTong.content[i] = a.content[i] + b.content[i];
            }

            if (a.BacDathuc == BacDathucCaohon)
            {
                for (int i = BacDathucThaphon + 1; i < BacDathucCaohon; i++)
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
            int BacDathucCaohon = (a.BacDathuc > b.BacDathuc) ? a.BacDathuc : b.BacDathuc;
            int BacDathucThaphon = (a.BacDathuc < b.BacDathuc) ? a.BacDathuc : b.BacDathuc;
            var DathucTong = new Dathuc(BacDathucCaohon);

            for (int i = 0; i <= BacDathucThaphon; i++)
            {
                DathucTong.content[i] = a.content[i] - b.content[i];
            }

            if (a.BacDathuc == BacDathucCaohon)
            {
                for (int i = BacDathucThaphon + 1; i < BacDathucCaohon; i++)
                    DathucTong.content[i] = a.content[i];
            }
            else
            {
                for (int i = BacDathucThaphon + 1; i <= BacDathucCaohon; i++)
                    DathucTong.content[i] = (-b.content[i]);
            }
            return DathucTong;
        }
        public static bool operator ==(Dathuc a, Dathuc b)
        {
            if (a.BacDathuc != b.BacDathuc) return false;

            for (int i = 0; i <= a.BacDathuc; i++)
                if (a.content[i] != b.content[i])
                    return false;
            return true;
        }
        public static bool operator !=(Dathuc a, Dathuc b)
            => !(a == b);
        public override string ToString()
        {
            var builder = new StringBuilder();
            for (int i = n; i > 0; i--)
            {
                builder.Append(content[i]);
                builder.Append($"x^{i} + ");
            }
            builder.Append(content[0]);
            return builder.ToString();
        }
    }
}
