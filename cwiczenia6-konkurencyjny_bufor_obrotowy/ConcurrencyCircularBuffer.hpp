#include "CircularBuffer.hpp"
#include <mutex>

template <typename T, unsigned N = 1024 > class ConcurrencyCircularBuffer;

template <typename T, unsigned N>
class ConcurrencyCircularBuffer : public CircularBuffer<T,N>{
    std::mutex mtx;
public:
    ConcurrencyCircularBuffer() : CircularBuffer<T,N>(){};

    virtual ~ConcurrencyCircularBuffer(){};

    bool push_back(const T& item){
        std::lock_guard<std::mutex> guard(mtx);   
        return CircularBuffer<T,N>::push_back(item);
    }

    bool pop_front(T& item){
        std::lock_guard<std::mutex> guard(mtx);
        return CircularBuffer<T,N>::pop_front(item);
    }
};
