// Dziedziczenie
    // wirtualne - nie włączamy wielokrotnie tych samych składników
    // public,protected,private - jak w klasach

    // W konstruktorze muszą być argumenty dla odziedziczonych konstruktorów (naipier virtuale, potem reszta po kolei)

#include "Complex.hpp"
#include <cstring>
//class Nazwa : Lista_dziedziczenia
//{
//};
// ComplexNamed dziedziczy pola z klasy Complex, i dodaje imie
class ComplexNamed : public Complex {
    char* name;
public:
    ComplexNamed(char* name, double re, double im) : Complex(re, im)
    {
        this->name = name;
    }

    void Info()
    {
        std::cout << name << "  " << re << "  " << im << std::endl;
    }
};

int main()
{
    ComplexNamed CN("aqqq", 10, 20);

    CN.Info();
}
