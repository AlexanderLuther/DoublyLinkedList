/* 
 * File:   Node.hpp
 * Author: helmuth
 *
 * Created on 29 de febrero de 2020, 09:36
 */

#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>

template <class T>
class Node{
    
    private:
        T value;
        Node<T>* next;
        Node<T>* previous;
    
    public:
        Node();
        Node(T value);
        void setValue(T value);
        void setPrevious(Node<T>* previous);
        void setNext(Node<T>* next);
        T getValue();
        Node<T>* getPrevious();
        Node<T>* getNext();        
};


/*
 * Constructores de la clase.
 */
template <class T> 
Node<T>::Node(){
    this->value = NULL;
    this->previous = NULL;
    this->next = NULL;
}

template <class T> 
Node<T>::Node(T value){
    this->value = value;
    this->previous = NULL;
    this->next = NULL;
}

/*
 * Setters de la clase.
 */
template <class T>
void Node<T>::setValue(T value){
    this->value = value;
}

template <class T>
void Node<T>::setPrevious(Node<T>* previous){
    this->previous = previous;
}

template <class T>
void Node<T>::setNext(Node<T>* next){
    this->next = next;
}

/*
 * Getters de la clase.
 */
template <class T>
T Node<T>::getValue(){
    return this->value;
}

template <class T>
Node<T>* Node<T>::getPrevious(){
    return this->previous;
}

template <class T>
Node<T>* Node<T>::getNext(){
    return this->next;
}

#endif /* NODE_HPP */