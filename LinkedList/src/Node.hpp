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
        std::unique_ptr<Node<T>> getManagedNext();
    private:
        T data_;
        std::unique_ptr<Node<T>> next_;
};

template<typename T> 
Node<T>::Node(T data): data_{data}, next_{nullptr}
{
}

template<typename T> 
T Node<T>::getData() const
{
    return data_;
}

template<typename T> 
void Node<T>::setNext(Node<T>* next)
{
    next_.reset(next);
}

template<typename T> 
Node<T>* Node<T>::getNext()
{
    return next_.get();
}

template<typename T>
std::unique_ptr<Node<T>> Node<T>::getManagedNext()
{
    return std::move(next_);
}



#endif // NODE_HPP_
