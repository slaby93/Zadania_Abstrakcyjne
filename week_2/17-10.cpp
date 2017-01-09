/*
 * 17-10.cpp
 * 
 * Copyright 2016 Lukasz Jozef Papierz <z1105168@s0059-18>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <iostream>
using namespace std;

class Add;
class Mul;
class Node {
	public:
	    //metoda jest czysto wirtualna
		virtual double operator()(double x) const = 0;
		Add operator+(Node &x);
		Mul operator*(Node &x);
};

class Variable : public Node {
	public:
	    //funkcja z const nie modyfikuje obiektu
		virtual double operator()(double x) const {
			return x;
		}
};
class Add: public Node {
		Node * left, * right;
	public:
		Add(Node * l, Node * r) : left(l), right(r) {}
		double operator()(double x) const {
			return (*left)(x)+(*right)(x);
		}
		/*~Add() {
			delete left;
			delete right;
		}*/
};

class Mul: public Node {
		Node *left, *right;
	public:
		Mul(Node * l, Node * r) : left(l), right(r) {}
		double operator()(double x) const {
			return (*left)(x)*(*right)(x);
		}
		/*~Mul() {
			delete left;
			delete right;
		}*/
};
class Constant: public Node {
	double constant;
	public:
		Constant(double x) : constant(x) {}
		double operator()(double x) const {
			return constant;
		}
};
class Function: public Node {
	public:
		double operator()(double x) const {
			return (*this)(x);
		}
		
};
Add Node::operator+(Node &x) {
	Add *add = new Add(this, &x);
	return *add;
}
Mul Node::operator*(Node &x) { 
	
	Mul *mul = new Mul(this, &x);
	return *mul;
}

int main() {
	
	//zadanie 1
	//Node *a = new Mul( new Add(new Variable(), new Constant(4)), new Variable());
	//cout << (*a)(3) << endl;
	//a = new Mul(a, new Variable());
	//delete a;
	
	
	//zadanie 2
	//Node *f = new Function();
	//f = new Mul(new Add(new Variable(), new Constant(2)), new Variable());
	//cout << (*f)(3) << endl;
	//delete f;
	
	//zadanie 3
	Variable x;
	Mul f = x * x + x * 3;
	cout<< f(2.0)<< endl;
 	//cout<< f(5.0) << endl;

	return 0;
}

