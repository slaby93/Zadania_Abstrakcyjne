#include <iostream>
using namespace std;

//template<typename T>  struct sum_traits;
//
//template<>  struct sum_traits<char> {
//    typedef int  sum_type;
//    static  sum_type zero() {return 0;}
//};
//template<>  struct sum_traits<float> {
//    typedef double  sum_type;
//    static  sum_type zero() {return 0.0;}
//};
//
//template<>  struct sum_traits<int> {
//    typedef long int sum_type;
//    static  sum_type zero() {return 0;}
//};
//template<>  struct sum_traits<double> {
//    typedef double sum_type;
//    static  sum_type zero() {return 0.0;}
//};
//
//template<typename T>
//typename sum_traits<T>::sum_type sum(T *beg,T *end) {
//    typedef typename sum_traits<T>::sum_type sum_type;
//    sum_type total = sum_traits<T>::zero();
//    while(beg != end ) {
//        total += *beg; beg++;
//    }
//    return total;
//}
//
//
//int main() {
//    char name[]="@ @ @";
//    int length=strlen(name);
//    cout<<sum(name,&name[length]);
//}

#include <list>

//template <typename Iter>
//typename iterator_traits<Iter>::value_type minimum(Iter begin, Iter ending) {
//    if (begin == ending)
//        throw new logic_error("Empty sequence has no minimum!");
//    Iter minimum = begin;
//    while (++begin != ending) {
//        if (*minimum > *begin)
//            minimum = begin;
//    }
//    return *minimum;
//}
//
//int main() {
//    list<int> list;
//    list.push_back(7);   list.push_back(3);   list.push_back(5);
//    cout << "List's minimum: " << minimum(list.begin(), list.end()) << '\n';
//    int tab[3];
//    tab[0] = 7;   tab[1] = 3;   tab[2] = 5;
//    cout << "Array's minimum: " << minimum(tab, tab + 3) << '\n';
//    return 0;
//}



//
//template <typename Iter>
//int operacja_impl(Iter i, forward_iterator_tag) {
//    cout << "Forward Iterator.\n";
//    return 0;
//}
//
//template <typename Iter>
//int operacja_impl(Iter i, bidirectional_iterator_tag) {
//    cout << "Biderectional Iterator.\n";
//    return 0;
//}
//
//template <typename Iter>
//int operacja_impl(Iter i, random_access_iterator_tag) {
//    cout << "Random access iterator.\n";
//    return 0;
//}
//
//template <typename Iter>
//inline int operacja(Iter i) {
//    return operacja_impl(i, typename iterator_traits<Iter>::iterator_category());
//}
//
//int main() {
//    list<int> l;
//    operacja(l.begin());
//    int t[3];
//    operacja(t);
//    return 0;
//}

//template <typename Iter>
//void wypisz_na_cout(Iter b, Iter e) {
//    while (b != e) {
//        cout << *b;
//        ++b;
//        if (b != e) {
//            cout << ' ';
//        }
//    }
//    cout << '\n';
//}
//
//
//template <typename Iter>
//void sortuj_impl(Iter b, Iter e, forward_iterator_tag) {
//    Iter i, min;
//    while (b != e) {
//        i = min = b;
//        while (++i != e) {
//            if (*i < *min)
//                min = i;
//        }
//        if (b != min)
//            swap(*b, *min);
//        ++b;
//    }
//}
//
//template <typename Iter>
//void sortuj_impl(Iter b, Iter e, random_access_iterator_tag tag) {
//    if (e - b <= 1)
//        return;
//    Iter left = b;
//    Iter right = e - 1;
//    typename iterator_traits<Iter>::value_type pivot =
//            *(left + (right - left) / 2);
//    while (1) {
//        while (*left < pivot)
//            ++left;
//        while (*right > pivot)
//            --right;
//        if (left > right)
//            break;
//        swap(*left, *right);
//        ++left;
//        --right;
//    }
//    sortuj_impl(b, right + 1, tag);
//    sortuj_impl(left, e, tag);
//}
//
//template <typename Iter>
//inline void sortuj(Iter b, Iter e) {
//    return sortuj_impl(b, e, typename iterator_traits<Iter>::iterator_category());
//}
//
//int main() {
//    static const int len = 20;
//    int t[len];
//    list<int> l;
//
//    srand(time(0));
//    for (int i = 0; i < len; ++i) {
//        t[i] = 10 + rand() % 90;
//        l.push_back(t[i]);
//    }
//
//    wypisz_na_cout(l.begin(), l.end());
//    sortuj(l.begin(), l.end());
//    wypisz_na_cout(l.begin(), l.end());
//    sortuj(t, t + len);
//    wypisz_na_cout(t, t + len);
//
//    return 0;
//}

#include <iomanip>
#include <complex>

template <typename T>
inline void info(T num) {
    if (std::numeric_limits<T>::is_specialized) {
        if(numeric_limits<T>::is_signed) {
            cout << "signed" ;
        } else {
            cout << "unsigned";
        }
        if(numeric_limits<T>::is_integer) {
            cout << " integer";
        } else {
            cout << " not integer";
        }
        cout << " min: " << numeric_limits<T>::lowest();
        cout << " max: " << numeric_limits<T>::max() << endl;
    }
}



int main() {
    info(1);
    info(2.0f);
    info(complex<double>(1, 2));
}
