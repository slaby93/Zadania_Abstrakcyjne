using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Czlowiek
    {
        private string imie;
        string nazwisko;


        public Czlowiek(string v1, string v2)
        {
            this.Imie = v1;
            this.Nazwisko = v2;
        }

        public string Imie
        {
            get
            {
                return imie;
            }

            set
            {
                imie = value;
            }
        }

        public string Nazwisko
        {
            get
            {
                return nazwisko;
            }

            set
            {
                nazwisko = value.First().ToString().ToUpper() + String.Join("",value.Skip(1));
            }
        }

        public override string ToString()
        {
            return Imie + " " + Nazwisko;
        }

    }

    class Program
    {
        public void dodaj(int x)
        {
            this.sum += x;
        }

        public static void wypisz(int x)
        {
            Console.WriteLine("x = " + x);
        }
         
        int sum = 5;
        static void Main(string[] args)
        {
            //zadanie 1
            /*Czlowiek aaa = new Czlowiek("Daniel", "zaSlaby");
            aaa.Nazwisko = "asdasd";
            System.Console.WriteLine(aaa);
            System.Console.ReadLine();*/

            //zadanie 3
            Zdarzenie p = new Zdarzenie();
            Program m = new Program();

          
            p.registrate(m.dodaj);
            p.registrate(wypisz);
            p.registrate( delegate (int x){
               System.Console.WriteLine("Mam {0}", x);
            });

            p.run(10);
            p.run(5);

            Console.WriteLine("Suma wynosi {0} ", m.sum);

            System.Console.ReadLine();
        }

     

    }
    class Zdarzenie {

       

        private List<Action<int>> list = new List<Action<int>>();

        public void registrate(Action<int> value)
        {
            list.Add(value);
        }

        public void run(int x)
        {
            foreach(var i in list)
            {
                i(x);
            }
        }
    }
}