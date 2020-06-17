using System;
using System.IO;

namespace BaiKiemtra_Cuoicung
{
    class Program
    {
        static void Main(string[] args)
        {
            string p0 = Directory.GetParent(Directory.GetCurrentDirectory()).ToString();
            string p1 = Directory.GetParent(p0).ToString();
            string currentPath = Directory.GetParent(p1).ToString();


            string openPath = $"{currentPath}\\data_encrypted.txt";
            string writePath = $"{currentPath}\\data_encrypted.txt";


            Console.WriteLine(currentPath);
            var lop = new QLGV();
            lop.Read(openPath);
            Console.WriteLine("\nBam phim de tiep tuc..."); Console.ReadLine();

            Console.WriteLine();
            Console.WriteLine("DANH SACH LOP");
            Console.WriteLine($"Si so: {lop.SiSo}\n");
            lop.XuatDanhSachGV();

            Console.WriteLine("\nBam phim de tiep tuc..."); Console.ReadLine();
            Console.WriteLine("Nhap ho va ten cua sinh vien de tim kiem: ");
            Console.Write("Nhap ho va ten dem: ");
            var hoDem = Console.ReadLine();
            Console.Write("Nhap ten: ");
            var ten = Console.ReadLine();

            var sv = lop.TimKiem_HoTen(hoDem, ten);
            if (sv != null)
            {
                Console.WriteLine("Thong tin sinh vien tim duoc: ");
                lop.Xuat_1_GV(sv);
            }
            else
            {
                Console.WriteLine("Khong tim thay sinh vien!");
            }

            Console.WriteLine("\nBam phim de tiep tuc..."); Console.ReadLine();
            Console.Write("Nhap ten cua sinh vien de tim kiem tat ca sinh vien cung ten: ");
            ten = Console.ReadLine();
            lop.TimKiem_TatCa_Ten(ten);

            Console.WriteLine("\nBam phim de tiep tuc..."); Console.ReadLine();
            Console.Write("Nhap MSSV cua sinh vien de tim kiem: ");
            var mssv = Console.ReadLine();
            sv = lop.TimKiem_MSGV(mssv);

            if (sv != null)
            {
                Console.WriteLine("Thong tin sinh vien tim duoc: ");
                lop.Xuat_1_GV(sv);
            }
            else
            {
                Console.WriteLine("Khong tim thay sinh vien!");
            }

            Console.WriteLine("\nBam phim de tiep tuc..."); Console.ReadLine();
            lop.Write(writePath);

            Console.ReadLine();
        }
    }
}
