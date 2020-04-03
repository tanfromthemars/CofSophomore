using System;

namespace Bai2
{
    class Program
    {
        class myClass
        {
            public static int i;    //giá trị mặc định cho i là 0
            public void seti(int n) { i = n; }
            public int geti() { return i; }
        }
        static void Main(string[] args)
        {
            myClass.i = 100;

            myClass ob1 = new myClass();
            myClass ob2 = new myClass();

            Console.WriteLine("Gia tri ob1: {0}", ob1.geti());  //Hiển thị 100
            Console.WriteLine("Gia tri ob2: {0}", ob2.geti());  //Hiển thị 100
        }
    }
}
//Giải thích: Khi khai báo "public" cho giá trị i và 0, sau đó để cập nhật dữ liệu ta cần object của class (sua doi du lieu ben ngoai class) 