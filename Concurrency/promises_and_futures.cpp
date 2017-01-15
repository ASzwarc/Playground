#include <iostream>
#include <string>
#include <thread>
#include <future>

void someFunction(std::promise<std::string>& prms)
{
	try
	{
		std::string str("Hello from future !");
		throw(std::exception());
		prms.set_value(str);
	}
	catch(...)
	{
		prms.set_exception(std::current_exception());
	}
}

int main()
{
	std::promise<std::string> prms;
	std::future<std::string> ftr = prms.get_future();
	std::thread thread1(&someFunction, std::ref(prms));
	std::cout << "Hello from main thread !" << std::endl;
	try
	{
		std::string received = ftr.get();
		std::cout << received << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	thread1.join();
	return 0;
}