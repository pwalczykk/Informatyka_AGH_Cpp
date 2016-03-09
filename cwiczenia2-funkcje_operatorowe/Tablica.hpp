#ifndef TABLICA_HPP_
#define TABLICA_HPP_

#define N 10

#include <iostream>

class Tablica
{
    int tab[N];
public:
    Tablica(){};
    Tablica(int add);
    ~Tablica(){};

    void Print();

    Tablica& operator+(const Tablica& t);
    Tablica& operator-(const Tablica& t);
    Tablica& operator*(const Tablica& t);

    int& operator[] (int at);
};

#endif
