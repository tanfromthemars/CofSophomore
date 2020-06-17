using System;

namespace Demo_Final
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = @"";

            QLGV quanly = new QLGV();

            quanly.NhapGV();
            quanly.XuatDSGV();
            quanly.Write(path);

            Console.WriteLine("Ghi du lieu thanh cong!");

            Console.Write("Nhap vao ten can tim kiem: ");
            var ten = Console.ReadLine();
            quanly.TK_Tatca_Ten(ten);

            Console.Write("Nhap vao ma so de tim kiem: ");
            var ms = Console.ReadLine();
            var gv = quanly.TK_1_Maso(ms);
            if (gv is null)
                Console.WriteLine("Khong tim thay giao vien co ma so '{0}'", ms);
            else
                quanly.Xuat_1_GV(gv);

            Console.Write("Nhap vao ho dem de tim kiem: ");
            var hodem = Console.ReadLine();
            Console.Write("Nhap vao ten de tim kiem: ");
            ten = Console.ReadLine();
            gv = quanly.TK_1_HoTen(hodem, ten);
            if (gv is null)
                Console.WriteLine("Khong tim thay giao vien co ho va ten '{0} {1}", hodem, ten);
            else
                quanly.Xuat_1_GV(gv);

            Console.ReadLine();
        }
    }
}
