/* 
 * File:   Node.cpp
 * Author: helmuth
 * 
 * Created on 29 de febrero de 2020, 09:36
 */

#include "Node.hpp"
#include <iostream>

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
