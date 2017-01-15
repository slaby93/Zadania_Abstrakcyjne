// ConsoleApplication52.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template<int x, int n>
struct Potega {
	static const int result = x * Potega<x, n - 1>::result;
};

template<int x>
struct Potega<x, 0> {
	static const int result = 1;
};

template<int n>
struct Fibonacci {
	static const int result = Fibonacci<n - 1>::result + Fibonacci<n - 2>::result;
};

template<>
struct Fibonacci<0> {
	static const int result = 0;
};

template<>
struct Fibonacci<1> {
	static const int result = 1;
};

template<typename T>
inline void replace(T& x, T& y) {
	T tmp = x;
	x = y;
	y = tmp;
}

template<typename T, int n>
struct BubbleSort {
	static inline void sort(T* data) {
		BubbleSortInnerLoop<T, true, 0, n>::loop(data);
	}
};

template<typename T, int i, int j>
struct BubbleSortCompare {
	static inline void compare(T* data) {
		if (data[i] > data[j]) {
			replace(data[i], data[j]);
		}
	}
};

template<typename T, bool done, int i, int n>
struct BubbleSortInnerLoop {
	static inline void loop(T* data) {
		BubbleSortOuterLoop<T, true, i, i + 1, n>::loop(data);
		BubbleSortInnerLoop<T, i < (n - 2), i + 1, n>::loop(data);
	}
};

template<typename T, int i, int n>
struct BubbleSortInnerLoop <T, false, i, n> {
	static inline void loop(T* data) {}
};

template<typename T, bool done, int i, int j, int n>
struct BubbleSortOuterLoop {
	static inline void loop(T* data) {
		BubbleSortCompare<T, i, j>::compare(data);
		BubbleSortOuterLoop<T, j < (n - 1), i, j + 1, n>::loop(data);
	}
};

template<typename T, int i, int j, int n>
struct BubbleSortOuterLoop<T, false, i, j, n> {
	static inline void loop(T* data) {}
};

int _tmain(int argc, _TCHAR* argv[])
{
	cout << Potega<5, 3>::result << endl;
	cout << Fibonacci<5>::result << endl;
	double a[] = { 15.24, 7.68, 3.21, 8.47, 10.56, 8.12, 8.47, 1.41, 9.31, 80.98, 17.21, 0.68 };
	BubbleSort<double, 12>::sort(a);
	for (int i = 0; i < 12; i++) {
		std::cout << a[i] << std::endl;
	}
	cin >> a[0];
	return 0;
}

