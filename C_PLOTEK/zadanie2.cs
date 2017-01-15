using System;
 
namespace cw8
{
 
    class Osoba{
 
        protected string Name;
 
        public Osoba(string name){
            Name = name;
        }
 
        public string Przedstaw(){
            return String.Format("Jestem {0}", Name);
        }
 
    }
 
    class Pracownik : Osoba{
 
        private string _job;
 
        public Pracownik(string name, string job) : base (name){
            _job = job;
        }
 
        public new string Przedstaw(){
            return String.Format("{0}. Pracuję jako {1}", base.Przedstaw(), _job);
        }
    }
 
    class MainClass
    {
        public static void Main (string[] args)
        {
 
            Pracownik p = new Pracownik ("Jan Kowalski", "piekarz");
 
                Console.WriteLine ((p as Osoba).Przedstaw());
        }
    }
}