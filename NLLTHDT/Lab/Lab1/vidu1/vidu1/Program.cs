//Khai báo sử dụng các định danh trong các namespace
using System;


namespace vidu1 //Xác định namespace của chương trình
{
    class Program   //Lớp mặc định chương trình được tạo ra
    {
        //Lớp đối tượng người sử dụng định nghĩa
        class myclass
        {
            int a;
            public void set_a(int num)
            {
                a = num;
            }
            public int get_a()
            {
                return a;
            }
        }
        static void Main(string[] args) //Phương thức main() của chương trình tự động được tạo ra
        {
            //Khai báo các đối tượng mới
            myclass ob1 = new myclass();
            myclass ob2 = new myclass();
            ob1.set_a(10);
            ob2.set_a(99);
            Console.WriteLine("Gia tri a cua doi tuong ob1: {0}", ob1.get_a());
            Console.WriteLine("Gia tri a cua doi tuong ob2: {0}", ob2.get_a());
            Console.ReadLine();
        }
    }
}

//Nhận xét:
//Thành phần của 2 đối tượng ob1 và ob2 giống nhau