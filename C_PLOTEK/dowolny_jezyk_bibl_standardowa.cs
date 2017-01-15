using System;
using System.Collections.Generic;
using System.Linq;

namespace cw7
{

	class MainClass
	{

		public static IEnumerable<int> lengthsSeq<T>(IEnumerable<List<T>> seq){
			return seq.Select (item => item.Count);
		}

		public static IEnumerable<T> betweenSeq<T>(IEnumerable<T> seq, T from, T to) where T : IComparable<T>{
			return seq.Where (item => item.CompareTo(from) >= 0 && item.CompareTo(to) <= 0);
		}

		public static IEnumerable<T> disSeq<T>(IEnumerable<T> seq){
			return seq.Distinct ();
		}

		public static IEnumerable<T> unionSeq<T>(IEnumerable<T> a, IEnumerable<T> b){
			return a.Union (b);
		}

		public static IEnumerable<T> interSeq<T>(IEnumerable<T> a, IEnumerable<T> b){
			return a.Intersect (b);
		}

		public static IEnumerable<double> sortSeq(IEnumerable<double> seq){
			return seq.OrderBy (item => item - Math.Truncate(item));
		}

		public static void wypisz<T>(IEnumerable<T> seq, string separator){
			Console.WriteLine(String.Join(separator, seq));
		}
			
		public static IEnumerable<double> RandList (int n)
		{
			var random = new Random ();
			return Enumerable.Range (0, n).Select (_ => random.NextDouble ());
		}


		public static void Main (string[] args)
		{

			var list = sortSeq (RandList (10));

			wypisz (list, ", ");

			var list1 = new List<int> { 1,2,3,4,5,6,7};
			var list2 = new List<int> { 5, 6, 7, 8, 9 };
			var list4 = new List<int> { 1, 1, 1, 1, 22, 2, 2, 2, 2, 2, 2 };

			var list3 = new List<List<int>> { list1, list2 };

			wypisz (betweenSeq (list1, 3, 5), ", ");
			wypisz (unionSeq (list1, list2), ", ");
			wypisz (interSeq (list1, list2), ", ");
			wypisz (lengthsSeq (list3), ", ");
			wypisz (disSeq (list4), ", ");
		}

	}
}
