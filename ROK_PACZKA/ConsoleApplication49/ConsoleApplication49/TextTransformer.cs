using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication49
{
    interface TextTransformer
    {
        string Transform(string str);

        string[] Options
        {
            set;
        }
    }
}
