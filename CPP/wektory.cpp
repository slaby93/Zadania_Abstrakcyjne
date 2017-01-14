#include <iostream>
#include <vector>

using namespace std;

//Zadanie numer 1
//void wypisz(const char *s) {
//    while (*s) {
//        if (*s == '%' && *(++s) != '%') {
//            throw std::length_error("Zła liczba argumentów");
//        }
//        std::cout << *s++;
//    }
//}
//
//template<typename T, typename... Args>
//void wypisz(const char *s, T value, Args... args) {
//    while (*s) {
//        if (*s == '{' && *(++s) == '}') {
//            std::cout << value;
//            wypisz(*s ? ++s : s, args...);
//            return;
//        }
//        std::cout << *s++;
//    }
//    throw std::length_error("Zła liczba argumentów");
//}
//
//int main() {
//    wypisz("Wynikiem {} {} do {} jest {}", "dodania", 2, 3.0, 2 + 3.0);
//    return 0;
//}



//Zadanie numer 3
//int operator "" _bin(const char *number_to_convert) {
//    return stoi(number_to_convert, nullptr, 2);
//}
//
//int main() {
//    cout << 1101_bin << " " << -1100_bin << endl;
//}


template <class T> class Wektor {
private:
public:
    vector<T> v;

    Wektor<T>(initializer_list<T> arr) {
        for (auto n : arr) {
            v.push_back(n);
        }
    }

    Wektor<T>(Wektor<T> &old) {
        cout << "kopiuje \n";
        v = old.v;
    }


    T *begin() {
        return &v[0];
    }

    T *end() {
        return &v[v.size()];
    }

    Wektor<T> &operator=(Wektor<T> &&other) {
        if (this != &other) {
            delete v;
            v = other.v;
            other.v = nullptr;
        }
        return *this;
    }

    Wektor operator +(const Wektor<T> & y )
    {
        return Wektor<T>(y.v);
    }

};


int main() {
    typedef Wektor<int> IWektor;
    IWektor v = {1, 4, 5};
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
    IWektor u(v);
    for (auto x : u) {
        cout << x << " ";
    }
    cout << endl;
    IWektor s = v + u;
};
