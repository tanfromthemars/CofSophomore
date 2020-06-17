using System;
using System.Collections.Generic;
using System.Text;

namespace BaiKiemtra_Cuoicung
{
    public class Giaovien : Nguoi
    {
        private string _msgv;
        private string _bomon;

        public Giaovien(string hoDem, string ten, string maSo, string msgv, string bomon)
            : base(hoDem, ten, maSo)
        {
            _msgv = msgv;
            _bomon = bomon;
        }

        public string MSGV { get => _msgv; set => _msgv = value; }
        public string Bomon { get => _bomon; set => _bomon = value; }
    }
}
