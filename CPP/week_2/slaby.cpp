#include <iostream>

using namespace std;

class Node {
public:
    virtual double operator()(double x) const =0;
};

class Constant : public Node {
private:
    double value;
public:
    Constant(double x) {
        value = x;
    }

    double operator()(double x) const {
        return value;
    }
};

class Variable : public Node {
public:
    virtual double operator()(double x) const {
        return x;
    }
};

class Add : public Node {
public:
    Node *left, *right;

    Add(Node *l, Node *r) {
        this->left = l;
        this->right = r;
    }

    double operator()(double x) const {
        return this->right->operator()(x) + this->left->operator()(x);
    }

    ~Add() {
        delete this->left;
        delete this->right;
    }
};

class Mul : public Node {
    Node *left;
    Node *right;
public:
    Mul(Node *l) {
        left = l;
    }

    Mul(Node *l, Node *r) {
        left = l;
        right = r;
    }

    double operator()(double x) const {

        return this->left->operator()(x) * this->right->operator()(x);
    }

    ~Mul() {
        delete this->left;
        delete this->right;
    }

};

class Function : public Node {
private:
    Node *x;
public:
    Function(const Function &object) {
        std::cout << "Copy constructor allocating ptr." << endl;
        *x = object;
    }

    Function(Node *arg) {
        x = arg;
    }

    double operator()(double x) const {
        return this->x->operator()(x);
    }

    ~Function() {
        delete this->x;
    }

};

int main() {

    // Zad 1
    Node *a = new Mul(new Add(new Variable(), new Constant(2)), new Variable());
    std::cout << (*a)(3) << "\n";
    a = new Mul(a, new Variable());
    delete a;
    // Zad 2
    Function f = new Mul(new Add(new Variable(), new Constant(2)), new Variable());
    std::cout << f(3) << "\n";
    return 0;
}