using System;

namespace vidu2
{
    class Program
    {
        //Lớp đối tượng người sử dụng định nghĩa
        class myclass
        {
            public int a;
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
            ob1.a(10);
            ob2.set_a(99);
            Console.WriteLine("Gia tri a cua doi tuong ob1: {0}", ob1.a());
            Console.WriteLine("Gia tri a cua doi tuong ob2: {0}", ob2.get_a());
            Console.ReadLine();
        }
    }
}

//nhận xét:
//sử dụng public nghĩa là object của class có thể truy cập và sửa đổi dữ liệu bên ngoài class
//    sử dụng private access modifier the hien tinh bao dong cua lập trình hướng đối tượng 