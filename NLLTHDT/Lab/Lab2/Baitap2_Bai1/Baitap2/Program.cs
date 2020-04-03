using System;

namespace Bai1
{
    class Program
    {
        class myClass
        {
            private static int i;   //giá trị mặc định cho i là 0
            public void seti(int n) { i = n; }
            public int geti() { return i; }
        }
        static void Main(string[] args)
        {
            myClass ob1 = new myClass();
            myClass ob2 = new myClass();
            ob1.seti(10);
            Console.WriteLine("Gia tri ob1: {0}", ob1.geti());  //Hiển thị 10
            Console.WriteLine("Gia tri ob2: {0}", ob2.geti());  //Hiển thị 10
        }
    }
}

//Câu hỏi: Giải thích vì sao giá trị i đối tượng ob2 cũng bằng 10 mặc dù chưa khởi gán giá trị này cho đối tượng ob2
//Trả lời: khi khai báo private gán i mặc định bằng 0 (sửa đổi dữ liệu bên trong class); sau đó khởi gán giá trị thì kết quả lưu về mặc định sẽ là 10. Từ đó cho ra 2 kết quả đều bằng 10