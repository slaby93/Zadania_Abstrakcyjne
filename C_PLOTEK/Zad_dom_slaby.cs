using System;
using System.Collections.Generic;

namespace konsola
{

	class BiMap<K, V>
	{

		private Dictionary<K, V> hashmap1;

		private Dictionary<V, K> hashmap2;

		public BiMap()
		{
			hashmap1 = new Dictionary<K, V>();
			hashmap2 = new Dictionary<V, K>();
		}

		public V GetByKey(K key)
		{
			return hashmap1.ContainsKey(key) ? hashmap1[key] : default(V);
		
		}


		public K GetByValue(V value)
		{
			return hashmap2.ContainsKey(value) ? hashmap2[value] : default(K);
		}

		public void Add(K key, V value)
		{
			if (hashmap1.ContainsKey(key) || hashmap2.ContainsKey(value))
				throw new System.Exception("This Key or Value is already used");
			

			hashmap1.Add(key, value);
			hashmap2.Add(value, key);

		}


	}


	class MainClass
	{
		public static void Main(string[] args)
		{
			BiMap<int, int> biMap = new BiMap<int, int>();


			biMap.Add(7, 4);
			biMap.Add(3, 7);

			Console.WriteLine(biMap.GetByKey(7));
			Console.WriteLine(biMap.GetByValue(7));
		}
	}
}
