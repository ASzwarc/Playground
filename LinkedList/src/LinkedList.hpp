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
        void print() const;
        void insertAtBeginning(T data);
        void insertAtEnd(T data);
        T deleteFirst();
        T deleteLast();
        T deleteByKey();
        Node<T> searchByKey(T data);
    private:
        std::unique_ptr<Node<T>> head_;
};

template<typename T> LinkedList<T>::LinkedList(): head_{nullptr}
{
    std::cout << "CTOR" << std::endl;
}

template<typename T> void LinkedList<T>::print() const
{
}

template<typename T> void LinkedList<T>::insertAtBeginning(T data)
{
    auto newNode = new Node<T>(data);
    if (head_)
    {
        newNode->setNext(head_->getNext());
    }
    head_.reset(newNode);
}


#endif //ifndef LINKEDLIST_HPP_
