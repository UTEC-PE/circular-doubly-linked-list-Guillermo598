#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* start;

    public:
        List();

        T front(){
            return start -> data;
        };
        T back(){
            return start -> prev -> data;
        };
        void push_front(T value){
            Node<T>* temp = new Node<T>;
            temp -> data = value;
            if (start = nullptr){
                temp -> next = temp -> prev = temp;
                start = temp;
            }
            else{
                Node<T>* last = start -> prev;
                temp -> next = start;
                temp -> prev = last;
                last -> next = start -> prev = temp;
                start = temp;
            }
        };
        void push_back(T value){
            Node<T>* temp = new Node<T>;
            temp -> data = value;
            if (start = nullptr){
                temp -> next = temp -> prev = temp;
                start = temp;
            }
            else{
                Node<T>* last = start -> prev;
                temp -> next = start;
                start -> prev = temp;
                temp -> prev = last;
                last -> next = temp;
            }
        };
        void pop_front(){
            Node<T>* temp = start;
            start -> next = start -> next -> next;

            delete temp;
        };
        void pop_back();
        T get(int position);
        void concat(List<T> &other);
        bool empty(){

        };
        int size();
        void clear();
        Iterator<T> begin();
        Iterator<T> end();

        ~List();
};

#endif