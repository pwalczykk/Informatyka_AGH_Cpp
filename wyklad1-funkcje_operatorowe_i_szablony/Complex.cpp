#include "Complex.hpp"

Complex::Complex(double Re, double Im)
{
    this->Re = Re;
    this->Im = Im;
}

// Funkcje operatorowe
Complex& Complex::operator+(const Complex& r)
{
    Complex c(Re + r.Re, Im + r.Im);
    return c;
}

Complex& Complex::operator-(const Complex& r)
{

}

Complex& Complex::operator=(const Complex& r)
{
    return *this;
}
