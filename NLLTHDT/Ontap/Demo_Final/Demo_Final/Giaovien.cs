using System;
using System.Collections.Generic;
using System.Text;

namespace Demo_Final
{
    public class Giaovien : Nguoi
    {
        private string _id;
        private string _tenBomon;
        public string ID { get { return _id; } }
        public string TenBomon { get { return _tenBomon; } set { _tenBomon = value; } }
        public Giaovien() { _id = "GV"; }
        public Giaovien(string hoDem, string ten, string ms, string tenBomon) : base(hoDem, ten, ms)
        {
            _id = "GV";
            _tenBomon = tenBomon;
        }
    }
}
