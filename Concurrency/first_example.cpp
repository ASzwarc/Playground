#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>

struct Counter
{
    Counter():
        val_{0}
    {}

    void increment()
    {
        ++val_;
    }

    void decrement()
    {
        if (val_ <= 0)
        {
            throw "Value can't be less than zero";
        }
        val_--;
    }

    int val_;
};


struct ConcurrentCounter
{
    void increment()
    {
        std::lock_guard<std::mutex> guard(mutex_);
        counter_.increment();
    }

    void decrement()
    {
        std::lock_guard<std::mutex> guard(mutex_);
        try
        {
            counter_.decrement();
        }
        catch (const char* what)
        {
            std::cout << "Exception: " << what << std::endl;
            throw what;
        }
    }
    
    Counter counter_;
    std::mutex mutex_;
};

int main()
{
    ConcurrentCounter counter;

    std::vector<std::thread> threads;

    for (int i = 0; i < 5; i++)
    {
        threads.push_back(std::thread([&counter](){
            std::cout << "Incrementing counter from thread:  " 
                      << std::this_thread::get_id() << std::endl;
            for (int i = 0; i < 100; i++)
            {
                counter.increment();
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                counter.decrement();
            }
            try
            {
                counter.decrement();
            }
            catch(const char* what)
            {
                std::cout << "Exception caught: " << what << std::endl;
            }
        }));
    }

    for (auto& thread : threads)
    {
        thread.join();
    }
    
    std::cout << "Value of counter: " << counter.counter_.val_ << std::endl;

    return 0;
}
