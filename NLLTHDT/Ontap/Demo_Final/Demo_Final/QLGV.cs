using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Data.Common;

namespace Demo_Final
{
    public class QLGV : IOdatabase, Baomat
    {
        private Giaovien[] danhsachGV;
        private int Tongso;
        private int MAX = 100;
        public QLGV()
        {
            Tongso = 0;
            danhsachGV = new Giaovien[MAX];
        }
        public void NhapGV()
        {
            while (true)
            {
                Console.Write("Nhap vao tong so giao vien: ");
                bool isValid = int.TryParse(Console.ReadLine(), out Tongso);
                if (isValid)
                    break;
            }
            for (int i = 0; i < Tongso; i++)
            {
                Console.WriteLine("Nhap thong tin giao vien thu {0}", i + 1);
                Console.Write("Nhap vao ma so: ");
                var maso = Console.ReadLine();
                Console.Write("Nhap vao ho dem: ");
                var hoDem = Console.ReadLine();
                Console.Write("Nhap vao ten: ");
                var ten = Console.ReadLine();
                Console.Write("Nhap vao mon hoc: ");
                var Monhoc = Console.ReadLine();

                danhsachGV[i] = new Giaovien(maso, hoDem, ten, Monhoc);
            }
        }
        /*
         * public void NhapGV()
         * {
         * while (true)
         * {
         * Console.Write("Nhap vao tong so giao vien: ");
         * bool isValid = int.TryParse(Console.ReadLine(), out Tongso);
         * if (isValid)
         * break;
         * }
         * for (int i = 0; i < Tongso; i++)
         * {
         * Console.WriteLine("Nhap thong tin giao vien thu {0}", i + 1);
         * Console.Write("Nhap vao ma so: ");
         * var maso = Console.ReadLine();
         * Console.Write("Nhap vao ho: ");
         * var ho = Console.ReadLine();
         * Console.Write("Nhap vao ten: ");
         * var ten = Console.ReadLine();
         * Console.Write("Nhap vao bo mon: ");
         * var monhoc = Consol.ReadLine();
         * 
         * danhsachGV[i] = new Giaovien(maso, ho, ten, monhoc);
         * }
         * }
         */
        public void Xuat_1_GV(Giaovien gv)
        {
            Console.WriteLine("{0} | {1} | {2} | {3} | {4}", gv.ID, gv.Maso, gv.HoDem, gv.Ten, gv.TenBomon);
        }
        /*
         * public void Xuat_1_GV(Giaovien gv)
         * {
         * Console.WriteLine("{0} | {1} | {2} | {3} | {4}", gv.ID, gv.Maso, gv.Hodem, gv.Ten, gv.TenBomon);
         * }
         */
        public void XuatDSGV()
        {
            Console.Write("Tong so giao vien trong danh sach: {0}", Tongso);
            Console.WriteLine("{0} | {1} | {2} | {3} | {4}", "ID", "Ma so", "Ho dem", "Ten", "Ten bo mon");
            for (int i = 0; i < Tongso; i++)
                Xuat_1_GV(danhsachGV[i]);
            Console.WriteLine();
        }
        /*
         * public void XuatDSGV()
         * {
         * Console.Write("Tong so giao vien trong danh sach: {0}", Tongso);
         * Console.WriteLine("{0} | {1} | {2} | {3} | {4}", "ID", "Ma so", "Ho dem", "Ten", "Ten bo mon");
         * for (int i = 0; i < Tongso; i++)
         *  Xuat_1_GV(danhsachGV[i]);
         * Console.WriteLine();
         */
        public Giaovien TK_1_HoTen(string hodem, string ten)
        {
            for (int i = 0; i < Tongso; i++)
                if (danhsachGV[i].HoDem == hodem && danhsachGV[i].Ten == ten)
                    return danhsachGV[i];
            return null;
        }
        /*
         * public Giaovien Timkiem_Hoten(string ho, string ten)
         * {
         * for (int i = 0; i < Tongso; i++)
         *  if (danhsachGV[i].Ho == ho && danhsachGV[i].Ten == ten)
         *      return danhsachGV[i];
         * return null;
         */
        public Giaovien TK_1_Maso(string maso)
        {
            for (int i = 0; i < Tongso; i++)
                if (danhsachGV[i].Maso == maso)
                    return danhsachGV[i];
            return null;
        }
        /*
 * public Giaovien Timkiem_Maso(string maso)
 * {
 * for (int i = 0; i < Tongso; i++)
 *  if (danhsachGV[i].maso == maso)
 *      return danhsachGV[i];
 * return null;
 */
        public void TK_Tatca_Ten(string ten)
        {
            Console.WriteLine("Ket qua: ");
            int dem = 0;

            for (int i = 0; i < Tongso; i++)
                if (danhsachGV[i].Ten == ten)
                {
                    Xuat_1_GV(danhsachGV[i]);
                    dem++;
                }
            if (dem == 0)
                Console.WriteLine("Khong tim thay giao vien nao!");
        }
        /*
 * public Giaovien Timkiem_Ten(string ho, string ten)
 * {
 * Concolse.WriteLine("Ket qua: ");
 * int dem = 0;
 * 
 * for (int i = 0; i < Tongso; i++)
 *  if (danhsachGV[i].Ten == ten)
 *  {
 *  Xuat_1_GV(DanhsachGV[i]);
 *  dem++;
 *  }
 *  if (dem == 0)
 * Console.WriteLine("Khong tim thay giao vien nao!");
 * }
 */
        public string Giaima(string data)
        {
            string ChuoiGiaima = "";

            for (int i = 0; i < data.Length; i++)
            {
                int ascii = (int)data[i];
                ascii = ascii - 5;
                ChuoiGiaima += (char)ascii;
            }
            return ChuoiGiaima;
        }
        /*
         * public string Giaima(string data)
         * {
         * string ChuoiGiaima = "";
         * 
         * for (int i = 0; i < data.Length; i++)
         * {
         *  int ascii = (int)data[i];
         *  ascii = ascii - 5;
         *  ChuoiGiaima += (char)ascii;
         * }
         * return ChuoiGiaima;
         */
        public void Read(string filename)
        {
            FileStream fs = new FileStream(filename, FileMode.Open);
            StreamReader reader = new StreamReader(fs);

            Tongso = int.Parse(Giaima(reader.ReadLine()));

            for (int i = 0; i < Tongso; i++)
            {
                var id = Giaima(reader.ReadLine());
                var maso = Giaima(reader.ReadLine());
                var hodem = Giaima(reader.ReadLine());
                var ten = Giaima(reader.ReadLine());
                var tenBM = Giaima(reader.ReadLine());

                danhsachGV[i] = new Giaovien(hodem, ten, maso, tenBM);
            }
            reader.Close();
            fs.Close();
        }
        /*
         * public void Read(string filename)
         * {
         *  FileStream fs = new FileStream(filename, FileMode.Open);
         *  StreamReader reader = new StreamReader(fs);
         *  
         *  Tongso = int.Parse(Giaima(reader.ReadLine()));
         *  
         *  for (int i = 0; i < Tongso; i++)
         *  {
         *      var id = Giaima(reader.ReadLine()));
         *      var maso = Giaima(reader.ReadLine()));
         *      var hodem = Giaima(reader.ReadLine()));
         *      var ten = Giaima(reader.ReadLine()));
         *      var tenBM = Giaima(reader.ReadLine()));
         *      
         *      danhsachGV[i] = new Giaovien(hodem, ten, maso, tenBM);
         *  }
         *  reader.Close();
         *  fs.Closer();
         * }
         */
        public string Mahoa(string data)
        {
            string ChuoiMahoa = "";

            for (int i = 0; i < data.Length; i++)
            {
                int ascii = (int)data[i];
                ascii = ascii + 5;
                ChuoiMahoa += (char)ascii;
            }
            return ChuoiMahoa;
        }
        /*
         * public string Mahoa(string data)
         * {
         * string ChuoiMahoa = "";
         * 
         * for (int i = 0; i < data.Length; i++)
         * {
         *  int ascii = (int)data[i];
         *  ascii = ascii + 5;
         *  ChuoiMahoa += (char)ascii;
         * }
         * return ChuoiMahoa;
         */
        public void Write(string filename)
        {
            FileStream fs = new FileStream(filename, FileMode.OpenOrCreate);
            StreamWriter writer = new StreamWriter(fs);

            writer.WriteLine(Mahoa(Tongso.ToString()));

            for (int i = 0; i < Tongso; i++)
            {
                var gv = danhsachGV[i];
                writer.WriteLine(Mahoa(gv.ID));
                writer.WriteLine(Mahoa(gv.Maso));
                writer.WriteLine(Mahoa(gv.HoDem));
                writer.WriteLine(Mahoa(gv.Ten));
                writer.WriteLine(Mahoa(gv.TenBomon));
            }
            writer.Close();
            fs.Close();
        }
        /*
         * public void Write(string filename)
         * {
         *  FileStream fs = new FileStream(filename, FileMode.OpenOrCreate);
         *  StreamWriter writer = new StreamWriter(fs);
         *  
         *  writer.WriteLine(Mahoa(Tongso.ToString()));
         *  
         *  for (int i = 0; i < Tongso; i++)
         *  {
         *      var gv = danhsachGV[i];
         *      writer.WrireLine(Mahoa(gv.ID));
         *      writer.WrireLine(Mahoa(gv.Maso));
         *      writer.WrireLine(Mahoa(gv.Hodem));
         *      writer.WrireLine(Mahoa(gv.Ten));
         *      writer.WrireLine(Mahoa(gv.TenBM));
         *  }
         *  writer.Close();
         *  fs.Close();
         * }
         */
    }
}
