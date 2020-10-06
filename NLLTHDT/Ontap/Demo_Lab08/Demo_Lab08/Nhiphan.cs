﻿using System;
using System.Linq;
using System.Collections;
using System.Text;
using System.Net;

namespace Demo_Lab08
{
    public class Nhiphan
    {
        private readonly int[] bin;
        private static readonly int soBit = 8;
        public IEnumerable Bin { get => bin; }
        public int GetDecimal
        {
            get
            {
                int dec = 0;
                for (int i = soBit - 2; i >= 0; i--)
                    dec += (int)(bin[i] * Math.Pow(2, 1));

                if (bin[soBit - 1] == 1)
                    return -dec;
                return dec;
            }
        }
        public Nhiphan(int num)
        {
            bin = new int[soBit];
            bin = Parse(num).Cast<int>().ToArray();
        }
        public static IEnumerable Parse(int dec)
        {
            var bin = new int[soBit];
            var stack = new Stack();

            if (dec < 0)
            {
                bin[soBit - 1] = 1;
                dec = Math.Abs(dec);
            }

            while (dec != 0)
            {
                stack.Push(dec % 2);
                dec /= 2;
            }
            var count = stack.Count;
            if (count >= soBit)
                throw new ArgumentException("So thap phan qua lon!", nameof(dec));

            for (int i = count - 1; i >= 0; i--)
            {
                bin[i] = (int)stack.Pop();
            }
            return bin;
        }
        public static Nhiphan operator +(Nhiphan a, Nhiphan b)
        {
            var dec1 = a.GetDecimal;
            var dec2 = b.GetDecimal;

            var sum = dec1 + dec2;

            if (sum < -127 || sum > 127)
                throw new InvalidOperationException("Tran so nhi phan!");
            return new Nhiphan(sum);
        }
        public static Nhiphan operator -(Nhiphan a, Nhiphan b)
        {
            var dec1 = a.GetDecimal;
            var dec2 = b.GetDecimal;

            var sub = dec1 - dec2;

            if (sub < -127 || sub > 127)
                throw new InvalidOperationException("Tran so nhi phan!");
            return new Nhiphan(sub);
        }
        public static bool operator ==(Nhiphan a, Nhiphan b)
        {
            var isEqual = true;
            for (int i = 0; i < soBit; i++)
                if (a.bin[i] != b.bin[i])
                    isEqual = false;
            return isEqual;
        }
        public static bool operator !=(Nhiphan a, Nhiphan b)
            => !(a == b);
        public override string ToString()
        {
            var builder = new StringBuilder();
            for (int i = soBit - 1; i >= 0; i--)
                builder.Append(bin[i]);
            return builder.ToString();
        }
    }
}