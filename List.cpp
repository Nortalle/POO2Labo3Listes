/*
 ------------------------------------------------------------------------------
 Labo        : 3
 File        : List.cpp
 Author(s)   : Guillaume Hochet et Vincent Guidoux
 Date        : 25.04.2018

 Goal        :

 Compiler    :
 ------------------------------------------------------------------------------
*/

#include "List.h"

List::List() : head(nullptr), tail(nullptr), length(0) {}

List::List(const List &list) : length(list.length) {

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

string List::operator[](size_t i) const {
    //TODO

    return std::__cxx11::string();
}

string &List::operator[](size_t i) {
    //TODO
    string tmp;

    return tmp;
}*/

size_t List::size() const {

    return length;
}

void List::insert(const string &o) {

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

void List::append(const string &o) {
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

void List::removeAt(size_t index) {
    //TODO call find()

    length--;
}

void List::remove(const string &o) {
    //TODO

    length--;
}

size_t List::find(const string &o) const {
    //TODO

    return 0;
}

std::ostream &operator<<(std::ostream &out, const List &l) {

    const string arrow = " -> ";

    if(l.length != 0){
        List::Node* tmp = l.head;

        while(tmp != nullptr){
            out << arrow << tmp->element;
            tmp = tmp->next;
        }
    }

    return out;
}





