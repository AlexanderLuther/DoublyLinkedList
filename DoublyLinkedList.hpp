/* 
 * File:   DoublyLinkedList.hpp
 * Author: helmuth
 *
 * Created on 29 de febrero de 2020, 09:49
 */
#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP
#include "Node.hpp"

template <class T>
class DoublyLinkedList {
    
    public:
        DoublyLinkedList();
        void addFirst(T value);
        void addLast(T value);
        void add(int index, T value);
        T getFirst();
        T getLast();
        T get(int index);
        int indexOf(T value);
        void removeFirst();
        void removeLast();
        void removeIndex(int index);
        void removeValue(T value);
        bool isEmpty();
        void clear();
        int size();
        
    private:
        Node<T>* header;
        Node<T>* end;
        bool isEmptyList();
        bool isArrayOutOfBounds(int index);
        void remove(Node<T>* node);
};
#endif /* DOUBLYLINKEDLIST_HPP */

