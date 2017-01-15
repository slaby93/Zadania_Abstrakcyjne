using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace ConsoleApplication49
{
    abstract class RegexTextTransformer : TextTransformer
    {
        public string Transform(string str)
        {
            return Regex.Replace(str, GetRegex(), GetReplacement());
        }

        public abstract string[] Options
        {
            set;
        }

        public abstract string GetRegex();

        public abstract string GetReplacement();
    }
}
