//
// Created by Admin on 05.06.2021.
//

#ifndef PRAKTIKUM3_ITEM_H
#define PRAKTIKUM3_ITEM_H

template <class T>
class Item {
public:
    Item(T info);
    void print();
    void setNext(Item *next);
    void setPrevios(Item *previos);
    Item * getNext();
    Item * getPrevios();
    T getInfo();
//    friend operator|;
private:
    T info;
    Item *next;
    Item *previos;
};

template <class T>
Item<T>::Item(T pinfo) {
    info = pinfo;
    next = nullptr;
    previos = nullptr;
}
template <class T>
void Item<T>::print() {
    std::cout << info << std::endl;
}

template <class T>
void Item<T>::setNext(Item *pnext) {
    next = pnext;
}

template <class T>
Item<T> * Item<T>::getNext() {
    return next;
}

template <class T>
T Item<T>::getInfo() {
    return info;
}

template<class T>
void Item<T>::setPrevios(Item *pprevios) {
    previos = pprevios;
}

template<class T>
Item<T> *Item<T>::getPrevios() {
    return previos;
}


#endif //PRAKTIKUM3_ITEM_H
