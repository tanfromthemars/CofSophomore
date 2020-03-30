using System;

namespace vidu1
{
    class Program
    {
        public class myclass
        {
            int a;
            public myclass()
            {   //Hàm constructor là một thành phần của lớp
                a = 10;
            }
            public void show()
            {
                Console.WriteLine("Gia tri a la: {0}", a);
            }
        }
        static void Main(string[] args)
        {
            myclass ob = new myclass();
            ob.show();  //Gia tri a la 10
            Console.ReadLine();
            return;
        }
    }
}
