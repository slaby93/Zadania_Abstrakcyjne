using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        int sum = 5;

        public void dodaj(int x)
        {
            sum += x;
        }

        public static void wypisz(int x)
        {
            Console.WriteLine("x = " + x);
        }



        static void Main(string[] args)
        {
            ///////////////////////   1    ////////////////////////////


            Czlowiek jk = new Czlowiek("jan", "Kowalski");
            System.Console.WriteLine(jk);
            System.Console.WriteLine(jk.Imie + " " + jk.Nazwisko);
            jk.Nazwisko = "Nowak";
            System.Console.WriteLine(jk);

            //////////////////////////   3   //////////////////////////////

            Zdarzenie zdarzenie = new Zdarzenie();
            Program program = new Program();
            zdarzenie.registrate(program.dodaj);
            zdarzenie.registrate(wypisz);
            zdarzenie.registrate(delegate (int x)
            {
                Console.WriteLine("Mam {0} ", x);
            });

            zdarzenie.run(10);
            zdarzenie.run(5);
            Console.WriteLine("Suma wynosi {0} ", program.sum);


        }
    }
}

//////////////////////////////////

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Czlowiek
    {
        String _Imie;
        String _Nazwisko;

       public Czlowiek(String imie, String nazwisko)
        {
            this.Imie = imie;
            this.Nazwisko = nazwisko;
        }

        public String Imie
        {
            get{return _Imie; }
            set {
                _Imie = char.ToUpper(value[0]) 
                    + value.Substring(1, value.Length - 1);
            }
        }

        public String Nazwisko
        {
            get { return _Nazwisko; }
            set {
                _Nazwisko = char.ToUpper(value[0]) 
                    + value.Substring(1, value.Length - 1);
            }
        }

        public override string ToString()
        {
            return Imie + " " + Nazwisko;
        }
    }
}

////////////////////////////////////////////////


using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Zdarzenie
    {
        public delegate void DFunction(int x);
        public DFunction df;
         

        public void registrate(DFunction value)
        {
            df += value;  
        }

        public void run(int x)
        {
            df(x);
        }
    }
}
