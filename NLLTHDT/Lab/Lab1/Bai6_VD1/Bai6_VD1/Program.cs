using System;

namespace Bai6_VD1
{
    class Program
    {
        public class myclass
        {
            int a;
            public myclass(int x)
            {   //Hàm constructor có tham số
                a = x;
            }
            public void show()
            {
                Console.WriteLine("Gia tri a la: {0}", a);
            }
        }
        static void Main(string[] args)
        {
            myclass ob = new myclass(4);    //Truyền giá trị cho tham số hàm constructor
            ob.show();  //Giá trị a là: 4
            Console.ReadLine();
            return;
        }
    }
}
