#include <atomic>
#include <thread>
#include <iostream>
#include <vector>

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


}