#include <global.h>

namespace
{
void threadFunction(int id, std::mutex* mutex) {  
    std::lock_guard<std::mutex> lock(*mutex);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
void test_1()
{
    const int numThreads = 3;
    
    std::thread threads[numThreads];
    std::mutex* mutex = new std::mutex();
    //the mutex is shared data between all threads. make sure the mutex
    //is destructed after all threads have been destructed.
    //tie the lifetime of the mutex to that of the threads.
    //right now, the mutex is leaked. Only changes to the mutex type are needed.
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = std::thread(threadFunction, i + 1, mutex);
    }
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }
} 
}
 
void conc_ex1()
{     
    test_1();
}