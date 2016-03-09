#include "Tablica.hpp"

Tablica::Tablica(int add)
{
    int number = 0;

    for(int i = 0; i<N; i++)
    {
        number += add;
        tab[i]=number;
    }
}

void Tablica::Print()
{
    for(int i = 0; i < N; i++)
    {
        std::cout<<tab[i]<< " ";
    }
    std::cout<< " \t\t "<< this <<std::endl;
}

Tablica& Tablica::operator+(const Tablica& t)
{
    for(int i = 0; i < N; i++)
    {
        tab[i] += t.tab[i];
    }
    return* this;
}

Tablica& Tablica::operator-(const Tablica& t)
{
    for(int i=0; i<N; i++)
    {
        tab[i] -= t.tab[i];
    }
    return *this;
}

Tablica& Tablica::operator*(const Tablica& t)
{
    for(int i=0; i<N; i++)
    {
        tab[i] *= t.tab[i];
    }
    return *this;
}

int& Tablica::operator[](int at)
{
        if(at < 0 || at > N)
            exit(-1);          // Działa prawie jak throw a któtsze :)

        return tab[at];
}
