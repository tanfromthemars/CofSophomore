using System;
using System.Text;
using System.IO;

namespace BaiKiemtra_Cuoicung
{
    public class QLGV : IODatabase, Baomat
    {
        private Giaovien[] danhSachGV;
        private int siSo;
        private int MAX;

        public int SiSo { get => siSo; }

        public QLGV()
        {
            MAX = 100;
            siSo = 0;
            danhSachGV = new Giaovien[MAX];
        }

        public void NhapThongTinLopHoc()
        {
            Console.Write("Nhap so luong sinh vien: ");
            siSo = int.Parse(Console.ReadLine());

            for (int i = 0; i < siSo; i++)
            {
                Console.WriteLine("Nhap thong tin sinh vien thu {0}", i + 1);
                Console.Write("Nhap Ho va ten dem: ");
                var hoDem = Console.ReadLine();

                Console.Write("Nhap ten: ");
                var ten = Console.ReadLine();

                Console.Write("Nhap so CMND: ");
                var CMND = Console.ReadLine();

                Console.Write("Nhap MSGV: ");
                var msgv = Console.ReadLine();

                Console.Write("Nhap bo mon day: ");
                var bomon = Console.ReadLine();

                var sv = new Giaovien(hoDem, ten, CMND, msgv, bomon);

                danhSachGV[i] = sv;
            }
        }

        public void Xuat_1_GV(Giaovien gv)
        {
            Console.WriteLine("| {0,-8} | {1,-15} | {2,-8} | {3,-8} | {4,-7} |", gv.MaSo, gv.HoDem, gv.Ten, gv.MSGV, gv.Bomon);
        }
        private void XuatDongKe(int n)
        {
            Console.Write("+");
            for (int i = 0; i < n - 2; i++)
                Console.Write("-");
            Console.Write("+");
            Console.WriteLine();
        }
        public void XuatDanhSachGV()
        {
            XuatDongKe(62);
            Console.WriteLine("| {0,-8} | {1,-15} | {2,-8} | {3,-8} | {4,-7} |", "Ma So", "Ho dem", "Ten", "MSSV", "Lop");
            XuatDongKe(62);
            for (int i = 0; i < siSo; i++)
            {
                Xuat_1_GV(danhSachGV[i]);
            }
            XuatDongKe(62);
        }

        public Giaovien TimKiem_HoTen(string hoDem, string ten)
        {
            for (int i = 0; i < siSo; i++)
            {
                var sv = danhSachGV[i];
                if (sv.HoDem == hoDem && sv.Ten == ten)
                    return sv;
            }

            return null;
        }

        public void TimKiem_TatCa_Ten(string ten)
        {
            Console.WriteLine("Ket qua: ");
            int dem = 0;
            for (int i = 0; i < siSo; i++)
            {
                var sv = danhSachGV[i];
                if (sv.Ten.ToLower() == ten.ToLower())
                {
                    dem++;
                    Xuat_1_GV(sv);
                }
            }

            if (dem == 0) Console.WriteLine("Khong tim thay ket qua!");
        }

        public Giaovien TimKiem_MSGV(string msgv)
        {
            for (int i = 0; i < siSo; i++)
            {
                var gv = danhSachGV[i];
                if (gv.MSGV == msgv)
                    return gv;
            }

            return null;
        }

        public void Read(string fileName)
        {
            using (var reader = File.OpenText(fileName))
            {
                Console.WriteLine("Bat dau doc du lieu tu tap tin...");
                Console.WriteLine("Xong.");

                var line = reader.ReadLine();
                line = Descrypt(line);

                siSo = int.Parse(line);

                for (int i = 0; i < siSo; i++)
                {
                    line = reader.ReadLine();
                    line = Descrypt(line);

                    var parts = line.Split(" ");

                    var hoDem = parts[1];
                    var ten = parts[2];
                    var cmnd = parts[0];
                    var msgv = parts[3];
                    var bomon = parts[4];

                    var gv = new Giaovien(hoDem, ten, cmnd, msgv, bomon);
                    danhSachGV[i] = gv;
                }

                Console.WriteLine("Bat dau giai ma du lieu ...");
                Console.WriteLine("Xong.");
            }
        }

        public void Write(string filename)
        {
            var data = new StringBuilder("");
            data.AppendLine(Encrypt(siSo.ToString()));

            for (int i = 0; i < siSo; i++)
            {
                var gv = danhSachGV[i];
                var line = $"{gv.MaSo} {gv.HoDem} {gv.Ten} {gv.MSGV} {gv.Bomon}";
                var encrypedLine = Encrypt(line);
                data.AppendLine(encrypedLine);
            }

            Console.WriteLine("Ma hoa du lieu ...");
            Console.WriteLine("Xong.");

            File.WriteAllText(filename, data.ToString());

            Console.WriteLine("Ghi du lieu vao tap tin...");
            Console.WriteLine("Xong.");
        }

        public string Mahoa(string text)
        {
            string mahoa = "";
            foreach (var ch in text)
            {
                mahoa += (char)((int)ch + 100);
            }
            return mahoa;
        }

        public string Giaima(string text)
        {
            string giaima = "";
            foreach (var ch in text)
            {
                giaima += (char)((int)ch - 100);
            }
            return giaima;
        }
    }
}
