using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace Lab09
{
    public interface INhap
    {
        IEnumerable<Sinhvien> NhapDulieu();
    }
    public class NhapDulieuTuBanphim:INhap
    {
        public IEnumerable<Sinhvien> NhapDulieu()
        {
            var DanhsachSV = new List<Sinhvien>();
            var index = 1;
            while (true)
            {
                Console.WriteLine($"Nhap thong tin sinh vien {index}: ");
                var HoTendem = NhapThongtin("Nhap ho va ten dem: ");
                var Ten = NhapThongtin("Nhap ten: ");
                var MaSV = NhapThongtin("Nhap ma so: ");
                
                DanhsachSV.Add(new Sinhvien(HoTendem, Ten, MaSV));

                Console.Write("Tiep tuc nhap thong tin sinh vien (c/k): ");
                var choose = Console.ReadLine();
                if (choose.ToLower().CompareTo("k") == 0)
                    break;
            }
            return DanhsachSV;
        }
        private string NhapThongtin(string message)
        {
            string str = string.Empty;
            while (string.IsNullOrWhiteSpace(str))
            {
                Console.WriteLine(message);
                str = Console.ReadLine();
            }
            return str;
        }
    }
    public class LopHoc
    {
        private List<Sinhvien> danhSachSV;

        public int SiSoLopHoc { get => danhSachSV.Count; }
        public IEnumerable<Sinhvien> DanhSachSV { get => danhSachSV; }

        public LopHoc()
        {
            this.danhSachSV = new List<Sinhvien>();
        }
        public LopHoc(List<Sinhvien> danhSachSV)
        {
            this.danhSachSV = new List<Sinhvien>(danhSachSV);
        }

        public void Them1SinhVien(Sinhvien sinhVien)
        {
            if (!sinhVien.Validate())
                throw new ArgumentException("Du lieu khong hop le!", nameof(sinhVien));

            danhSachSV.Add(sinhVien);
        }

        public void NhapThongTin(INhap nhap)
        {
            danhSachSV = nhap.NhapDulieu().Cast<Sinhvien>().ToList();
        }

        public IEnumerable<Sinhvien> TimSinhVienTheoHoTen(string hoTen)
          => danhSachSV.FindAll(sv => sv.HovaTen.CompareTo(hoTen) == 0);

        public IEnumerable<Sinhvien> TimSinhVienTheoTen(string ten)
          => danhSachSV.FindAll(sv => sv._Ten.CompareTo(ten) == 0);

        public Sinhvien TimSinhVienTheoMaSo(string maSo)
          => danhSachSV.Find(sv => sv.MaSinhvien.CompareTo(maSo) == 0);

        public bool XoaSinhVienTheoMaSo(string maSo)
        {
            var sinhVien = TimSinhVienTheoMaSo(maSo);
            if (sinhVien is null)
                return false;
            danhSachSV.Remove(sinhVien);
            return true;
        }

        public override string ToString()
        {
            var builder = new StringBuilder();
            builder.AppendLine();

            foreach (var sinhVien in danhSachSV)
            {
                builder.Append(sinhVien.MaSinhvien + " - ");
                builder.AppendLine(sinhVien.HovaTen);
            }
            return builder.ToString();
        }
    }
}
