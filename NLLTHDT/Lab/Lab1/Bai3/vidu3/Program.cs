using System;

namespace vidu3
{
    public class Hinhchunhat
    {
        private int chieudai;
        private int chieurong;
        public void SetHCN()
        {
            Console.WriteLine("Nhap chieu dai: ");
            chieudai = int.Parse(Console.ReadLine());

            Console.WriteLine("Nhap chieu rong: ");
            chieurong = int.Parse(Console.ReadLine());
        }
        public int Tinhchuvi() => (chieudai + chieurong) * 2;
        public int Tinhdientich() => chieudai * chieurong;
    }
    class program
    {
        static void Main(string[] args)
        {
            var hcn = new Hinhchunhat();
            hcn.SetHCN();

            Console.WriteLine("Tinh chu vi: {0}", hcn.Tinhchuvi());
            Console.WriteLine($"Tinh dien tich: {hcn.Tinhdientich()}");

            Console.ReadLine();
        }
    }
}