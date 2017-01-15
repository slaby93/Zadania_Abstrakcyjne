using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication49
{
    class SetRegexTextTransformer : RegexTextTransformer
    {
        private string[] options;

        public SetRegexTextTransformer()
        {
            options = new string[2] { "", "" };
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
            return options[0];
        }

        public override string GetReplacement()
        {
            return options[1];
        }
    }
}
