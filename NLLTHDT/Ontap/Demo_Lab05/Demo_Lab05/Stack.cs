using System;
using System.Collections.Generic;
using System.Text;
using System.Transactions;

namespace Demo_Lab05
{
    public class Stack
    {
        private readonly int max;
        private readonly double[] numbers;
        private int length;
        public bool isEmpty { get => length == 0; }
        public double Top
        {
            get => (isEmpty ? numbers[0] : throw new InvalidOperationException("Stack rong"));
        }
        public bool isFull { get => length == max; }
        public int Length { get => length; }
        public Stack() : this(100) { }
        public Stack(int max)
        {
            if (max <= 0)
                throw new ArgumentException("So phan tu cua stack khong hop le!", nameof(max));

            this.max = max;
            length = 0;
            numbers = new double[max];
        }
        public double Pop()
        {
            if (isEmpty)
                throw new InvalidOperationException("stack rong!");

            var number = numbers[0];

            for (int i = 0; i < length - 1; i++)
                numbers[i] = numbers[i + 1];
            length -= 1;
            return number;
        }
        public void Push(double number)
        {
            if (isFull)
                throw new InvalidOperationException("stack day`!!");
            for (int i = length; i > 0; i--)
                numbers[i] = numbers[i - 1];
            numbers[0] = number;
            length += 1;
        }
    }
}
