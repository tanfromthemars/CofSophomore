using System;
using System.IO;

interface IODatabase
{
    void Read(string Filename);
    void Write(string Filename);
    string Data { get; set; }
}
interface Baomat
{
    void Mahoa();
    void Giaima();
}
public class Document: IODatabase, Baomat
{
    string S;
    public Document(string str)
    {
        S = str;
    }
    public void Read(string Filename)
    {
        FileStream fs = new FileStream(Filename, FileMode.Open);
        StreamReader sr = new StreamReader(fs);
        string text;
        S = "";
        while ((text = sr.ReadLine())!=null)
        {
            S = S + text;
        }
        sr.Close();
        fs.Close();
    }
    public void Write(string Filename)
    {
        FileStream fs;
        fs = new FileStream(Filename, FileMode.OpenOrCreate);
        StreamWriter sw = new StreamWriter(fs);
        sw.WriteLine(S);
        sw.Close();
        fs.Close();
    }
    public string Data
    {
        get { return S; }
        set { S = value; }
    }
    public void Mahoa()
    {
        string KQ = "";
        for (int i = 0; i < S.Length; i++)
            KQ = KQ + (char)((int)S[i] + 5);
        S = KQ;
    }
    public void Giaima()
    {
        string KQ = "";
        for (int i = 0; i < S.Length; i++)
            KQ = KQ + (char)((int)S[i] - 5);
        S = KQ;
    }
    //public void DemKytu()
    //{
    //    int ChuCai, ChuSo, KyTuDacBiet, i, l;
    //    ChuCai = ChuSo = KyTuDacBiet = i = 0;
    //    l = S.Length;
    //    while (i < l)
    //    {
    //        if ((S[i] >= 'a' && S[i] <= 'z') || (S[i] >= 'A' && S[i] <= 'Z'))
    //        {
    //            ChuCai++;
    //        }
    //        else if (S[i] >= '0' && S[i] <= '9')
    //        {
    //            ChuSo++;
    //        }
    //        else
    //        {
    //            KyTuDacBiet++;
    //        }
    //        i++;
    //    }
    //    Console.Write("So chu cai: {0}", ChuCai);
    //    Console.Write("So chu so: {0}", ChuSo);
    //    Console.Write("So ky tu dac biet: {0}", KyTuDacBiet);
    //}
    public void Dem()
    {
        int l = 0;
        int j;
        int bien_dem = 0;
        while (l < S.Length - 1)
        {
            j = l;
            while (true)
            {
                if (S[l + 1] == ' ' && S[j] != ' ')
                {
                    bien_dem++;
                    l++;
                    j++;
                    break;
                }
            }
        }
    }
}
public class Program
{
    static void Main(string[] args)
    {
        string Filename = "d:\\Sinhvien.txt";
        Document doc = new Document("Hoc mon lap trinh huong doi tuong");
        doc.Write(Filename);
        doc.Dem();
        doc.Read(Filename);
        Console.WriteLine("Du lieu trong file: {0}", doc.Data);
        Console.WriteLine("Du lieu sau khi ma hoa: ");
        doc.Mahoa();
        Console.WriteLine(doc.Data);
        Console.WriteLine("Du lieu sau khi giai ma: ");
        doc.Giaima();
        Console.WriteLine(doc.Data);
        Console.ReadLine();
    }
}