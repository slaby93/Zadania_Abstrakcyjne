#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <typeinfo>

using namespace std;

//zadanie2
template <class Typ>
int porownaj(Typ *a, Typ *b)
{
    if(*a==*b) {
		return 0;
	} else if (*a > *b) {
		return 1;
	} else {
		return -1;
	}
}

template<>
int porownaj(string *a, string *b) {
	return a->compare(*b);
}


//zadanie3
template <class Typ>
bool test(Typ a)
{
	return false;
}

template <>
bool test(int a)
{
	return true;
}

template <>
bool test(double a)
{
	return true;
}

template <class Typ>
bool test(Typ *a)
{
	return false;
}

//zadanie4
//przyklad cos na ten gust
template<class T>
bool check(T p) {
	if(typeid(T) == typeid(int) || typeid(T) == typeid(double))
		return true;
	else return false;
}

//zadanie5
template<typename T, int K>
class Tablica {


	T elements[K];

	public:

		T pobierz(int index) {
			return elements[index];
		}

		void dodaj(T elem, int index){
			elements[index] = elem;
		}

		T& operator[] (const int index)
        {
            return elements[index];
        }
};


int main() {
	//int a = 100;
	//int b = 1000;
	//int *wsk_a = &a;
	//int *wsk_b = &b;

	//zadanie2
	//cout<<porownaj(wsk_a,wsk_b);

	 //zadanie3
	 //int c = 1000;
	 //int *wsk_c = &c;
	 //cout<<test(1)<<endl;
	 //cout<<test(1.0)<<endl;
	 //cout<<test(*wsk_c)<<endl;
	 //cout<<test("asda")<<endl;

	 //zadanie5

	 Tablica<int,10> t;

	 t.dodaj(10333,0);
	 cout<<t[0];



}

