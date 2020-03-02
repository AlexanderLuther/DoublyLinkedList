/* 
 * File:   DoublyLinkedList.cpp
 * Author: helmuth
 * 
 * Created on 29 de febrero de 2020, 09:49
 */
#include "DoublyLinkedList.hpp"
#include <iostream>
#include "Node.hpp"
#include "Node.cpp"

/*
 Constructor de la clase.
 */
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
    this->header = NULL;
    this->end = NULL;
}

/*
 * Metodo encargado de agregar un nuevo nodo al inicio de la lista.
 *  1.Crea un nuevo nodo con el valor recibido como parametro.
 *  2.Valida si la lista se encuentra vacia, de ser asi se le asigna al header y al end la direccion del nodo creado.
 *  3.Si no se encuentra vacia, establece el siguiente del nodo hacia el header, el previo del header hacia el nodo y 
 *    asigna al header la direccion del nodo creado.
 */
template <typename T>
void DoublyLinkedList<T>::addFirst(T value){
    Node<T>* node = new Node<T>(value);   
    if(this->isEmpty()){
        this->header = node;
        this->end = node;
    }
    else{
        node->setNext(this->header);
        this->header->setPrevious(node);
        this->header = node;
    }
} 

/*
 * Metodo encargado de agregar un nuevo nodo al final de la lista.
 * 1.Crea un nuevo nodo con el valor recibido como parametro.
 * 2.Valida si la lista se encuentra vacia, de ser asi se le asigna al header y al end la direccion del nodo creado.
 * 3.Si no se encuentra vacia, establece el previo del nodo hacia el end, el siguiente del end hacia el nodo y 
 *    asigna al end la direccion del nodo creado.
 */
template <typename T>
void DoublyLinkedList<T>::addLast(T value){
    Node<T>* node = new Node<T>(value);   
    if(this->isEmpty()){
        header = node;
        end = node;
    }
    else{
        node->setPrevious(this->end);
        this->end->setNext(node);
        end = node;
    }
} 

/*
 * Metodo encargado de insertar un nuevo nodo en el indice de la lista que recibe como parametro.
 * 1. Verifica si el indice recibido es igual a la longitud de la lista, en este caso se desea insertar un nuevo
 *    elemento justo despues del ultimo elemento de la lista, por lo cual se llama al metodo addLast().
 * 2. Verifica si la lista se encuentra vacia y si el indice se encuentra dentro de los limites, inicia
 *    la busqueda del nodo con el indice donde se desea insertar.
 * 3. Si el nodo encontrado es igual al header se llama al metodo addFirst().
 * 4. Caso contrario se crea un nuevo nodo con el valor recibido como parametro.
 * 5. Se establece siguiente del nodo previo al nuevo nodo.
 * 6. Se establece el previo del nuevo nodo al previo del nodo actual.
 * 7. Se estabelce el siguiente del nuevo nodo al nodo actual.
 * 8. Se establece el previo del nodo actual al nodo nuevo.
 */
template <typename T>
void DoublyLinkedList<T>::add(int index, T value){
    if(index == this->size()){
        this->addLast(value);
    }
    else{
        if(!this->isEmptyList()){
            if(!this->isArrayOutOfBounds(index)){
                int actualIndex = 0;
                for(Node<T>* actualNode = this->header; actualNode != NULL; actualNode = actualNode->getNext()){
                    if(actualIndex == index){  
                        if(actualNode == this->header){
                            this->addFirst(value);
                            break;
                        }
                        else{ 
                            Node<T>* newNode = new Node<T>(value);
                            actualNode->getPrevious()->setNext(newNode);
                            newNode->setPrevious(actualNode->getPrevious());
                            newNode->setNext(actualNode);
                            actualNode->setPrevious(newNode);
                            break;
                        }
                    }
                    actualIndex++;
                }
            }
        }
    }
}

/*
 * Metodo encargado de devolver el valor del nodo al frente de la lista.
 * Retorna el valor almacenado dentro del nodo referenciado por el header. 
*/
template <typename T>
T DoublyLinkedList<T>::getFirst(){
    if(!this->isEmptyList()){
        return this->header->getValue();
    }
    return (T)NULL;
}

/*
 * Metodo encargado de devolver el valor del nodo al final de la lista.
 * Retorna el valor almacenado dentro del nodo referenciado por el end. 
*/
template <typename T>
T DoublyLinkedList<T>::getLast(){
    if(!this->isEmptyList()){
        return this->end->getValue();
    }
    return (T)NULL;
}

/*
 * Metodo encargado de devolver el valor contenido dentro del nodo cuyo indice se recibe como parametro.
 * Se valida que la lista no se encuentre vacia y que el indice recibido se encuentre dentro de los limites.
 * Se inicia en el primer nodo, si el indice actual es igual al que se recibe como parametro se devuelve el
 * valor contenido del nodo actual, de lo contrario se avanza al siguiente nodo y se incrementa en 1 el valor
 * del indice actual.
*/
template <typename T>
T DoublyLinkedList<T>::get(int index){
    if(!this->isEmptyList()){
        if(!this->isArrayOutOfBounds(index)){
            int actualIndex = 0;
            for(Node<T>* node = this->header; node != NULL; node = node->getNext()){
                if(index == actualIndex){
                    return node->getValue();
                }
                actualIndex++;
            }
        }      
    }
    return 0;
}

/*
 * Metodo encargado de obtener el indice del nodo cuyo valor sea igual al que se recibe como parametro.
 * Se valida que la lista no se encuentre vacia y se inicia desde el header hasta llegar al ultimo nodo.
 * Si el valor del nodo actual es igual al valor buscado se retorna el valor contenido dentro del entro
 * index de lo contrario se avanza al siguiente nodo y se incrementa en 1 el valor de index. Si no se 
 * encuentra ningun nodo con el valor buscado se retorna -1. 
*/
template <typename T>
int DoublyLinkedList<T>::indexOf(T value){
    if(!this->isEmptyList()){
        int index = 0;
        for(Node<T>* node = this->header; node != NULL; node = node->getNext()){
            if(node->getValue() == value){
                return index;
            }
            index++;
        }
    }
    return -1;
}    

/*
 * Metodo encargado de eliminar el primer nodo de la lista.
 *  1.Valida que la lista no se encuentre vacia.
 *  2.Crea un nuevo nodo que apunta hacia el header
 *  3.Si el header y el end apuntan al mismo nodo entonces se establece a NULL el valor de ambos.
 *  4.De lo contrario se establece el header hacia el siguiente del nodo actual  y el previo del nodo siguiente a NULL.
 *  5.Finalmente se elimina el nodo actual.  
 */
template <typename T>
void DoublyLinkedList<T>::removeFirst(){
    if(!this->isEmptyList()){
        Node<T>* node = this->header;
        if(this->header == this->end){
            this->header = NULL;
            this->end = NULL;
        }
        else{
            this->header = node->getNext();
            node->getNext()->setPrevious(NULL);
        }
        delete node;
    }
} 

/*
 * Metodo encargado de eliminar el ultimo nodo de la lista.
 *  1.Valida que la lista no se encuentre vacia.
 *  2.Crea un nuevo nodo que apunta hacia el end.
 *  3.Si el header y el end apuntan al mismo nodo entonces se establece a NULL el valor de ambos.
 *  4.De lo contrario se establece el end hacia el previo del nodo actual  y el siguente del nodo previo a NULL.
 *  5.Finalmente se elimina el nodo actual.  
 */
template <typename T>
void DoublyLinkedList<T>::removeLast(){
    if(!this->isEmptyList()){
        Node<T>* node = this->end;
        if(this->header == this->end){
            this->header = NULL;
            this->end = NULL;
        }
        else{
            this->end = node->getPrevious();
            node->getPrevious()->setNext(NULL);
        }
        delete node;
    }
} 

/*
 * Metodo encargado de eliminar un nodo dentro de la lista basado en el indice que se recibe como parametro.
 * Valida que la lista no se encuentre vacia y que el indice se encuentre dentro de los limites. Recorre la
 * lista desde el header validando si el indice actual corresponde al indice del nodo que se desea eliminar,
 * si es asi llama la metodo remove() enviandole como parametro el nodo actual.
*/
template <typename T>
void DoublyLinkedList<T>::removeIndex(int index){
    if(!this->isEmptyList()){
        if(!this->isArrayOutOfBounds(index)){
            int actualIndex = 0;
            for(Node<T>* node = this->header; node != NULL; node = node->getNext()){
                if(actualIndex == index){
                    this->remove(node);
                    break;
                }   
            actualIndex++;
            }
        }
    }
}

/*
 * Metodo encargado de eliminar un nodo dentro de la lista basado en el valor  que se recibe como parametro.
 * Valida que la lista no se encuentre vacia. Recorre la lista desde el header validando si el valor del nodo 
 * actual es igual al valor del parametro recibido, si es asi llama la metodo remove() enviandole como parametro el nodo actual.
*/
template <typename T>
void DoublyLinkedList<T>::removeValue(T value){
    if(!this->isEmptyList()){
        for(Node<T>* node = this->header; node != NULL; node = node->getNext()){
            if(node->getValue() == value){
                this->remove(node);
                break;
            }   
        }
    }   
}

/*
 * Metodo encargado de determinar si la lista se encuentra vacia.
 * Valida si el header y el end apuntan hacia NULL y devuelve el valor booleano obtenido de esa comparacion. 
*/
template <typename T>
bool DoublyLinkedList<T>::isEmpty(){
    return this->header == NULL && end == NULL;
}

/*
 * Metodo encargado de eliminar todos los nodos de la lista.
 * Llama al metodo removeFirst() para eliminar cada uno de los nodos de la lista uno por uno.
*/
template <typename T>
void DoublyLinkedList<T>::clear(){
    if(!this->isEmpty()){
        int length = this->size();
        for(int i =0; i < length; i++){
            this->removeFirst();
        }
    }
}

/*
 * Metodo encargado de obtener y retornar la longitud de la lista.
 * Recorre todos los nodos de la lista desde el nodo header hasta el nodo end, con cada nodo que nodo que 
 * avanza incrementa 1 al contrador size. Por ultimo retorna el valor contenido dentro de size. 
*/
template<typename T>
int DoublyLinkedList<T>::size(){
    if(this->isEmpty()){
        return 0;
    }
    else{
        int size = 1;
        for(Node<T>* node = this->header; node != end; node = node->getNext()){
            size++;
        }
        return size;
    }
}

/*
 * Metodo encargado de validar si la lista se encuentra vacia. De ser asi lanza una excepcion.
 * De lo contrario devuelve un valor false;
 */
template <typename T>
bool DoublyLinkedList<T>::isEmptyList(){
    if(this->isEmpty()){
        std::string msg = "La lista se encuentra vacia";
        throw msg;
    }
    return false;    
}

/*
 * Metodo encargado de validar si el indice se encuentra dentro de los limites. De no ser asi lanza una excepcion.
 * De lo contrario devuelve un valor false;
 */
template <typename T>
bool DoublyLinkedList<T>::isArrayOutOfBounds(int index){
    if(index >= this->size() || index < 0){
        std::string msg = "El indice se encuentra fuera de los limites";
        throw  msg;
    }
    return false;    
}

/*
 * Metodo encargado de eliminar el nodo que recibe como parametro.
 * 1. Si el nodo recibido es apuntado por el header se llama al metodo removeFirst().
 * 2. Si el nodo recibido es apuntado por el end se llama al metodo removeLast().
 * 3. De lo contrario se establece el siguiente del nodo previo al siguiente del nodo a eliminar.
 *    y el previo del nodo siguiente al previo del nodo a eliminar y se elimina el nodo.
 */
template <typename T>
void DoublyLinkedList<T>::remove(Node<T>* node){
    if(node == this->header){
        this->removeFirst();
    }
    else if(node == this->end){
        this->removeLast();
    }
    else{
        node->getPrevious()->setNext(node->getNext());
        node->getNext()->setPrevious(node->getPrevious()); 
        delete node;
    }
}
