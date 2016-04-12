#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <mutex> // #include "pthread.h"

//#include <sys/types.h>
//#include <sys/syscall.h>

#include "ConcurrencyCircularBuffer.hpp"

using std::thread;
using std::vector;

struct ThreadItem{
    char* result;
    std::thread worker;
};

void printThread()
{
    std::cout<<std::this_thread::get_id()<<std::endl;
}

std::mutex mtx;

void* tfBasic(char** result)
{
    *result =  new char[256];
    snprintf(*result, 256, "Thread id: %ld", std::this_thread::get_id());
    //std::cout<<std::endl<<std::this_thread::get_id()<<std::endl;

// ATOMIC BLOCK !!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!TODO implementacja do ROSa
    mtx.lock();
    std::cout << "Hi " << std::this_thread::get_id() << "!" << std::endl;
    mtx.unlock();

    std::lock_guard<std::mutex> guard(mtx);
    std::cout << "Hi " << std::this_thread::get_id() << " again!" << std::endl << std::endl;
}

ConcurrencyCircularBuffer<int, 1024> cb;

std::once_flag flag;

void* tfPush(char** result){
    std::call_once(flag, []() {std::cout << std::endl << "Beggining tfPush" << std::endl;});
    int cnt = 0;
    for (int i = 0; i<100; i++)
        cnt += (cb.push_back(i) == true ? 1 : 0);
    *result = new char[256];
    snprintf(*result, 256, "thread with ID %ld PUSHED %ld items", std::this_thread::get_id(), cnt);
}

void* tfPull(char** result){
    std::call_once(flag, []() {std::cout << std::endl << "Beggining tfPull" << std::endl;});
    int j, cnt = 0;
    for(int i = 0; i < 100; i++)
        cnt += (cb.pop_front(j) == true ? 1 : 0);
    *result = new char[256];
    snprintf(*result, 256, "thread with ID %ld PULLED %ld items", std::this_thread::get_id(), cnt);
}

void testThreadsBasic(){
    // Get n cores
    int n = std::thread::hardware_concurrency();

    // Array of threads
    std::vector<ThreadItem> threads;
    threads.resize(n);

    // Spawn threads
    for(int i = 0; i < n; i++){
        threads[i].worker = std::thread(tfPull, &threads[i].result);
    }

    // Wait for threads to finish
    for(int i = 0; i < n; i++){
        threads[i].worker.join();
    }

    printf("Result:\n");
    for(int i = 0; i<n; i++){
        printf("%s\n",threads[i].result);
    }
}


int main()
{
    testThreadsBasic();
    return 0;
}
