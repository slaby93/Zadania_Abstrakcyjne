#include <iostream>
// DANIEL S£ABY
using namespace std;

template<int Rozmiar, typename Typ>
class Tablica {
public:
    Typ innerTab[Rozmiar];

    Tablica() {
        for (int i = 0; i < Rozmiar; i++) {
            innerTab[i] = 0;
        }
    }

    Typ pobierz(int index) {
        return innerTab[index];
    }

    void wstaw(int index, Typ arg) {
        innerTab[index] = arg;
    }

    void wypisz() {
        cout << "[";
        for (int i = 0; i < Rozmiar; i++) {
            cout << innerTab[i] << " ";
        }
        cout << "]" << endl;
    }
};

template<int A, typename B>
void zadanie6(Tablica<A, B> *arg) {
    cout << "ROZMIAR: " << A << endl;
}

template<int Rozmiar, typename B>
void zadanie7(Tablica<Rozmiar, B> *param) {
    B *tab = param->innerTab;
    for (int i = 0; i < Rozmiar; i++) {
        for (int j = 0; j < Rozmiar; j++) {
            if (tab[i] < tab[j]) {
                int tmp = tab[j];
                tab[j] = tab[i];
                tab[i] = tmp;
            }
        }
    }
}


int main() {
    Tablica<5, int> *t = new Tablica<5, int>();
    t->wstaw(3, 3);
    t->wstaw(2, 4);
    t->wstaw(1, 1);
    t->wstaw(0, 2);
    t->wstaw(4, 5);
    zadanie6(t);
    t->wypisz();
    zadanie7(t);
    t->wypisz();
}