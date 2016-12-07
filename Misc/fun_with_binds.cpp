#include <iostream>
#include <functional>
#include <string>

void function(int first, double second, std::string third)
{
    if (first == 1)
    {
        std::cout << "First was equal to one" << std::endl;
    }
    std::cout << second << " " << third << std::endl;
}

void fun_with_bind(std::function<void(double, std::string)> foo, 
                   double second, 
                   std::string third)
{
    foo(second, third);
}

class Base
{
public:
    Base(int val): val_{val}
    {}
    
    void printVal(double one, std::string two)
    {
        std::cout << one << " " << two << std::endl;
        std::cout << "Val is: " << val_ << std::endl;
    }
private:

    void printValFromPrivate(double one, std::string two)
    {
        std::cout << "Private function" << std::endl;
    }
    int val_;
};

int main()
{

    fun_with_bind(std::bind(function, 
                            1, 
                            std::placeholders::_1, 
                            std::placeholders::_2), 
                  2.2, "third");

    std::cout << "Lets check lambdas: " << std::endl;

    fun_with_bind([](double two, std::string three){
            std::cout << two << " " << three << std::endl;
            }, 3.3, "fourth");


    std::cout << "Lets try to bind class method" << std::endl;
    Base base(93);
    std::shared_ptr<Base> base_ptr = std::make_shared<Base>(94);
    fun_with_bind(std::bind(&Base::printVal, base_ptr, 4.4, "fifth"), 5.5, "sixth");
    
    return 0;
}
