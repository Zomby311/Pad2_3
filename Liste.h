//
// Created by Admin on 05.06.2021.
//

#ifndef PRAKTIKUM3_LISTE_H
#define PRAKTIKUM3_LISTE_H

#include "Item.h"


template<class T>
class Liste {
private:
    Item<T> *first;
    Item<T> *current;
    Item<T> *last;

public:
    Liste();

    Item<T> *get();
    bool empty();
    bool end();
    void adv();
    void reset();
    void ins(Item<T> *item);
    void del();
    void print();
    Item<T> *getFirst();
    Item<T> *getCurrent();
    Item<T> *getLast();
};

template<class T>
Liste<T>::Liste() {
    first = NULL;
    current = NULL;
    last = NULL;
}

template<class T>
void Liste<T>::print() {
    Item<T> *item = first;

    while (item != NULL) {
        std::cout << "-------------" << std::endl;
        Item<T> *previos = item->getPrevios();
        if (previos != NULL) {
            std::cout << "Previos : ";
            previos->print();
        }
        std::cout << "Info : ";
        item->print();
        Item<T> *next = item->getNext();
        if (next != NULL) {
            std::cout << "Next : ";
            next->print();
        }
        item = item->getNext();
        std::cout << "-------------" << std::endl;
    }

    std::cout <<"First :" << first->getInfo() << std::endl;
    std::cout <<"Current :" << current->getInfo() << std::endl;
    std::cout <<"Last :" << last->getInfo() << std::endl;
}

template<class T>
Item<T> *Liste<T>::get() {
    return current;
}

template<class T>
bool Liste<T>::empty() {
    if (first == NULL) {
        return true;
    }
    return false;
}

template<class T>
bool Liste<T>::end() {
    if (current->getNext() == NULL) {
        return true;
    }
    return false;
}

template<class T>
void Liste<T>::adv() {
    if (current->getNext() != NULL) {
        current = current->getNext();
    } else {
        std::cout << "Das Ende der Liste wurde erreicht." << std::endl;
    }
}

template<class T>
void Liste<T>::reset() {
    current = first;
}

template<class T>
void Liste<T>::ins(Item<T> *item) {

    if (first == NULL) {
        first = item;
        current = item;
        last = item;
        return;
    }

    Item<T> *tmpitem = first;

    if(item < first){
        item->setNext(first);
        first->setPrevios(item);
        first = item;
        return;
    }
    if(item > last){
        last->setNext(item);
        item->setPrevios(last);
        last = item;
        return;
    }
    while (tmpitem != NULL){
        if(tmpitem<item && tmpitem->getNext() > item){
            item->setPrevios(tmpitem);
            item->setNext(tmpitem->getNext());
            tmpitem->getNext()->setPrevios(item);
            tmpitem->setNext(item);
            break;
        }
        tmpitem = tmpitem->getNext();
    }
    current = item;
}

template<class T>
void Liste<T>::del() {

    Item<T> *item = first;

    while (item != NULL) {
        if (item == current) {
            Item<T> *previos = current->getPrevios();
            Item<T> *next = current->getNext();
            if(previos != NULL && next != NULL){
                next->setPrevios(previos);
                previos->setNext(next);
                break;
            }
            if(previos != NULL){
                previos->setNext(nullptr);
                last = previos;
            }
            if(next != NULL){
                next->setPrevios(nullptr);
                first = next;
            }

        }
        item = item->getNext();
    }
    delete current;
    current = first;
}

template <class T>
Item<T> * Liste<T>::getFirst(){
    return first;
}
template <class T>
Item<T> * Liste<T>::getCurrent(){
    return current;
}
template <class T>
Item<T> * Liste<T>::getLast(){
    return last;
}


#endif //PRAKTIKUM3_LISTE_H
