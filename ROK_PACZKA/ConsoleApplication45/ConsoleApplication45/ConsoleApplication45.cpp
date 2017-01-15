// ConsoleApplication45.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Node {
public:
	virtual double df(double x) const = 0;

	virtual double operator()(double x) const = 0;

	virtual Node* clone() = 0;
};

class Add : public Node {
	Node *left, *right;
public:
	Add(Node *l, Node *r) : left(l), right(r) {}

	Add(Add &&x) : left(x.left), right(x.right) {
		x.left = nullptr;
		x.right = nullptr;
	}

	virtual ~Add() {
		delete(left);
		delete(right);
	}

	double df(double x) const {
		return left->df(x) + right->df(x);
	}

	double operator()(double x) const {
		return (*left)(x)+(*right)(x);
	}

	Node* clone() {
		Add *x = new Add(nullptr, nullptr);
		x->left = this->left->clone();
		x->right = this->right->clone();
		return x;
	}
};

class Mul : public Node {
	Node *left, *right;
public:
	Mul(Node *l, Node *r) : left(l), right(r) {}

	Mul(Mul &&x) : left(x.left), right(x.right) {
		x.left = nullptr;
		x.right = nullptr;
	}

	virtual ~Mul() {
		delete(left);
		delete(right);
	}

	double df(double x) const {
		return left->df(x) * (*right)(x)+(*left)(x)* right->df(x);
	}

	double operator()(double x) const {
		return (*left)(x)* (*right)(x);
	}

	Node* clone() {
		Mul *x = new Mul(nullptr, nullptr);
		x->left = this->left->clone();
		x->right = this->right->clone();
		return x;
	}
};

class Constant : public Node {
private:
	int value;
public:
	Constant(int value) : value(value) {}

	double df(double x) const {
		return 0;
	}

	double operator()(double x) const {
		return value;
	}

	Node* clone() {
		return new Constant(*this);
	}
};

class Variable : public Node {
public:
	double df(double x) const {
		return 1;
	}

	double operator()(double x) const {
		return x;
	}

	Node* clone() {
		return new Variable();
	}
};

template<class X>
Add operator+(const Constant &l, X &r) {
	return Add(new Constant(l), new X(move(r)));
}

template<class X>
Add operator+(X &l, const Constant &r) {
	return Add(new X(move(l)), new Constant(r));
}

template<class X>
Mul operator*(const Constant &l, X &r) {
	return Mul(new Constant(l), new X(move(r)));
}

template<class X>
Mul operator*(X &l, const Constant &r) {
	return Mul(new X(move(l)), new Constant(r));
}

template<class X, class Y>
Add operator+(X &l, Y &r) {
	return Add(new X(move(l)), new Y(move(r)));
}

template<class X, class Y>
Mul operator*(X &l, Y &r) {
	return Mul(new X(move(l)), new Y(move(r)));
}

class FunctionDerivative {
	Node *pointer;
public:
	FunctionDerivative(Node *source) : pointer(source) {}

	double operator()(double x) const {
		return pointer->df(x);
	}
};

class Function {
	Node *pointer;
public:
	Function(Node *source) : pointer(source) {}

	Function(Add source) : pointer(new Add(move(source))) {}

	Function(Mul source) : pointer(new Mul(move(source))) {}

	virtual ~Function() {
		delete(pointer);
	}

	double operator()(double x) const {
		return (*pointer)(x);
	}

	FunctionDerivative derivative() {
		return FunctionDerivative(pointer);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Variable x;
	Function f = x * x + x * 3;
	FunctionDerivative df = f.derivative();
	std::cout << f(2.0) << "\n\n";
	std::cout << f(5.0) << "\n\n";
	std::cout << df(2.0) << "\n\n";
	std::cout << df(5.0) << "\n\n";
	int a;
	cin >> a;
	return 0;
}