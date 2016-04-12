#ifndef CIRCULARBUFFER_HPP_
#define CIRCULARBUFFER_HPP_

#include "Tablica.hpp"

template <typename T, unsigned N = 1024>

class CircularBuffer : public Tablica <T,N>
{
    bool can_overwerite = true;
    int next_pop = 0, next_push = 0;
public:
    CircularBuffer() : Tablica <T,N>(){};
    virtual ~CircularBuffer(){};

    bool isEmpty(){
        for(int i = 0; i < N; i++)
        {
            if(Tablica<T,N>::dane[i])
            {
                std::cout << " Buffor is not empty!" <<std::endl;
                return false;
            }
        }
        std::cout << " Buffor is empty!" <<std::endl;
        return true;
    }

    // dokłada do konca
    bool push_back(const T& item){
        try{
            Tablica<T,N>::dane[next_push] = item;
            next_push++; if(next_push == N) next_push = 0;
        }catch(...){
            return false;
        }
        return true;
    }

    // zdejmuje z począku
    bool pop_front(T& item){
        try{
            item = Tablica<T,N>::dane[next_pop];
            next_pop++; if(next_pop == N) next_pop = 0;
        }catch(...){
            return false;
        }
        return true;
    }
};

#endif
