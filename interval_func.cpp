#include <iostream>
#include <chrono>
#include <thread>
#include <functional>

void timer_start(std::function<void(void)> func, unsigned int interval)
{
    std::thread([func, interval]()
    {
        while (true)
        {
            auto x = std::chrono::steady_clock::now() + std::chrono::milliseconds(interval);
            func();
            std::this_thread::sleep_until(x);
        }
    }).detach();
}

void do_something1()
{
    std::cout << "*****************" << std::endl;
    std::cout << "I am doing something" << std::endl;
    std::cout << "-------------------" << std::endl;
}

void do_something2()
{
    std::cout << "MinhTuan" << std::endl;
}

int main()
{
//    timer_start(do_something, 1000);
    std::thread t1(timer_start, do_something1, 1000);
    std::thread t2(timer_start, do_something2, 5000);
    t1.join();
    t2.join();
    while(true);
}
