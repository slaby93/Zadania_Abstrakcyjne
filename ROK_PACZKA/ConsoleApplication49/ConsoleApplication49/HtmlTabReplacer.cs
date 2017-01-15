using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication49
{
    class HtmlTabReplacer : RegexTextTransformer
    {
        private string[] options;

        public HtmlTabReplacer()
        {
            options = new string[1] { "2" };
        }

        public override string[] Options
        {
            set
            {
                options = value;
            }
        }

        public override string GetRegex()
        {
            return "    |\t";
        }

        public override string GetReplacement()
        {
            StringBuilder multiply = new StringBuilder();
            for (int i = 0; i < Int32.Parse(options[0]); i++)
            {
                multiply.Append("nbsp;");
            }
            return multiply.ToString();
        }
    }
}
