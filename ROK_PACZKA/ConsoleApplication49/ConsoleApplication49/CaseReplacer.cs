using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication49
{
    class CaseReplacer : TextTransformer
    {
        private string[] options;

        public CaseReplacer()
        {
            options = new string[1] { "" };
        }

        public string Transform(string str)
        {
            if (options[0] == "l")
            {
                return str.ToLower();
            }
            else
            {
                return str.ToUpper();
            }
        }

        public string[] Options
        {
            set
            {
                options = value;
            }
        }
    }
}
