/* 
 * File:   main.cpp
 * Author: helmuth
 *
 * Created on 29 de febrero de 2020, 09:36
 */

#include <cstdlib>
#include "DoublyLinkedList.hpp"
#include "DoublyLinkedList.cpp"
using namespace std;
/*
 * 
 */
int main() {
    try{       
        DoublyLinkedList<int> list;
        list.add(0,5);
        list.add(1,10);
        list.add(2,11);
        list.add(2,13);
        list.addFirst(60);
        list.addFirst(20);
        list.addFirst(30);
        list.addLast(50);
        list.addFirst(5);
        list.add(1, 100);  
        list.add(0, 12);
        for(int i =0; i < list.size(); i++){
            cout<< list.get(i) << " ";
        }
        cout <<"\nPrimer elemento: " <<list.getFirst() <<endl;
        cout <<"Ultimo elemento: " <<list.getLast() <<endl;

        //list.removeIndex(71);
        list.removeValue(50);
        list.addFirst(99);
        for(int i =0; i < list.size(); i++){
            cout<< list.get(i) << " ";
        }
        cout <<"\nPrimer elemento: " <<list.getFirst() <<endl;
        cout <<"Ultimo elemento: " <<list.getLast() <<endl;

       

    }
    catch(const string &e){
        cerr <<e <<endl;
    }    
    return 0;
}

