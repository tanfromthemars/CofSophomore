using System;
using System.Collections.Generic;
using System.Text;

namespace Demo_Final
{
    public interface IOdatabase
    {
        void Read(string filename);
        void Write(string filename);
    }
}
