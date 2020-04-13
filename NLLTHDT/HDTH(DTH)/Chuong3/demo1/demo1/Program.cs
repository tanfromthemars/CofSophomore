using System;

namespace demo1
{
    public class Tienich
    {
        public static bool Xetdauphanso(int tuSo, int mauSo)
        {
            bool dau;

            //Xet dau phan so
            // 2/3 va -2/-3 => dau duong
            if (tuSo < 0 && mauSo < 0 || tuSo > 0 && mauSo > 0)
                dau = true; // Dau duong
            else
                dau = false; // Dau am
            return dau;
        }
    }
    public class Phanso
    {
        // -2/3
        private uint _tuSo;
        private uint _mauSo;
        private bool _dau; //true (+), false (-)
        // tuso = -2, mauso = 3
        // -2/3
        public Phanso(int tuSo, int mauSo)
        {
            //Tach dau va luu dau
            _dau = Tienich.Xetdauphanso(tuSo, mauSo);
            
            //Dung tri tuyet doi
            tuSo = Math.Abs(tuSo);
            mauSo = Math.Abs(mauSo);
            
            //Buoc cuoi cung, gan gia tri tuong ung
            _tuSo = (uint)tuSo;
            _mauSo = (uint)mauSo;
        }
        public Phanso()
        {
            _tuSo = 0;
            _mauSo = 1;
            _dau = true;
        }
        public Phanso(int tuSo)
        {
            _dau = Tienich.Xetdauphanso(tuSo, 1);

            tuSo = Math.Abs(tuSo);

            _tuSo = (uint)tuSo;
            _mauSo = 1;
        }
        public Phanso(Phanso ps)
        {
            _tuSo = ps._tuSo;
            _mauSo = ps._mauSo;
            _dau = ps._dau;
        }
        public void Nhapphansotubanphim()
        {
            Console.Write("Nhap vao tu so: ");
            string str = Console.ReadLine();
            //2 -> "2"
            int tuSo = int.Parse(str);

            Console.Write("Nhap vao mau so: ");
            int mauSo = int.Parse(Console.ReadLine());            
            //-2/3
            //Tach dau
            _dau = Tienich.Xetdauphanso(tuSo, mauSo);
            //Lay tri tuyet doi
            tuSo = Math.Abs(tuSo);
            mauSo = Math.Abs(mauSo);
            //Luwu tuong ung
            _tuSo = (uint)tuSo;
            _mauSo = (uint)mauSo;                
        }
        public Phanso Cong(Phanso Phanso_2)
        {
            // -2/3 => _dau = false, _tuSo = 2, _mauSo = 3
            // 1. Gan bien tam
            int tuso_1 = (int)this._tuSo;
            int mauso_1 = (int)this._mauSo;

            int tuSo_2 = (int)Phanso_2._tuSo;
            int mauSo_2 = (int)Phanso_2._mauSo;

            // 2. Gan dau vao phan so de tinh toan
            if (this._dau == false)
                tuso_1 = tuso_1 * -1;
            if (Phanso_2._dau == false)
                tuSo_2 = tuSo_2 * -1;

            // 3. Tinh toan va tra gia tri
            int tuSo_tong = tuso_1 * mauSo_2 + tuSo_2 * mauso_1;
            int mauso_tong = mauso_1 * mauSo_2;

            return new Phanso(tuSo_tong, mauso_tong);
        }
        public string Xuatphanso()
        {
            string str = "";
            // -2/3 => _dau = false, _tuso = 2, _mauso = 3
            //2 => "2"
            str = _tuSo.ToString() + "/" + _mauSo.ToString();
            if (_dau = false)
            {
                str = "-" + str;
            }
            return str;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            var ps1 = new Phanso();
            var ps2 = new Phanso();

            Console.WriteLine("Nhap gia tri phan so 1");
            ps1.Nhapphansotubanphim();

            Console.WriteLine("Nhap gia tri phan so 2");
            ps2.Nhapphansotubanphim();

            Console.WriteLine();

            Console.WriteLine("Phan so 1: {0}", ps1.Xuatphanso());
            Console.WriteLine("Phan so 2: {0}", ps2.Xuatphanso());
            Console.WriteLine();

            var ps_tong = ps1.Cong(ps2);
            Console.WriteLine("{0} + {1} = {2}", ps1.Xuatphanso(), ps2.Xuatphanso(), ps_tong.Xuatphanso());
        }
    }
}
