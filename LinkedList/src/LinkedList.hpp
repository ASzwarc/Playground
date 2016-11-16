#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include <memory>
#include <iostream>
#include <stdexcept>
#include "Node.hpp"

template<typename T>
class LinkedList
{
    public:
        LinkedList();
        void print() const;
        void insertFirst(T data);
        void insertLast(T data);
        T deleteFirst();
        T deleteLast();
        bool deleteByKey(T key);
        bool searchByKey(T key);
        unsigned int size();
    private:
        std::unique_ptr<Node<T>> head_;
        unsigned int size_;
};

template<typename T> LinkedList<T>::LinkedList(): head_{nullptr}, size_{0}
{
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

template<typename T> void LinkedList<T>::insertFirst(T data)
{
    auto newNode = std::make_unique<Node<T>>(data);
    if (head_)
    {
        newNode->setNext(head_.release());
    }
    head_ = std::move(newNode);
    size_++;
}

template<typename T> void LinkedList<T>::insertLast(T data)
{
    auto newNode = std::make_unique<Node<T>>(data);
    if (!head_)
    {
        head_ = std::move(newNode);
        size_++;
        return;
    }
    auto last = head_.get();
    while (last->getNext())
    {
        last = last->getNext();
    }
    last->setNext(newNode.release());
    size_++;
}

template<typename T> T LinkedList<T>::deleteFirst()
{
    if (!head_)
        throw std::range_error("List is empty!");
    auto headData = head_->getData();
    head_ = head_->getManagedNext();
    size_--;
    return headData;
}

template<typename T> T LinkedList<T>::deleteLast()
{
    if (!head_)
        throw std::range_error("List is empty!");
    auto newLast = head_.get();
    if (newLast->getNext() == nullptr)
    {
        auto deletedNodeData = head_->getData();
        head_.reset();
        size_--;
        return deletedNodeData;
    }
    while (newLast->getNext()->getNext())
    {
        newLast = newLast->getNext();
    }
    auto deletedNodeData = newLast->getNext()->getData();
    newLast->setNext(nullptr);
    size_--;
    return deletedNodeData;
}

template<typename T> bool LinkedList<T>::deleteByKey(T key)
{
    if(!head_)
        return false;

    auto temp = head_.get();

    if (temp->getData() == key)
    {
        this->deleteFirst();

        return true;
    }
    while (temp->getNext())
    {
        if (temp->getNext()->getData() == key)
        {
            auto tempNode = temp->getNext()->getManagedNext();
            temp->setNext(tempNode.release());
            size_--;
            return true;    
        }
        else
        {
            temp = temp->getNext();
        }
    }
    return false;
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

template<typename T> unsigned int LinkedList<T>::size()
{
    return size_;
}
#endif //ifndef LINKEDLIST_HPP_
