#include "CircularBuffer.hpp"
#include "Tablica.hpp"
#include <iostream>


int main(int argc, char** argv)
{

    CircularBuffer <int, 3> cbuffer;

    cbuffer.isEmpty();

    int x = 1;
    int y = 2;

    cbuffer.push_back(x);
    cbuffer.push_back(y);
    cbuffer.push_back(3);
    cbuffer.push_back(4);

    std::cout << cbuffer << std::endl;


    int aqq1, aqq2, aqq3, aqq4;

    cbuffer.pop_front(aqq1);
    cbuffer.pop_front(aqq2);
    cbuffer.pop_front(aqq3);
    cbuffer.pop_front(aqq4);

    std::cout << std::endl << " " << aqq1  << " " << aqq2 << " " << aqq3<< " " << aqq4<< std::endl<< std::endl;

    cbuffer.isEmpty();

    return 0;
}
