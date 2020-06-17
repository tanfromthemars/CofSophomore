using System;
using System.IO;

namespace Demo0605
{
    interface IODatabase
    {
        void Write(string filename);
        void Read(string filename);
    }
    interface Baomat
    {
        void Mahoa();
        void Giaima();
    }
    class Sinhvien
    {
        protected string _Ho, _Ten, _MSSV;
        public Sinhvien()
        {

        }
        public Sinhvien(string Ho, string Ten, string MSSV)
        {
            _Ho = Ho;
            _Ten = Ten;
            _MSSV = MSSV;
        }
        public string Ho
        {
            get { return _Ho; }
            set { _Ho = value; }
        }
        public string Ten
        {
            get { return _Ten; }
            set { _Ten = value; }
        }
        public string MSSV
        {
            get { return _MSSV; }
            set { _MSSV = value; }
        }
        public string HoTen
        {
            get { return _Ho + " " + _Ten; }
        }
    }
    class Lophoc:IODatabase, Baomat
    {
        protected string _Ho, _Ten, _MSSV;
        protected Sinhvien[] mang;
        protected int _Siso, _Max;
        public Lophoc()
        {
            _Max = 100;
            _Siso = 0;
            mang = new Sinhvien[_Max];
        }
        public int Siso
        {
            get { return _Siso; }
        }
        public void Them1SV()
        {
            Console.Write("Nhap ho: ");
            string Ho = Console.ReadLine();
            Console.Write("Nhap ten: ");
            string Ten = Console.ReadLine();
            Console.Write("Nhap MSSV: ");
            string MSSV = Console.ReadLine();
            var sv = new Sinhvien(Ho, Ten, MSSV);
            mang[_Siso] = sv;
            _Siso++;
        }
        public void Xuat()
        {
            for (int i = 0; i < _Siso; i++)
            {
                Console.WriteLine("Sinh vien thu {0}", i + 1);
                Console.WriteLine("MSSV: {0}, Ho va ten: {1}", mang[i].MSSV, mang[i].HoTen);
            }
        }
        public void Timtheoten(string ten)
        {
            int dem = 0;
            for (int i = 0; i < _Siso; i++)
            {
                if (ten == mang[i].Ten)
                {
                    Console.WriteLine("MSSV: {0}, Ho va ten: {1}", mang[i].MSSV, mang[i].HoTen);
                    dem++;
                }
            }
            if (dem == 0)
            {
                Console.WriteLine("Khong tim thay!");
            }
        }
        public void TimtheoMS(string mssv)
        {
            int dem = 0;
            for (int i = 0; i < _Siso; i++)
            {
                if (mssv == mang[i].MSSV)
                {
                    Console.WriteLine("MSSV: {0}, Ho va ten: {1}", mang[i].MSSV, mang[i].HoTen);
                    dem++;
                }
            }
            if (dem == 0)
            {
                Console.WriteLine("Khong tim thay!");
            }
        }
        public void Xoa(string mssv)
        {
            for (int i = 0; i < _Siso; i++)
            {
                if (mssv == mang[i].MSSV)
                {
                    while (i < _Siso)
                    {
                        mang[i].MSSV = mang[i + 1].MSSV;
                        mang[i].Ho = mang[i + 1].Ho;
                        mang[i].Ten = mang[i + 1].Ten;
                        _Siso--;
                    }
                }
            }
        }
        public void Write(string filename)
        {
            FileStream file;
            file = new FileStream(filename, FileMode.OpenOrCreate);
            StreamWriter sw = new StreamWriter(file);
            sw.WriteLine(_Siso);
            for (int i = 0; i < _Siso; i++)
            {
                sw.WriteLine(mang[i].MSSV);
                sw.WriteLine(mang[i].Ho);
                sw.WriteLine(mang[i].Ten);
            }
            sw.Close();
            file.Close();
        }
        public void Read(string filename)
        {
            FileStream file;
            file = new FileStream(filename, FileMode.Open);
            StreamReader sr = new StreamReader(file);
            string siso = sr.ReadLine();
            _Siso = Int32.Parse(siso);
            for (int i = 0; i < _Siso; i++)
            {
                string MSSV = sr.ReadLine();
                string Ho = sr.ReadLine();
                string Ten = sr.ReadLine();
                var sv = new Sinhvien(Ho, Ten, MSSV);
                mang[i] = sv;
            }
            sr.Close();
            file.Close();
        }
        public string MSSV
        {
            get { return _MSSV; }
            set { _MSSV = value; }
        }
        public void Mahoa()
        {
            string KQ = "";
            for (int i = 0; i < _MSSV.Length; i++)
                KQ = KQ + (char)((int)_MSSV[i] + 5);
            _MSSV = KQ;
        }
        public void Giaima()
        {
            string KQ = "";
            for (int i = 0; i < _MSSV.Length; i++)
                KQ = KQ + (char)((int)_MSSV[i] - 5);
            _MSSV = KQ;
        }
    }
    class Program
    {
        static void Main()
        {
            string filename = "d:\\Sinhvien.txt";
            int ss;
            string ten, mssv, xoa;
            Lophoc ctk42 = new Lophoc();
            ctk42.Read(filename);
            ctk42.Xuat();
            Console.ReadLine();
            
            Console.Write("Nhap si so lop: ");
            ss = int.Parse(Console.ReadLine());
            Console.WriteLine("Nhap thong tin sinh vien");
            for (int i = 0; i < ss; i++)
            {
                Console.WriteLine("Sinh vien thu {0}", i + 1);
                ctk42.Them1SV();
            }
            ctk42.Xuat();
            ctk42.Write(filename);
            
            Console.Write("Nhap ten can tim: ");
            ten = Console.ReadLine();
            ctk42.Timtheoten(ten);
            Console.Write("Nhap MSSV can tim: ");
            mssv = Console.ReadLine();
            ctk42.TimtheoMS(mssv);

            Console.Write("Nhap MSSV can xoa: ");
            xoa = Console.ReadLine();
            ctk42.Xoa(xoa);

            ctk42.Xuat();
            Console.ReadLine();
        }
    }
}
