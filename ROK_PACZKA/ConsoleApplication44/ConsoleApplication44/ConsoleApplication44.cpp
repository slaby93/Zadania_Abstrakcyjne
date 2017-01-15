// ConsoleApplication44.cpp : Defines the entry point for the console application.
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
	virtual int compare(Number &x) = 0;

	virtual string toString() = 0;

	virtual void fillRandom() = 0;
};

class Rational : public Number {
protected:
	int mianownik;
public:
	int compare(Number &x);

	string toString() {
		return to_string(wartosc) + "/" + to_string(mianownik);
	}

	void fillRandom() {
		wartosc = -1000 + (rand() % 2001);
		do {
			mianownik = -1000 + (rand() % 2001);
		} while (mianownik == 0);
		int dzielnik = gcd(wartosc, mianownik);
		if (mianownik < 0) {
			wartosc *= -1;
			mianownik *= -1;
		}
		wartosc /= dzielnik;
		mianownik /= dzielnik;
	}
};

class Rational2D : public Number {
protected:
	bool znak;
	Rational x, y;
public:
	int compare(Number &x) {
		if (typeid(x) == typeid(Rational2D)) {
			Rational2D &y = dynamic_cast<Rational2D&>(x);
			int a = this->x.compare(y.x);
			int b = this->y.compare(y.y);
			if (a != 0) {
				return a;
			}
			else {
				return b;
			}
		}
		else {
			Rational &y = dynamic_cast<Rational&>(x);
			return this->x.compare(y);
		}
	}

	string toString() {
		string out = x.toString();
		if (znak == 0) {
			out += " - sqrt(";
		}
		else {
			out += " + sqrt(";
		}
		return out + y.toString() + ")";
	}

	void fillRandom() {
		znak = rand() % 2;
		x.fillRandom();
		y.fillRandom();
	}
};

int Rational::compare(Number &x) {
	if (typeid(x) == typeid(Rational)) {
		Rational &y = dynamic_cast<Rational&>(x);
		if ((this->wartosc / (double)this->mianownik) == (y.wartosc / (double)y.mianownik)) {
			return 0;
		}
		else if ((this->wartosc / (double)this->mianownik) < (y.wartosc / (double)y.mianownik)) {
			return -1;
		}
		else {
			return 1;
		}
	}
	else {
		Rational2D &y = dynamic_cast<Rational2D&>(x);
		return -y.compare(*this);
	}
}

void display(Number** tab, int n) {
	for (int i = 0; i < n; i++) {
		cout << tab[i]->toString() << endl;
	}
}

void fill(Number** tab, int n) {
	for (int i = 0; i < n; i++) {
		tab[i]->fillRandom();
	}
}

void sort(Number** tab, int n) {
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < n - 1; j++)	{
			if (tab[j]->compare(*tab[j + 1]) == 1) {
				swap(tab[j], tab[j + 1]);
			}
		}
	}	
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));

	Rational2D x, y;
	x.fillRandom();
	y.fillRandom();
	cout << x.toString() << endl << y.toString() << endl << x.compare(y) << endl << endl;

	Number* tab[10];
	for (int i = 0; i < 10; i++) {
		tab[i] = new Rational();
	}
	fill(tab, 10);
	display(tab, 10);
	cout << endl;	
	sort(tab, 10);
	display(tab, 10);
	cout << endl;
	for (int i = 0; i < 10; i++) {
		delete(tab[i]);
	}

	for (int i = 0; i < 10; i++) {
		tab[i] = new Rational2D();
	}
	fill(tab, 10);
	display(tab, 10);
	cout << endl;
	sort(tab, 10);
	display(tab, 10);
	cout << endl;
	for (int i = 0; i < 10; i++) {
		delete(tab[i]);
	}

	for (int i = 0; i < 5; i++) {
		tab[i] = new Rational();
	}
	for (int i = 5; i < 10; i++) {
		tab[i] = new Rational2D();
	}
	fill(tab, 10);
	display(tab, 10);
	cout << endl;
	sort(tab, 10);
	display(tab, 10);
	cout << endl;
	for (int i = 0; i < 10; i++) {
		delete(tab[i]);
	}

	int a;
	cin >> a;
	return 0;
}

