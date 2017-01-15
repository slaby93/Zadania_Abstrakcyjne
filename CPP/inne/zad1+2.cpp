#include <iostream>

template <int N>
struct Silnia {
    enum {
    wartosc = N*Silnia<N-1>::wartosc
    };
};

template<>
struct Silnia<0> {
    enum {
        wartosc = 1
    };
};


template <int W, int N>
struct Potega {
    enum {
        wartosc = W * Potega<W,N-1>::wartosc
    };
};

template <int W>
struct Potega<W,0> {
    enum {
        wartosc = 1
    };
};

template <int N>
struct Fibonacci {
    enum {
        wartosc = Fibonacci<N-1>::wartosc
                + Fibonacci<N-2>::wartosc
    };
};

template <>
struct Fibonacci<1> {
    enum {
        wartosc = 1
    };
};

template <>
struct Fibonacci<2> {
    enum {
        wartosc = 1
    };
};


// ILOCZYNY

template<int N>
double IloczynSkalarny(const double a[], const double b[]) {
    return a[N-1] * b[N-1] + IloczynSkalarny<N-1>(a,b);
}

template<>
double IloczynSkalarny<1>(const double a[], const double b[]) {
    return a[0] * b[0];
}




template<typename T, int N, int M>
struct Iloczyn
{
    static void oblicz(const T a[], const T x[], T y[]) {
        y[N - 1] = IloczynSkalarny<M>(a + M * (N - 1), x);
        Iloczyn<T, N - 1, M>::oblicz(a, x, y);
    }
};

template<typename T, int M>
struct Iloczyn<T, 0, M> {
    static void oblicz(const T a[], const T x[], T y[]) {}
};





int main() {
    /*
    std::cout << Silnia<5>::wartosc;
    std::cout << Silnia<0>::wartosc << "\n";
    std::cout << Potega<5,3>::wartosc << "\n";
    std::cout << Fibonacci<20>::wartosc << "\n";
    */

    double a[] = {1, 2, 3};
    double b[] = {1, 1, 1};

    std::cout << IloczynSkalarny<3>(a, b) << "\n";

    double x[] = {1, 1, 0};
    double A[] = {1, 0, 0,
                  2, -5, 1};
    double y[2];
    Iloczyn<double, 2,3>::oblicz(A,x,y);

    std::cout << y[0] << " " << y[1] << "\n";

    return 0;
}

