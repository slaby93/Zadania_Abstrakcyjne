//Lukasz Papierz
using System;
using System.Collections.Generic;

namespace ConsoleApplication2
{
    class NewMap<K, V>
    {

        private Dictionary<K, V> dictionary;
        private Dictionary<V, K> dictionary2;

        public NewMap() {
            dictionary = new Dictionary<K, V>();
            dictionary2 = new Dictionary<V, K>();
        }

        public V Get(K key) {
            if (dictionary.ContainsKey(key)) {
                return dictionary[key];
            } else {
                return default(V);
            }
        }

        public K GetR(V value) {
            if (dictionary2.ContainsKey(value)) {
                return dictionary2[value];
            } else {
                return default(K);
            }
        }

        public void Add(K key, V value) {
            if (dictionary.ContainsKey(key) || dictionary2.ContainsKey(value)) {
                return;
            } else {
                dictionary.Add(key, value);
                dictionary2.Add(value, key);
            }

        }


    }


    class Program
    {
        static void Main(string[] args)
        {
            NewMap<int, int> map = new NewMap<int, int>();


            map.Add(5, 4);
            map.Add(5, 3);
            map.Add(3, 5);

            Console.WriteLine(map.Get(5));
            Console.WriteLine(map.GetR(5));
        }
    }
}
