#include <atomic>
#include <condition_variable>
#include <thread>
#include <iostream>
#include <vector>
#include <mutex>


std::mutex glock  ;
std::condition_variable gConditionVar ;

static  std::atomic<int> counter = 0; // <- critical region ( atomic )
void incrementCounter()
{
   ++counter;
}
int main() {

    std::vector<std::thread> threads;
    threads.reserve(1000);
    for ( int i = 0 ; i < 1000 ; i++) {
        threads.emplace_back(incrementCounter);
    }
    for ( int i = 0 ; i < 1000 ; i++) {
        threads[i].join();
    }
    std::cout << "Final Counter Value: " << counter << std::endl;

    // synchronisation
    // condition variable - >

    bool notified = false;
    int result = 0 ;

    // reporting thread

    std::thread reporter([&]{
    });


    //working thread

    std::thread worker([&] {
        std::unique_lock<std::mutex> lock(glock);

    });








}