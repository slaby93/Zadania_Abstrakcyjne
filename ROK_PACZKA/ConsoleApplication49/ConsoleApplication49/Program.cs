using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication49
{
    class Program
    {
        static void Main(string[] args)
        {
            string test = "    \t";
            HtmlTabReplacer replacer = new HtmlTabReplacer();
            System.Console.WriteLine(replacer.Transform(test));
            string[] options = { "3" };
            replacer.Options = options;
            System.Console.WriteLine(replacer.Transform(test));
            test = "AAAuuuuuuAAAABBBCCCoiidddaIPO";
            CaseReplacer cg = new CaseReplacer();
            System.Console.WriteLine(cg.Transform(test));
            string[] letter = { "l" };
            cg.Options = letter;
            System.Console.WriteLine(cg.Transform(test));
            Console.ReadLine();
        }
    }
}
