#include <iostream>

using namespace std;

template<class Typ>
int porownaj(Typ *a, Typ *b) {
    if (*a > *b) {
        return 1;
    } else if (*a == *b) {
        return 0;
    } else {
        return -1;
    }
}

template<typename Type>
bool zadanie3(Type) {
    return false;
}

template<>
bool zadanie3(int x) {
    return true;
}

template<typename Type>
bool zadanie3(Type *x) {
    return true;
}

template<>
bool zadanie3(double x) {
    return true;
}

template<typename T1, int rozmiar>
class Tablica {
public:
    Tablica(T1 a) {

    }
};

int main() {

    int liczba1 = 1;
    int liczba2 = 1;
    int *a;
    int *b;
    a = &liczba1;
    b = &liczba2;

    cout << "Wynik porównania: " << porownaj(a, b) << endl;

    cout << endl;

    cout << "Wynik zadanie 3 proba 1 <Integer>: " << zadanie3(1) << endl;
    cout << "Wynik zadanie 3 proba 2 <Double>: " << zadanie3(.4) << endl;
    cout << "Wynik zadanie 3 proba 3 <Pointer>: " << zadanie3(a) << endl;
    cout << "Wynik zadanie 3 proba 4 <String> : " << zadanie3("string") << endl;
    

    return 0;

}