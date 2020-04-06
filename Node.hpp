/* 
 * File:   Node.hpp
 * Author: helmuth
 *
 * Created on 29 de febrero de 2020, 09:36
 */

#ifndef NODE_HPP
#define NODE_HPP
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
#include "Node.cpp"
#endif /* NODE_HPP */

