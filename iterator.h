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
        Iterator(Node<T>* node);
         
        Iterator<T> operator=(Iterator<T> node){
            return current = node;
        };
        bool operator!=(Iterator<T> cmp){
            return current != cmp.current;
        };
        Iterator<T> operator++(){
            current = current -> next;
        };
        Iterator<T> operator--(){
            current = current -> prev;
        };
        T operator*(){
            return current -> data;
        };
};

#endif