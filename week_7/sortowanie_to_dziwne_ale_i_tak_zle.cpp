#include <iostream>

template<int K, typename T>
void sortuj(T *tab) {
    int n = K;
    do {
        for (int i = 0; i < K - 1; i++) {
            if (tab[i] > tab[i + 1]) {
                T temp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;
            }
        }
        n = n - 1;
    } while (n > 1);

    for (int i = 0; i < K; i++) {
        std::cout << tab[i] << std::endl;
    }
}


int main() {
    int tab[] = {1, 0, 4, 2, 3};
    sortuj<5>(tab);
    return 0;
}



