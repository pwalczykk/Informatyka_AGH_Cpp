#include <stdio.h>

template <typename T, int N> 

class Tablica{
    T tab[N];
public:
    Tablica(){};
    ~Tablica(){};

    void GetN(){
        for(int i =0; i<N; i++){
            printf("1");
        }
    }

    void GetN2(){
        printf("%d\n", N);
    }
};
