using System;
using System.Net.Http.Headers;
using System.Text;

namespace Demo_Lab05
{
    class Program
    {
        static void Main()
        {
            //TestStack();
            TestMatran();
            Console.ReadLine();
        }
        private static string LayGiatriHexTuongung(int dec)
        {
            if (dec < 10) return dec.ToString();
            else
            {
                switch(dec)
                {
                    case 10: return "A";
                    case 11: return "B";
                    case 12: return "C";
                    case 13: return "D";
                    case 14: return "E";
                    case 15: return "F";
                }
            }
            throw new ArgumentException("Khong the chuyen doi !!!", nameof(dec));
        }
        private static void ThapphanSangThaplucphan(int dec)
        {
            var stack = new Stack(100);
            while (dec != 0)
            {
                stack.Push(dec % 16);
                dec /= 16;
            }
            Console.WriteLine("Day so thap luc phan tuong ung: ");
            var hex = new StringBuilder();
            while (!stack.isEmpty)
            {
                hex.Append(LayGiatriHexTuongung((int)stack.Pop()));
            }
            Console.WriteLine(hex.ToString());
        }
        private static void ThapphanSangNhiphan(int dec)
        {
            var stack = new Stack(100);
            while (dec != 0)
            {
                stack.Push(dec % 2);
                dec /= 2;
            }
            Console.WriteLine("Day so nhi phan tuong ung: ");
            var builder = new StringBuilder();
            while (!stack.isEmpty)
            {
                builder.Append(stack.Pop());
            }
            Console.WriteLine(builder.ToString());
        }
        private static void TestStack()
        {
            Console.WriteLine("Nhap vao 1 so thap phan: ");
            var dec = int.Parse(Console.ReadLine());

            ThapphanSangNhiphan(dec);
            ThapphanSangThaplucphan(dec);
        }
        private static void TestMatran()
        {
            Console.WriteLine("Nhap ma tran thu nhat: ");
            var mt1 = new Matran();
            mt1.Nhap();
            Console.WriteLine($"Ma tran thu nhat: {mt1}");

            Console.WriteLine("Nhap ma tran thu hai: ");
            var mt2 = new Matran();
            mt2.Nhap();
            Console.WriteLine($"Ma tran thu hai: {mt2}");

            var mt3 = mt1 + mt2;
            Console.WriteLine($"Ma tran 1 + Ma tran 2 = {mt3}");

            System.Console.WriteLine($"Ma tran 1 ban dau: {mt1}");
            mt1 = Matran.Chuyenvi(mt1);
            System.Console.WriteLine($"Ma tan 1 sau khi chuyen vi: {mt1}");
        }
    }
}
