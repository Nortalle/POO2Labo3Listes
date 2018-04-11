/*
 ------------------------------------------------------------------------------
 Labo        : 3
 File        : List.cpp
 Author(s)   : Guillaume Hochet et Vincent Guidoux
 Date        : 25.04.2018

 Goal        :

 Compiler    :

 Source      : https://openclassrooms.com/courses/les-listes-doublement-chainees-en-langage-c
 ------------------------------------------------------------------------------
*/

#include "List.h"

template<class T>
List<T>::List() : head(nullptr), tail(nullptr), length(0) {}

template<class T>
List<T>::List(const List &list) : length(list.length) {

    //TODO pas finie et pas claire
/*
    if (list.length != 0) {

        Node *RhsIt = list.head;
        Node *It = new Node(RhsIt->element, nullptr, nullptr);
        head = It;
        while ((RhsIt = RhsIt->next) != list.tail) {
            try {
                Node *Next = new Node(RhsIt->element, It, nullptr);
                It = It->next = Next;
            }
            catch (std::bad_alloc &Exception) {
                for (Node *Last; head != nullptr; delete Last) {
                    Last = head;
                    head = head->next;
                }
                throw ;
            }
        }
        tail = It;
    }*/
}

/*
List &List::operator=(const List &other) {
    List tmp;

    return tmp;
}

T List::operator[](size_t i) const {
    //TODO

    return std::__cxx11::T();
}

T &List::operator[](size_t i) {
    //TODO
    T tmp;

    return tmp;
}*/

template<typename T>
size_t List<T>::size() const {

    return length;
}


template<typename T>
void List<T>::insert(const T &o) {

    Node *to_insert = new Node();

    to_insert->element = o;
    to_insert->previous = nullptr;

    if (head == nullptr) {

        to_insert->next = nullptr;
        head = to_insert;
        tail = to_insert;
    } else {
        head->previous = to_insert;
        to_insert->next = head;
        head = to_insert;
    }

    length++;
}

template<typename T>
void List<T>::append(const T &o) {
    Node *to_append = new Node();

    to_append->element = o;
    to_append->next = nullptr;

    if (tail == nullptr) {
        to_append->previous = nullptr;
        head = to_append;
        tail = to_append;
    } else {
        tail->next = to_append;
        to_append->previous = tail;
        tail = to_append;
    }
    length++;
}

template<typename T>
void List<T>::removeAt(size_t index) {

    if (0 <= index && index < length) {
        Node *tmp = head;

        int i = 0;

        while (tmp != nullptr && i <= index) {

            if (index == i) {
                if (tmp->next == nullptr) {

                    tail = tmp->previous;
                    tail->next = nullptr;
                } else if (tmp->previous == nullptr) {

                    head = tmp->next;
                    head->previous = nullptr;
                } else {

                    tmp->next->previous = tmp->previous;
                    tmp->previous->next = tmp->next;
                }
                delete tmp;

            } else {
                tmp = tmp->next;
            }
            i++;
        }
        length--;
    }
}

template<typename T>
void List<T>::remove(const T &o) {

    int index = find(o);
    if (index != -1)
        removeAt(index);
}

template<typename T>
int List<T>::find(const T &o) const {

    Node *tmp = head;
    int index = 0;

    while (tmp != nullptr) {
        if (tmp->element == o) {
            return index;
        } else {
            tmp = tmp->next;
        }
        index++;
    }

    return -1;
}

template<class U>
std::ostream &operator<<(std::ostream &out, const List<U> &l) {

    const string arrow = " -> ";

    List<U>::Node *tmp;

    if (l.size() != 0) {
        tmp = l.head;

        while (tmp != nullptr) {
            out << arrow << tmp->element;
            tmp = tmp->next;
        }
    }

    return out;
}





