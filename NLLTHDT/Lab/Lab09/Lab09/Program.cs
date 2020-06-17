using System;

namespace Lab09
{
    class Program
    {
        static void Main(string[] args)
        {
            var Lop = new LopHoc();
            Lop.NhapThongTin(new NhapDulieuTuBanphim());
            Console.WriteLine($"Si so lop hoc: {Lop.SiSoLopHoc}");
            Console.WriteLine($"Danh sach lop hoc: {Lop}");
        }
    }
}
