#include <iostream>
#include <thread>
#include <string>
#include <vector>


struct ThreadItem{
    char* result;
    std::thread worker;
};

void printThread()
{
    std::cout<<std::this_thread::get_id()<<std::endl;
}

void* tfBasic(char** result)
{
    *result =  new char[256];
    snprintf(*result, 256, "Thread id:", std::this_thread::get_id());
    std::cout<<std::endl<<std::this_thread::get_id()<<std::endl;
}

void testThreadsBasic(){
    int n = std::thread::hardware_concurrency();

    std::vector<ThreadItem> threads;
    threads.resize(n);

    for(int i = 0; i < n; i++){
        threads[i].worker = std::thread(tfBasic, &threads[i].result);
    }

    for(int i = 0; i < n; i++){
        threads[i].worker.join();
    }
}

int main()
{
    testThreadsBasic();
    return 0;
}
