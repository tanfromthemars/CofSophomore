using System;

namespace Lab09
{
    public class Sinhvien
    {
        private readonly string HoTendem;
        private readonly string Ten;
        private readonly string MaSV;
        public string HovaTen { get => this.ToString(); }
        public string Hodem { get => HoTendem; }
        public string _Ten { get => Ten; }
        public string MaSinhvien { get => MaSV; }
        public Sinhvien (string HoTendem, string Ten, string MaSV)
        {
            this.HoTendem = HoTendem;
            this.Ten = Ten;
            this.MaSV = MaSV;
            if (this.Validate() == false)
                throw new ArgumentException("Du lieu khong chinh xac!");
        }
        public bool Validate()
        {
            var flag = true;
            if (string.IsNullOrWhiteSpace(Ten))
                flag = false;
            if (string.IsNullOrWhiteSpace(HoTendem))
                flag = false;
            if (string.IsNullOrWhiteSpace(MaSV))
                flag = false;
            return flag;
        }
        public override string ToString()
            => $"{HoTendem} {Ten}".Trim();
    }
}
