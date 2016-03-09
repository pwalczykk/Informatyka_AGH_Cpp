#ifndef TABLICA_HPP_
#define TABLICA_HPP_

#define N 1024

#include <stdio.h>
#include <string.h>
#include <iostream>

class tablica
{
    double dane[N];

public:
    tablica();
    tablica(tablica &Tablica);
    ~tablica();

    bool set(int i, double val);

    bool get(int i);
};

#endif
