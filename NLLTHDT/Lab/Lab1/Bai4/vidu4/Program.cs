using System;

namespace vidu4
{
    public class Phanso
    {
        private int tuso;
        private int mauso;
        public void nhap()
        {
            Console.WriteLine("Nhap tu so: ");
            tuso = int.Parse(Console.ReadLine());

            Console.WriteLine("Nhap mau so: ");
            mauso = int.Parse(Console.ReadLine());
        }
        public void show()
        {
            Console.WriteLine("Phan so: {0}/{1}", tuso, mauso);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            
                var phanso = new Phanso();
                phanso.nhap();
                phanso.show();
            
        }
    }
}
