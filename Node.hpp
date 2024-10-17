#include "List.hpp"
#include <stdexcept>
#include <iostream>
#include <ostream>

template <typename T>
class Node : public List<T> {
    private:
    T data;
    Node<T>* next;
    public:
    Node(T data, Node<T>* next=nullptr){
        this->data = data;
        this->next = next;
    };

    friend std::ostream& operator<<(std::ostream &out, const Node<T> &node) {
        out << node.data;
        return out;
    }

};