#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
private:
    Node<T>* current;

public:
    Iterator(){
        current = nullptr;
    };
    Iterator(Node<T>* node){
        this -> current = node;
    };

    Iterator<T> operator=(Iterator<T> node){
        this -> current = node.current;
        return *this;
    };
    bool operator!=(Iterator<T> cmp){
        return (this -> current != cmp.current);
    };
    Iterator<T> operator++(){
        current = current -> next;
        return *this;
    };
    Iterator<T> operator--(){
        current = current -> prev;
        return *this;
    };
    T operator*(){
        return current -> data;
    };
};

#endif