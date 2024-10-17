#include "List.hpp"
#include <stdexcept>
#include <iostream>
#include <ostream>

template <typename T>
class ListArray : public List<T> {
private:
    T* array;
    int max;
    int n;
    static const int MINSIZE =2;

    void resize(int new_size) {
        T* new_array = new T[new_size];
        for (int i = 0; i < size; ++i) {
            new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;
        max = new_size;
    }

public:
    ListArray() : max(MINSIZE), n(0) {
        resize(MINSIZE);
    }

    ~ListArray() {
        delete[] array;
    }

    T operator[](int pos) {
        if(pos < 0 || pos >= n){
            throw std::out_of_range("Index out of bounds");
        }
        return array[pos];
    }

    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
        out << "[";
        for (int i = 0; i < list.size; ++i) {
            out << list.array[i];
            if (i < list.size - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }

    void insert(int pos, const T& element) override {
        if (pos < 0 || pos > size) {
            throw std::out_of_range("Index out of range");
        }
        if (size == max) {
            resize(max * 2);
        }
        for (int i = size; i > pos; --i) {
            array[i] = array[i - 1];
        }
        array[pos] = element;
        ++size;
    }

    void append(const T& element) override {
        insert(size, element);
    }

    void prepend(const T& element) override {
        insert(0, element);
    }
    
    T remove(int pos) override {
        if (pos < 0 || pos >= size) {
            throw std::out_of_range("Index out of range");
        }
        T element = array[pos];
        for (int i = pos; i < size - 1; ++i) {
            array[i] = array[i + 1];
        }
        --size;
        return element;
    }
    T get(int pos) override {
        if (pos < 0 || pos >= size) {
            throw std::out_of_range("Index out of range");
        }
        return array[pos];
    }

    int search(const T& element) override {
        for (int i = 0; i < size; ++i) {
            if (array[i] == element) {
                return i;
            }
        }
        return -1;
    }
    
    bool empty() override {
        return size == 0;
    }

    int size() override {
        return size;
    }

};

