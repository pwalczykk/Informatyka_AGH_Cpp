#include <stdio.h>
#include "Complex.hpp"
#include "Tablica.hpp"
#include "Temp.hpp"

int main(int argc, char** argv)
{
    Complex c(1,0);
    Complex h(2,0);

    Complex x=c+h;
    Complex y=x;

    printf("%f\n",y.Re);

    Tablica <double, 13>tab;
    printf("\n\n\n");
    tab.GetN();
    printf("\n\n\n");
    tab.GetN2();

    Temp <Complex>templacik;

    templacik.tab[3].Set(4,5);
    printf("\n\n\n");

    templacik.tab[3].ReadComplex();
    printf("\n\n\n");


    return 0;
}
