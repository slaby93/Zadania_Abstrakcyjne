#include <iostream>
#include <typeinfo>
using namespace std;


class A {};

class B : public A
{
};

class C
{
};

template<bool B, typename T, typename F>
struct Test
{
    typedef T type;
};

template<typename T, typename F>
struct Test <false, T, F>
{
    typedef F type;
};

template<typename T, typename F>
struct Test <true, T, F>
{
    typedef T type;
};

template<typename T1, typename T2>
struct ZwrocWiekszy : public Test<(sizeof(T1) > sizeof(T2)), T1, T2> {};


template<bool B>
struct Test_bool
{
    enum
    {
            value = true
    };
};

template <>
struct Test_bool <false>
{
    enum
    {
        value = false
    };
};

template <>
struct Test_bool <true>
{
    enum
    {
        value = true
    };
};

template<typename BASE, typename T2>
struct CzyKonwertowalna : public Test_bool<is_base_of<BASE, T2>::value> {};


template<typename T>
struct CzyKlasa : public Test_bool<is_class<T>::value> {};

int main()
{
    cout << typeid(typename ZwrocWiekszy<float, double>::type).name() << endl;
    cout << typeid(typename ZwrocWiekszy<double, float>::type).name() << endl;

    cout << CzyKonwertowalna<A, B>::value << endl;
    cout << CzyKonwertowalna<A, C>::value << endl;

    cout << CzyKlasa<A>::value << endl;
    cout << CzyKlasa<int>::value << endl;
}
