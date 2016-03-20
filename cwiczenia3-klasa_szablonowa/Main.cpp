#include "Tablica.hpp"
#include <iostream>


int main(int argc, char** argv)
{
    Tablica <int, 16>tab1(1);
    Tablica <float, 16> tab2(2.0);
    Tablica <float, 16> tab21(2.1);

    Tablica <double, 128> tab3(3.3);

    Tablica <char> tabA('a');
    Tablica <char> tabB(98);

    std::cout << tab1 << std::endl<<std::endl;

    tab1 = tab1 + 1;

    std::cout << tab1 << std::endl<<std::endl;

    tab2 = tab2 + tab21;

    std::cout << tab2 << std::endl<<std::endl;

    Tablica <float, 16> tab4 = tab2 * tab21;

    std::cout << tab4 << std::endl<<std::endl;

    std::cout<< "Finish!"<<std::endl;

    return 0;
}
