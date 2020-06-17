using System;
using System.Linq;
using System.Collections;
using System.Text;

namespace Lab08_Bai1
{
    public class ConsoNhiphan
    {
        private readonly int[] bin;
        private static readonly int Sobit = 8;
        public IEnumerable Bin { get => bin; }
        public int GetDecimal
        {
            get
            {
                int dec = 0;
                for (int i = Sobit - 2; i >= 0; i--)
                    dec += (int)(bin[i] * Math.Pow(2, i));
                if (bin[Sobit - 1] == 1) return -dec;
                return dec;
            }
        }
        public ConsoNhiphan(int num)
        {
            bin = new int[Sobit];
            bin = Parse(num).Cast<int>().ToArray();
        }
        public static IEnumerable Parse(int dec)
        {
            var bin = new int[Sobit];
            var stack = new Stack();

            if (dec < 0)
            {
                bin[Sobit - 1] = 1;
                dec = Math.Abs(dec);
            }
            while (dec != 0)
            {
                stack.Push(dec % 2);
                dec /= 2;
            }
            var count = stack.Count;
            if (count >= Sobit)
                throw new ArgumentException("So thap phan qua lon!", nameof(dec));
            for (int i = count - 1; i >= 0; i--)
            {
                bin[i] = (int)stack.Pop();
            }
            return bin;
        }
        public static ConsoNhiphan operator +(ConsoNhiphan a, ConsoNhiphan b)
        {
            var dec1 = a.GetDecimal;
            var dec2 = b.GetDecimal;

            var sum = dec1 + dec2;

            if (sum < -127 || sum > 127) throw new InvalidOperationException("Tran so nhi phan!");
            return new ConsoNhiphan(sum);
        }
        public static ConsoNhiphan operator -(ConsoNhiphan a, ConsoNhiphan b)
        {
            var dec1 = a.GetDecimal;
            var dec2 = b.GetDecimal;

            var sub = dec1 - dec2;

            if (sub < -127 || sub > 127) throw new InvalidOperationException("Tran so nhi phan!");
            return new ConsoNhiphan(sub);
        }
        public static bool operator ==(ConsoNhiphan a, ConsoNhiphan b)
        {
            var isEqual = true;
            for (int i = 0; i < Sobit; i++)
                if (a.bin[i] != b.bin[i])
                    isEqual = false;
            return isEqual;
        }
        public static bool operator !=(ConsoNhiphan a, ConsoNhiphan b)
        => !(a == b);
        public override string ToString()
        {
            var builder = new StringBuilder();
            for (int i = Sobit - 1; i >= 0; i--)
                builder.Append(bin[i]);
            return builder.ToString();
        }
    }
    public class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Nhap vao 1 so thap phan: ");
            var dec1 = Convert.ToInt32(Console.ReadLine());
            var bin1 = new ConsoNhiphan(dec1);
            Console.WriteLine("Chuoi nhi phan tuong ung: ");
            Console.WriteLine(bin1);

            Console.WriteLine("Nhap vao 1 so thap phan: ");
            var dec2 = Convert.ToInt32(Console.ReadLine());
            var bin2 = new ConsoNhiphan(dec2);
            Console.WriteLine("Chuoi nhi phan tuong ung: ");
            Console.WriteLine(bin2);

            var sum = bin1 + bin2;
            Console.WriteLine($"{bin1} + {bin2} = {sum}");
            Console.WriteLine($"Gia tri thap phan tuong ung: {sum.GetDecimal}");

            var sub = bin1 - bin2;
            Console.WriteLine($"{bin1} - {bin2} = {bin1 - bin2}");
            Console.WriteLine($"Gia tri thap phan tuong ung: {sub.GetDecimal}");
        }
    }
}
