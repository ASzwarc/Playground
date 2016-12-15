#include <iostream>
#include <memory>

void foo(std::shared_ptr<int> ptr)
{
    std::cout << "Value of shared_ptr: " << *ptr << std::endl;
}

void bar(std::unique_ptr<int> ptr)
{
    std::cout << "Value of unique_ptr: " << *ptr << std::endl;
}


int main()
{
    int value(1);

    std::shared_ptr<int> shared(&value);
    std::unique_ptr<int> uniq = std::make_unique<int>(2);

    std::shared_ptr<int> shared2(std::move(uniq));
    foo(shared2);
    return 0;
}
