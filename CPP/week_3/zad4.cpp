#include <iostream>
#include <typeinfo>
using namespace std;


template<typename T>
class Some{
    T k;
};


template<template <typename> typename C, typename K>
int say(C<K> arg){
    cout << typeid(K).name() << endl;

}

int main(){

    Some<int> k;
    Some<double> z;
    Some<Some<int>> wtf;

    say(k);
    say(z);
    say(wtf);

}
