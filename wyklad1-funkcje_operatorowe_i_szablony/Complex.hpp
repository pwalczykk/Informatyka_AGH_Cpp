#ifndef COMPLEX_HPP_
#define COMPLEX_HPP_

#include <fstream>

class Complex{
public:
    double Re;
    double Im;
public:
    Complex(){};
    Complex(double, double);
    ~Complex(){};

    void Set(double Re, double Im)
    {
        this->Re = Re;
        this->Im = Im;
    }
    void ReadComplex(){printf("%f %f", Re, Im);}

    Complex& operator+(const Complex& r);
    Complex& operator-(const Complex& r);
    Complex& operator=(const Complex& r);

};

#endif
