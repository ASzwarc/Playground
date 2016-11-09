#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include <memory>
#include <iostream>
#include "Node.hpp"

template<typename T>
class LinkedList
{
    public:
        LinkedList();
        void print();
        void insertAtBeginning(T data);
        void insertAtEnd(T data);
        T deleteFirst();
        T deleteLast();
        T deleteByKey();
        void searchByKey(T data);
    private:
        std::unique_ptr<Node<T>> head_;
};

template<typename T> LinkedList<T>::LinkedList(): head_{nullptr}
{
    std::cout << "CTOR" << std::endl;
}


#endif //ifndef LINKEDLIST_HPP_
