#include <memory>

#include "Complex.hpp"
#include "Tablica.hpp"

void UseRawPointer()
{
    Complex* p = new Complex(1,2);
    p->Info();
    if(p) delete(p);
}

void UseSmartPointer()
{
    std::unique_ptr<Complex> p(new Complex(5,7));
    p->Info();

    std::unique_ptr<Tablica<int,10>> t1(new Tablica<int,10>);

    std::unique_ptr<Tablica<int,20>> t2(new Tablica<int,20>(10));

}

class WithUniquePtr{
    std::unique_ptr<Complex> p1;
public:
    WithUniquePtr(double re, double im) : p1(new Complex(re, im)){
    }

    void Info()
    {
        p1->Info();
    }
};

void SmartInfo(std::shared_ptr<Complex>& ptr){
    ptr->Info();
}

int main(){
    UseRawPointer();
    UseSmartPointer();

    WithUniquePtr w(7.5, 4.6);

    w.Info();

    Complex* c = new Complex(9.8, 2.11);
    std::shared_ptr<Complex> p2(new Complex(123, 456));
    

    SmartInfo(p2);

    return 0;
}
