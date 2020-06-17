using System;

namespace Demo_Lab01_Bai03
{
    public class HCN
    {
        private int _ChieuDai;
        private int _ChieuRong;
        public void SetHCN()
        {
            Console.WriteLine("Nhap chieu dai: ");
            _ChieuDai = int.Parse(Console.ReadLine());

            Console.WriteLine("Nhap chieu rong: ");
            _ChieuRong = int.Parse(Console.ReadLine());
        }
        public int TinhChuvi() => (_ChieuDai + _ChieuRong) * 2;
        public int TinhDientich() => _ChieuDai * _ChieuRong;
    }
    class Program
    {
        static void Main(string[] args)
        {
            var hcn = new HCN();
            hcn.SetHCN();
            Console.WriteLine($"Chu vi HCN: {hcn.TinhChuvi()}");
            Console.WriteLine($"Dien tich HCN: {hcn.TinhDientich()}");

            Console.ReadLine();
        }
    }
}