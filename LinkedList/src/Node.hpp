#ifndef NODE_HPP_
#define NODE_HPP_

template <typename T>
class Node
{
    public:
        Node(T data);
        T getData();
    private:
        T data_;
        std::unique_ptr<Node<T>> next_;
};

#endif // NODE_HPP_
