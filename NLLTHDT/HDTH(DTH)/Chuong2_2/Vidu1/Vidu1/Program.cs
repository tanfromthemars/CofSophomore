using System;

namespace Vidu1
{
    class Program
    {
        public class Myclass
        {
            int a;
            public Myclass()
            {   //Hàm constructor là một thành phần của lớp
                a = 10;
            }
            public void Show()
            {
                Console.WriteLine("Gia tri a la: {0}", a);
            }
        }
        static void Main(string[] args)
        {
            Myclass ob = new Myclass();
            ob.Show();  //Giá trị a là 10
            Console.ReadLine();
            return;
        }
    }
}