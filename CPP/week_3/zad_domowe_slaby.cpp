// DANIEL SŁABY - ZADANIE DOMOWE 3 | PROGRAMOWANIE ABSTRAKCYJNE

#include <iostream>

using namespace std;

template<int iloscElementow, class typ>
class Tablica {
public:

    typ zmienna[iloscElementow];

    void wstaw(int index, typ element) {
        zmienna[index] = element;
    }

    typ pobierz(int index) {
        return zmienna[index];
    }

    int size() {
        return iloscElementow;
    }


    void wypiszTablice() {
        for (int i = 0; i < iloscElementow; i++) {
            cout << zmienna[i] << endl;
        }
    }

};

int main() {
    Tablica<21, double> nowa;
    for (int i = 0; i < nowa.size(); i++) {
        nowa.wstaw(i, i / 2);
    }
    nowa.wypiszTablice();
}