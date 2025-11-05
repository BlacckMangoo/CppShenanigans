#include <thread>
#include <iostream>
#include <vector>
#include <mutex>

std::mutex glock  ;



static  int counter = 0; // <- critical region ( atomic )
void incrementCounter()
{
    std::lock_guard<std::mutex> lock(glock); // automates the locking and unlocking of the mutex using RAII
    // we need to make sure that we unlock the mutex even if an exception occurs or else deadlock may occur
    try {
        counter = counter + 1;
        throw "danger";
    }catch (...) {
        std::cout << "Exception in incrementCounter()" << std::endl;
        return ;
    }
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

 // race condition
 // one thread may read the value of counter while another is writing to it

    // to fix use mutexes( binary semaphore )


    //Deadlock -> none of threads are able to proceed because each is waiting for a resource held by the other



}