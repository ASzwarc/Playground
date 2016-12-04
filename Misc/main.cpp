#include <iostream>
#include <memory>

struct One
{
    One(int par): number{par}
    {
        std::cout << "One::CTOR" << std::endl;
    }

    ~One()
    {
        std::cout << "One::DTOR" << std::endl;
    }

    int number;
};

struct Two
{
    Two(int par): number{par}
    {
        std::cout << "Two::CTOR" << std::endl;
    }

    ~Two()
    {
        std::cout << "Two::DTOR" << std::endl;
    }

    int number;
};


class Base
{

    public:
        Base(): oneStruct_{3}
        {
            std::cout << "Base::CTOR" << std::endl;
        }
        ~Base()
        {
            std::cout << "Base::DTOR" << std::endl;
        }
    private:
        One oneStruct_;
        Two twoStruct_{2};
};

class Derived: public Base
{
    public:
        Derived(): oneStruct_(5)
        {
            std::cout << "Derived::CTOR" << std::endl;
        }
        ~Derived()
        {
            std::cout << "Derived::DTOR" << std::endl;
        }
    private:
        One oneStruct_;

};


int main()
{
    {
        std::cout << "Test nr 1" << std::endl;
        Derived dupa;
    }
    {
        std::cout << std::endl;
        std::cout << "Test nr 2" << std::endl;
        std::shared_ptr<Base> basePtr = std::make_shared<Derived>();
    }
    {
        std::cout << std::endl;
        std::cout << "Test nr 3" << std::endl;
        std::shared_ptr<Base> basePtr(static_cast<Base*>(new Derived)); 
    }
    {
        std::cout << std::endl;
        std::cout << "Test nr 4" << std::endl;
        std::unique_ptr<Base> baseUniqPtr = std::make_unique<Derived>();
    }
    {
        std::cout << std::endl;
        std::cout << "Test nr 5" << std::endl;
        Base* baseRawPtr = new Derived();
        std::cout << "Deleting object" << std::endl;
        delete baseRawPtr;
    }
    return 0;
}
