#ifndef TABLICA_HPP_
#define TABLICA_HPP_
#include <iostream>
#include <cstring>

template <typename T, int N = 1024>

class Tablica{
    T dane[N];
public:
    Tablica(){
        std::memset(&dane, 0, sizeof(T)*N);

        std::cout << "tablica o " << N << " elementach, wielkości " << sizeof(T)*N << std::endl<<std::endl;
    }

    Tablica(T t){
        std::memset(&dane, 0, sizeof(dane));
        dane[0] = t;

        std::cout << "tablica o " << N << " elementach, wielkości " << sizeof(dane) << std::endl;
        std::cout << "pierwszy element: " << dane[0] << std::endl<<std::endl;
    }

    ~Tablica(){}

    Tablica operator + (T offset){
        Tablica tmp;
        int i;
        for(i = 0; i < N; i++){
            tmp.dane[i] = dane[i] + offset;
        }
        return tmp;
    }

    Tablica& operator + (const Tablica& t)
    {
        for(int i = 0; i < N; i++)
        {
            dane[i] += t.dane[i];
        }
        return* this;
    }

    Tablica operator * (const Tablica& t)
    {
        Tablica tmp;

        for(int i = 0; i < N; i++)
        {
            tmp.dane[i] = (this->dane[i] + t.dane[i] + 1) * 100;
        }
        return tmp;
    }

    friend std::ostream& operator << (std::ostream& os, const Tablica<T,N>& t)
    {
        os << std::endl;
        for(auto & d : t.dane)
            os << " " << d;
        return os;
    }

    friend std::istream& operator >> (std::istream& is, const Tablica<T,N>& t)
    {
        int nr = 0;
        for(auto& d : t.dane)
        {
            std::cout << "enter element number" << nr << ":";
            nr++;
            is >> t.dane[nr]; //?
        }
        return is;

    }

};

#endif
