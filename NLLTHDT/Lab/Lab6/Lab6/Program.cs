using System;

namespace Lab6
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                TestDathuc();
                Console.WriteLine("Bam phim bat ky de thoat...");
                Console.ReadLine();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Co loi xay ra! {ex.Message}");
            }
        }
        private static void TestDathuc()
        {
            var a = new Dathuc(2);
            a.NhapDathucTuBanphim();
            Console.WriteLine($"Da thuc 1: {a}");
            var b = new Dathuc(3);
            b.NhapDathucTuBanphim();
            Console.WriteLine($"Da thuc 2: {b}");
            Console.WriteLine("Bam phim bat ky de tiep tuc...");
            Console.ReadLine();

            Console.Clear();
            Console.WriteLine($"Da thuc 1: {a}");
            Console.WriteLine($"Da thuc 2: {b}");
            Console.WriteLine();
            Console.WriteLine("Da thuc 1 + Da thuc 2 = ");
            Console.WriteLine((a + b));
            Console.WriteLine("Da thuc 1 - Da thuc 2 = ");
            Console.WriteLine((a - b));
        }
    }
}
