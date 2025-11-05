//
// Created by lenovo on 01-11-2025.
//

#include <iostream>
#include <thread>

// launching a thread

int add(int const a, const int b) {
    std::cout << "added two numbers and answer is " <<  a+b << std::endl;
    return a + b;
}

class Functor {
public:
     void  operator()() const {
         std::cout << "did something" << std::endl;

    };
};

int main() {

    // using a function pointer to launch a thread

    std::thread t1(add, 5, 6);
    t1.join(); // wait for the thread to finish



    // using a functor to launch a thread

    Functor f ;
    std::thread t2(f);

    t2.join(); // wait for the thread to finish

    // using a lambda expression to launch a thread

    auto add = [](int const a,int const  b) { std::cout << "added two numbers using lambda and answer is " << a + b << std::endl;};
    std::thread t3(add, 7, 8);
    std::cout << std::this_thread::get_id() << "is joinable" << (t2.joinable() ? "true" : "false" )<< std::endl;
    t3.join(); // wait for the thread to finish
     // join only if joinable

    //jthread(RAII)










};