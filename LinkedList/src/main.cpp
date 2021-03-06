#include <iostream>
#include "LinkedList.hpp"

int main(int argc, char* argv[])
{

    LinkedList<int> testList;
    testList.insertFirst(2);
	testList.insertFirst(3);
    testList.insertFirst(4);
    testList.print();
    testList.insertLast(5);
    testList.print();
    std::cout << "Deleted node: " << testList.deleteLast() << std::endl;
    testList.print();
    if (testList.searchByKey(2))
        std::cout << "Node exists" << std::endl;
    else
        std::cout << "Couldn't find node" << std::endl;
    std::cout << "Deleted node: " << testList.deleteFirst() << std::endl;
    testList.print();
    testList.deleteByKey(2);
    testList.print();
    return 0;
}
