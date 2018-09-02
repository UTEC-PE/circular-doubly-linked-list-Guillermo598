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
        List(){
            start = nullptr;
        };

        T front(){
            if (start == nullptr)
                cout << "ListError" << endl;
            else
                return start -> data;
        };
        T back(){
            if (start == nullptr)
                cout << "ListError" << endl;
            else
                return start -> prev -> data;
        };
        void push_front(T value){
            Node<T>* temp = new Node<T>;
            temp -> data = value;
            if (start == nullptr){
                temp -> next = temp -> prev = temp;
                start = temp;
            }
            else{
                temp -> next = start;
                temp -> prev = start -> prev;
                start -> prev -> next = temp;
                start -> prev = temp;
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
                temp -> next = start;
                temp -> prev = start -> prev;
                start -> prev -> next = temp;
                start -> prev = temp;
            }
        };
        void pop_front(){
            if (start == nullptr)
                cout << "ListError" << endl;
            else{
                Node<T>* temp = start;
                start -> prev -> next = start -> next;
                start -> next -> prev = start -> prev;
                start = start -> next;
                delete temp;
            }
        };
        void pop_back(){
            if (start == nullptr)
                cout << "ListError" << endl;
            else{
                Node<T>* temp = start -> prev;
                start -> prev -> prev -> next = start;
                start -> prev = start -> prev -> prev;
                delete temp;
            }
        };
        T get(int position){
            if (position < 0)
                cout << "ListError" << endl;
            else{
                Node<T>* temp = start;
                for (int i = 0; i < position; i++)
                    temp = temp -> next;
                return temp -> data;
            }
        };
        void concat(List<T> &other){
            Node<T>* last = start -> prev;
            last -> next = other.start;
            other.start -> prev -> next = start;
            start -> prev = other.start -> prev;
            other.start -> prev = last;
        };
        bool empty(){
            return start == nullptr;
        };
        int size(){
            int size = 0;
            Iterator<T>* temp = start;
            do{
                temp++;
                size++;
            } while (temp != start);
            return size;
        };
        void clear(){
            Iterator<T>* temp = start;
            while (temp != nullptr){
                temp++;
                delete temp -> prev;
            };
            start = nullptr;
        };
        Iterator<T> begin(){
            Iterator<T>* temp = start;
        };
        Iterator<T> end(){
            Iterator<T>* temp = start -> prev;
        };

        ~List(){
            Node<T>* temp = start;
            if (temp -> next != nullptr){
                temp ->
            };
            delete this;
        };
};

#endif