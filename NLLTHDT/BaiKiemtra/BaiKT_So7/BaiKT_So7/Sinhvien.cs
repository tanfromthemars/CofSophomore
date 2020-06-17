using System;
using System.Collections.Generic;
using System.Text;

namespace BaiKT_So7
{
    class Sinhvien : Nguoi
    {
        public Nguoi()
        {

        }
        public Nguoi(string Ho, string Ten, string MSSV)
        {
            _Ho = Ho;
            _Ten = Ten;
            _MSSV = MSSV;
        }
        public string Ho
        {
            get { return _Ho; }
            set { _Ho = value; }
        }
        public string Ten
        {
            get { return _Ten; }
            set { _Ten = value; }
        }
        public string MSSV
        {
            get { return _MSSV; }
            set { _MSSV = value; }
        }
        public string HoTen
        {
            get { return _Ho + " " + _Ten; }
        }
    }
}
