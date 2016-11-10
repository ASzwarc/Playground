#include <iostream>
#include "LinkedList.hpp"

int main(int argc, char* argv[])
{

    LinkedList<int> testList;
    testList.insertAtBeginning(2);
	testList.insertAtBeginning(3);
    testList.insertAtBeginning(4);
    testList.print();
    return 0;
}
