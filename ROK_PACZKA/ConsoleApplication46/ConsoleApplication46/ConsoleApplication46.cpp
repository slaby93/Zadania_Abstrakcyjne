// ConsoleApplication46.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int gcd(int x, int y) {
	if (x < 0) {
		x *= -1;
	}
	if (y < 0) {
		y *= -1;
	}
	int tmp;
	while (y > 0) {
		tmp = y;
		y = x%tmp;
		x = tmp;
	}
	return x;
}

class Number {
protected:
	int wartosc;
public:
	virtual void skroc() = 0;

	virtual void fillRandom() = 0;
};

class Rational : public Number {
protected:
	int mianownik;
public:
	Rational(int a) {
		wartosc = a;
		mianownik = 1;
	}

	void skroc() {
		int dzielnik = gcd(wartosc, mianownik);
		if (mianownik < 0) {
			wartosc *= -1;
			mianownik *= -1;
		}
		wartosc /= dzielnik;
		mianownik /= dzielnik;
	}

	void fillRandom() {
		wartosc = -1000 + (rand() % 2001);
		do {
			mianownik = -1000 + (rand() % 2001);
		} while (mianownik == 0);
		skroc();
	}

	bool operator==(const Rational &x) {
		if (this->wartosc == 0 && x.wartosc == 0) {
			return true;
		}
		else {
			return (this->wartosc == x.wartosc) && (this->mianownik == x.mianownik);
		}
	}

	bool operator!=(const Rational &x) {
		if (this->wartosc == 0 && x.wartosc == 0) {
			return false;
		}
		else {
			return !((this->wartosc == x.wartosc) && (this->mianownik == x.mianownik));
		}
	}

	Rational operator-() {
		Rational a(0);
		a.wartosc = -this->wartosc;
		a.mianownik = this->mianownik;
		return a;
	}

	Rational operator/(const Rational &x) {
		Rational a(0);
		a.wartosc = this->wartosc * x.mianownik;
		a.mianownik = this->mianownik * x.wartosc;
		a.skroc();
		return a;
	}

	friend ostream& operator<<(ostream& stream, const Rational &liczba) {
		return stream << liczba.wartosc << "/" << liczba.mianownik;
	}
};

template<class X, class Y>
int compare(X a, Y b) {
	if (a == b) {
		return 0;
	}
	else if (a > b) {
		return 1;
	}
	else {
		return -1;
	}
}

template<class X, class Y>
int compare(X *a, Y *b) {
	if (*a == *b) {
		return 0;
	}
	else if (*a > *b) {
		return 1;
	}
	else {
		return -1;
	}
}

template<class X>
bool isArithmetic(X a) {
	return false;
}

template<>
bool isArithmetic(double a) {
	return true;
}

template<>
bool isArithmetic(int a) {
	return true;
}

template<class X>
bool isConstant(X &a) {
	return false;
}

template<class X>
bool isConstant(const X &a) {
	return true;
}

template<class X>
bool isFortyTwo(X a) {
	if (a == 42) {
		return true;
	}
	return false;
}

template<class X>
X solveEquation(X a, X b) {
	X zero = X(0);
	if (a == zero && b == zero) {
		return zero;
	}
	else if (a == zero && b != zero) {
		throw domain_error(string("No solutions for linear equation of type " + string(typeid(X).name())));
	}
	else {
		return -b / a;
	}
}

template<class X>
X solveEquation(X *a, X *b) {
	X zero = X(0);
	if (*a == zero && *b == zero) {
		return zero;
	}
	else if (*a == zero && *b != zero) {
		throw domain_error(string("No solutions for linear equation of type " + string(typeid(X).name())));
	}
	else {
		return -*b / *a;
	}
}

template<class X>
X solveEquation(const X &a, const X &b) {
	X zero = X(0);
	if (a == zero && b == zero) {
		return zero;
	}
	else if (a == zero && b != zero) {
		throw domain_error(string("No solutions for linear equation of type " + string(typeid(X).name())));
	}
	else {
		return -b / a;
	}
}

template<class X, const X& zero>
X solveEquation(X a, X b) {
	if (a == zero && b == zero) {
		return zero;
	}
	else if (a == zero && b != zero) {
		throw domain_error(string("No solutions for linear equation of type " + string(typeid(X).name())));
	}
	else {
		return -b / a;
	}
}

template<class X, const X& zero>
X solveEquation(X *a, X *b) {
	if (*a == zero && *b == zero) {
		return zero;
	}
	else if (*a == zero && *b != zero) {
		throw domain_error(string("No solutions for linear equation of type " + string(typeid(X).name())));
	}
	else {
		return -*b / *a;
	}
}

template<class X, const X& zero>
X solveEquation(const X &a, const X &b) {
	if (a == zero && b == zero) {
		return zero;
	}
	else if (a == zero && b != zero) {
		throw domain_error(string("No solutions for linear equation of type " + string(typeid(X).name())));
	}
	else {
		return -b / a;
	}
}

double zero = 0;
Rational zero1 = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	double *aa = new double(4), *bb = new double(6);
	Rational *cc = new Rational(0), *dd = new Rational(0);
	cc->fillRandom();
	dd->fillRandom();
	cout << *cc << endl << *dd << endl;
	try {
		cout << solveEquation<double, zero>(aa, bb) << endl;
	}
	catch (exception &e) {
		cout << "Caught: " << e.what() << endl;
		cout << "Type: " << typeid(e).name() << endl;
	}
	const int a = 42;
	int b = 66.6;
	float c = 222.5555;
	cout << isConstant(a);
	cin >> b;
	return 0;
}