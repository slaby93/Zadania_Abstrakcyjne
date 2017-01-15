using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication50
{
    delegate int SimpleDelegate(int a, int b);
    delegate int MultiplyDelegate(int a, int b);

    class Program
    {
        class Test
        {
            public int Add(int a, int b)
            {
                return a + b;
            }
        }

        public static MultiplyDelegate ReturnDelegate(SimpleDelegate a, SimpleDelegate b)
        {
            return (int x, int y) => { return a(x, y) * b(x, y); };
        }

        static void Main(string[] args)
        {
            Test test = new Test();
            SimpleDelegate a = test.Add;
            SimpleDelegate b = (int x, int y) => { return x - y; };
            MultiplyDelegate c = ReturnDelegate(a, b);
            System.Console.WriteLine(c(14, 52));
            Console.ReadLine();
        }
    }
}
