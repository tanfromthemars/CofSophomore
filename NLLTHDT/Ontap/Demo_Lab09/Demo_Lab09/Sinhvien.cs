using System;
using System.Collections.Generic;
using System.Text;

namespace Demo_Lab09
{
    class Sinhvien
    {
        private readonly string HoTenDem;
        private readonly string ten;
        private readonly string maSV;
        public string HoVaTen { get => this.ToString(); }
        public string HoDem { get => HoTenDem; }
        public string Ten { get => ten; }
        public string MaSinhvien { get => maSV; }
        public Sinhvien(string HoTendem, string ten, string maSV)
        {
            this.HoTenDem = HoTenDem;
            this.ten = ten;
            this.maSV = maSV;
            if (this.Validate() == false)
                throw new ArgumentException("Du lieu khong chinh xac!");
        }
        public bool Validate()
        {
            var flag = true;
            if (string.IsNullOrWhiteSpace(ten))
                flag = false;
            if (string.IsNullOrWhiteSpace(HoTenDem))
                flag = false;
            if (string.IsNullOrWhiteSpace(maSV))
                flag = false;
            return flag;
        }
        public override string ToString()
            => $"{HoTenDem} {Ten}".Trim();
    }
}
