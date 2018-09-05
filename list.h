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
    int nodes;

public:
    List(){
        start = nullptr;
        nodes = 0;
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
        nodes++;
    };
    void push_back(T value){
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
        }
        nodes++;
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
            nodes --;
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
            nodes--;
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
        nodes += other.nodes;
    };
    bool empty(){
        return (nodes == 0);
    };
    int size(){
        return nodes;
    };
    void clear(){
        Node<T>* temp = start;
        while (nodes != 0){
            Node<T>* aux = temp;
            temp = temp -> next;
            delete aux;
            nodes--;
        }
        start = nullptr;
        delete temp;
    };
    Iterator<T> begin(){
        return Iterator<T>(this -> start);
    };
    Iterator<T> end(){
        return Iterator<T>(this -> start -> prev);
    };

    ~List(){
        Node<T>* temp = start;
        for (int i = 0; i < size(); i++){
            if (temp -> next != start){
                temp = temp -> next;
                delete temp -> prev;
            }
        }
        delete temp;
    };
};

#endif