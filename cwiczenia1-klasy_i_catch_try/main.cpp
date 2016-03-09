#include <iostream>
#include <cstdlib>

#include "tablica.hpp"

int main(int args, char** argv)
{
    tablica tab1;

    tab1.set(1,1234.5678);

    tablica tab2(tab1);

    tab2.get(1);

    try{
        tab1.set(1,453);
        tab1.get(-1);
    }catch(int i){
        std::cout<<"    BŁĄD INT!!!   "<< i <<std::endl;
    }catch(const char* msg){
        std::cout<< "INNY BŁĄD: "<<msg<<std::endl;
    }catch(...){
        std::cout<<"JESZCZE INNY BŁĄD"<<std::endl;
    }

    return 0;
}
