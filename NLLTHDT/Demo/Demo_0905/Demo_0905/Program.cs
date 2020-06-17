using System;

namespace Demo_0905
{
    class Xehoi
    {
        protected int TocDo;
        protected string BienSo;
        protected string HangSX;
        string _ID ;
        public Xehoi (int TD, string BS, string HSX)
        {
            TocDo = TD;
            BienSo = BS;
            HangSX = HSX;
        }
        public string ID
        {
            get { return _ID; }
            set { _ID = value; }
        }
        public void Xuat()
        {
            Console.Write("ID: {0}, Xe: {1}, Bien so: {2}, Toc do: {3} km/h",ID , HangSX, BienSo, TocDo);
        }
    }
    class Xekhach : Xehoi
    {
        int SoHanhkhach;
        string _ID;
        public Xekhach(int TD, string BS, string HSX, int SHK) : base(TD, BS, HSX)
        {
            SoHanhkhach = SHK;
        }
        public string Id
        {
            get { return _ID; }
            set { _ID = value; }
        }
        public new void Xuat()
        {
            base.Xuat();
            Console.WriteLine("{0} cho ngoi", SoHanhkhach);
        }
    }
    class Xetai: Xehoi
    {
        double Trongtai;
        string _ID;
        public Xetai(int TD, string BS, string HSX, double TT) : base(TD, BS, HSX)
        {
            Trongtai = TT;
        }
        public string iD
        {
            get { return _ID; }
            set { _ID = value; }
        }
        public new void Xuat()
        {
            base.Xuat();
            Console.WriteLine(", {0} tan", Trongtai);
        }
    }
    class program
    {
        static void Main(string[] args)
        {          
            Xekhach c = new Xekhach(150, "49A-1293", "Toyota", 24);
            c.ID = "Xe khach";
            c.Xuat();
            Console.ReadLine();

            Xehoi h = new Xehoi(180, "84B-12832", "Asanzo");
            h.ID = "Xe hoi";
            h.Xuat();
            Console.ReadLine();

            Xetai t = new Xetai(90, "12A-2931", "Huyndai", 90);
            t.ID = "Xe tai";
            t.Xuat();
            Console.ReadLine();
        }
    }
}
