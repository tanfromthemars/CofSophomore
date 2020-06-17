using System;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Demo_0405
{
    public abstract class Hinhhoc
    {
        public abstract double Dientich();
    }
    public class Hinhtron:Hinhhoc
    {
        double Bankinh;
        public Hinhtron(double bk)
        {
            Bankinh = bk;
        }
        public override double Dientich()
        {
            Console.WriteLine("Dien tich hinh tron: ");
            return Bankinh * Bankinh * 3.1416;
        }
    }
    public class Hinhchunhat:Hinhhoc
    {
        double Dai, Rong;
        public Hinhchunhat(double d, double r)
        {
            Dai = d;
            Rong = r;
        }
        public override double Dientich()
        {
            Console.WriteLine("Dien tich hinh chu nhat: ");
            return Dai*Rong;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Hinhhoc[] hinh = { new Hinhtron(5), new Hinhtron(4), new Hinhchunhat(1, 2), new Hinhchunhat(3, 4), new Hinhchunhat(5, 6) };
            Console.WriteLine("Cac hinh co dien tich la: ");
            for (int i = 0; i < 5; i++)
                Console.WriteLine("{0}", hinh[i].Dientich());
            Console.ReadLine();
        }
    }
}
