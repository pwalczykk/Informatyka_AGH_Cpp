#ifndef COMPLEX_HPP_
#define COMPLEX_HPP_

#include <iostream>

 class Complex{
 protected:
     double re;
     double im;
 public:
     Complex(double re, double im)
     {
         this->re = re;
         this->im = im;
     }

     void Info()
     {
         std::cout << re << "  " << im <<std::endl;
     }
 };

#endif
