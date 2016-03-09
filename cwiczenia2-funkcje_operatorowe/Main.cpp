#include "Tablica.hpp"


int main(int argc, char** argv)
{
    Tablica T1(1);              T1.Print();
    Tablica T2(10);             T2.Print();

// Podstawowe operatory
    Tablica T3(10); T3+T2;      T3.Print();
    Tablica T4(10); T4-T2;      T4.Print();
    Tablica T5(10); T5*T2;      T5.Print();

// Odczyt
    std::cout << T5[4] <<std::endl;

// Podstawienie
    T5[0]=666;                T5.Print();

    return 0;
}
