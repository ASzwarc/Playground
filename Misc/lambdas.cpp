#include <iostream>
#include <memory>

int main()
{
	int i = 0;

	//it's possible to incerement variable passed by value by adding a "mutable" specification
	auto first_lambda = [=]() mutable -> int
	{
		++i;
		std::cout << "Value of i is: " << i << std::endl;
		return i;
	};

	auto output = first_lambda();
	std::cout << "Output is: " << output << std::endl;

	int j = 0;

	auto second_lambda = [&, j = 5]()
	{
		std::cout << "Value of j in lambda is: " << j << std::endl;
		return j;
	};

	std::cout << "Value of j is: " << j << std::endl;
	std::cout << "Value of j is: " << second_lambda() << std::endl; 
	std::cout << "Value of j in main is: " << j << std::endl; 
	
	std::cout << "Example from cppreference" << std::endl;

	int x = 4;
	std::cout << "Return value is: " << [&r = x, x = x + 1]()-> int
    {
        r += 2;
        return x * x;
    }() << std::endl;
    
    std::cout << "Value of x is: " << x << std::endl;

    struct pod
    {
    	pod(int var):
    		someVariable_{var}
    	{}
    	int someVariable_;
    	auto fun()
    	{
    		return [this](){return someVariable_;}();
    	}
    	auto fun_two()
    	{
    		return [this](){return ++someVariable_;}();
    	}
    	// It should be available in c++17
    	/*
    	auto fun_three()
    	{
    		return [*this](){return ++someVariable_;}();
    	}
    	*/
    };

    pod temp(5);
    std::cout << "Value of pod's member is: " << temp.fun() << std::endl;
    std::cout << "And now value od pod's member is: " << temp.fun_two() << std::endl;


    std::cout << "Last example:" << std::endl;
    auto third_lambda = [i = 0, p = std::make_unique<int>(3)]() mutable { return ++i;};

    std::cout << third_lambda() << std::endl;
    std::cout << third_lambda() << std::endl;

    //This is not allowed because you can't copy unique_ptr!
    // auto lambda_copy = third_lambda;
	return 0;


}