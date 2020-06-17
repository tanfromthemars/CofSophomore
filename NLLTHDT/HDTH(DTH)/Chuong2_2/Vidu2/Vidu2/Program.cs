using System;
namespace Vidu2
{
    class program
    {
        public class Myclass
        {
            int a;
            public Myclass(int x)
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
            Myclass ob = new Myclass(4); //Truyền giá trị cho tham số có hàm constructor
            ob.show();  //Giá trị a là 4
            Console.ReadLine();
            return;
        }
    }
}