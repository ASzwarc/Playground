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
        T deleteByKey(T data);
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
    auto temp = head_.get();
    std::cout << "Nodes: ";
    while (temp)
    {
        std::cout << temp->getData() << " ";
        temp = temp->getNext();
        if (temp)
            std::cout << "-> ";
    }
    std::cout << std::endl;
}

template<typename T> void LinkedList<T>::insertAtBeginning(T data)
{
    auto newNode = std::make_unique<Node<T>>(data);
    if (head_)
    {
        newNode->setNext(head_.release());
    }
    head_ = std::move(newNode);
}

template<typename T> void LinkedList<T>::insertAtEnd(T data)
{
    auto newNode = std::make_unique<Node<T>>(data);
    auto last = head_.get();
    while (last->getNext())
    {
        last = last->getNext();
    }
    last->setNext(newNode.release());
}

template<typename T> T LinkedList<T>::deleteFirst()
{
}

template<typename T> T LinkedList<T>::deleteLast()
{
    auto newLast = head_.get();
    while(newLast->getNext()->getNext())
    {
        newLast = newLast->getNext();
    }
    std::unique_ptr<Node<T>> deletedNode{newLast->getNext()};
    newLast->setNext(nullptr);
    return deletedNode->getData();
}
#endif //ifndef LINKEDLIST_HPP_
