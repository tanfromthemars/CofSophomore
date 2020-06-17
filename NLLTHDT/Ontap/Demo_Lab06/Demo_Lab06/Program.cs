using System;
using System.Net.Http.Headers;

namespace Demo_Lab06
{
    class Program
    {
        static void Main()
        {
            TestQueue();
            Console.ReadLine();
            Console.Clear();
            TestDathuc();
        }
        private static void TestQueue()
        {
            int max = 10;
            var queue = new Queue(max);
            for (int i = 0; i < max; i++)
                queue.Enqueue(i);
            Console.WriteLine("So phan tu trong hang doi: " + queue.Count);
            var index = queue.Front;
            while (!queue.isEmpty)
            {
                Console.WriteLine(queue.Dequeue());
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

            Console.WriteLine("Bam phim bat ky de tiep tuc..");
            Console.ReadLine();

            Console.Clear();
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.WriteLine($"Da thuc 1: {a}");
            Console.WriteLine($"Da thuc 2: {b}");
            Console.WriteLine();
            Console.WriteLine("Da thuc 1 + Da thuc 2 = ");
            Console.ResetColor();
            Console.WriteLine((a + b));

            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.WriteLine("da thuc 1 - Da thuc 2 = ");
            Console.ResetColor();
            Console.WriteLine((a - b));

            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.WriteLine("Da thuc 2 - Da thuc 1 = ");
            Console.ResetColor();
            Console.WriteLine((b - a));
        }
    }
}
