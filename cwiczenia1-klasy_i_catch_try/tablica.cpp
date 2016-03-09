#include "tablica.hpp"

tablica::tablica(){
    std::cout<<"Konstruktor"<<std::endl;

}

tablica::tablica(tablica &Tablica){
    memcpy(this->dane, Tablica.dane, N*sizeof(double));
    std::cout<<"Konstruktor kopiujący"<<std::endl;
}

tablica::~tablica(){
    std::cout<<"Destruktor"<<std::endl;
}

bool tablica::set(int i, double val){
    if((i < 0) || (i > N))
    throw i;

    this->dane[i]=val;
    return true;
}

bool tablica::get(int i){
    if((i < 0) || (i > N)){
        const char* aqq = "EXCEPTION !!!";
        throw aqq;
    }
    std::cout<<dane[i]<<std::endl;
    return true;
}
