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
        bool searchByKey(T key);
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
    auto headData = head_->getData();
    head_ = std::move(head_->getManagedNext());
    return headData;
}

template<typename T> T LinkedList<T>::deleteLast()
{
    auto newLast = head_.get();
    while(newLast->getNext()->getNext())
    {
        newLast = newLast->getNext();
    }
    auto deletedNodeData = newLast->getNext()->getData();
    newLast->setNext(nullptr);
    return deletedNodeData;
}

template<typename T> bool LinkedList<T>::searchByKey(T key)
{
    auto temp = head_.get();
    while (temp)
    {
        if (temp->getData() == key)
            return true;
        else
            temp = temp->getNext();
    }
    return false;
}
#endif //ifndef LINKEDLIST_HPP_
