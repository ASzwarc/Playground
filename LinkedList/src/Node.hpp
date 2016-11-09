#ifndef NODE_HPP_
#define NODE_HPP_

#include <memory>

template <typename T>
class Node
{
    public:
        Node(T data);
        T getData() const;
        void setNext(Node<T>* next);
        Node<T>* getNext();
    private:
        T data_;
        std::unique_ptr<Node<T>> next_;
};

template<typename T> 
Node<T>::Node(T data): data_{data}, next_{nullptr}
{
    std::cout << __PRETTY_FUNCTION__ << " data " << data_ << std::endl;
}

template<typename T> 
T Node<T>::getData() const
{
    return data_;
}

template<typename T> 
void Node<T>::setNext(Node<T>* next)
{
    std::cout << __PRETTY_FUNCTION__ << " setting next node: " << next->getData()
              << std::endl;
    next_.reset(next);
}

template<typename T> 
Node<T>* Node<T>::getNext()
{
    std::cout << __PRETTY_FUNCTION__ << " getting next node: " << next_->getData()
              << std::endl;
    return next_.get();
}



#endif // NODE_HPP_
