using System;
using System.Collections.Generic;
using System.IO.Pipes;
using System.Text;

namespace Demo_Lab09
{
    public interface INhap
    {
        IEnumerable<Sinhvien> NhapDulieu();
    }
    public class NhapDulieuTuBanphim : INhap
    {
        public IEnumerable<Sinhvien> NhapDulieu()
        {
            var danhsachSV = new List<Sinhvien>();
            var index = 1;
            while (true)
            {
                Console
            }
        }
    }
    class Lophoc
    {
        private List<Sinhvien> danhsachSV;
        public int SisoLophoc { get => danhsachSV.Count; }
        public IEnumerable<Sinhvien> DanhsachSV { get => danhsachSV; }
        public Lophoc()
        {
            this.danhsachSV = new List<Sinhvien>(danhsachSV);
        }
        public void Them1Sinhvien(Sinhvien sinhvien)
        {
            if (!sinhvien.Validate())
                throw new ArgumentException("Du lieu khong hop le", nameof(sinhvien));
            danhsachSV.Add(sinhvien);
        }
        public void NhapThongtin(INhap nhap)
        {
            danhsachSV = nhap.NhapDulieu().Cast<Sinhvien>().ToList();
        }
        public IEnumerable<Sinhvien> TimSinhvienTheoHoten(string hoTen)
            => danhsachSV.FindAll(sv => sv.HoVaTen.CompareTo(hoTen) == 0);
        public IEnumerable<Sinhvien> TimSinhvienTheoTen(string ten)
            => danhsachSV.FindAll(sv => sv.Ten.CompareTo(ten) == 0);
        public Sinhvien TimSinhvienTheoMaso(string maso)
            => danhsachSV.Find(sv => sv.MaSinhvien.CompareTo(maso) == 0);
        public bool XoaSinhvienTheoMaso(string maso)
        {
            var sinhvien = TimSinhvienTheoMaso(maso);
            if (sinhvien is null)
                return false;
            danhsachSV.Remove(sinhvien);
            return true;
        }
        public override string ToString()
        {
            var builder = new StringBuilder();
            builder.AppendLine();
            foreach (var sinhvien in DanhsachSV)
            {
                builder.Append(sinhvien.MaSinhvien + " - ");
                builder.AppendLine(sinhvien.HoVaTen);
            }
            return builder.ToString();
        }
    }
}
