//
// Created by Nortalle on 29.03.2018.
//

#include "List.h"

List::Node::Node(const string &element, Node *next, Node *before) : element(element), next(next), before(before) {}

List::Node::Node(const string &element) : element(element), next(nullptr), before(nullptr) {}

List::List() : head(nullptr), length(0) {}

List::List(const List &list) : length(list.length) {

    //TODO pas finie et pas claire

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
    }
}

List &List::operator=(const List &other) {
    //TODO

    return <#initializer#>;
}

string List::operator[](size_t i) const {
    //TODO

    return std::__cxx11::string();
}

string &List::operator[](size_t i) {
    //TODO

    return <#initializer#>;
}

size_t List::size() const {

    return length;
}

void List::insert(const string &o) {

    if (o == nullptr) {
        //TODO Lancer une exception
    }

    if (length == 0) {
        head = new Node(o);
        tail = head;
    } else {
        Node *tmp = new Node(o);

        tmp->next = head;
        tmp->next->before = tmp;

        head = tmp;
    }
    length++;
}

void List::append(const string &o) {
    //TODO

    if (length == 0) {
        head = new Node(o);
        tail = head;
    } else {
        tail->next = new Node(o);
        tail->next->before = tail;
        tail = tail->next;
    }
    length++;
}

void List::removeAt(size_t index) {
    //TODO

}

void List::remove(const string &o) {
    //TODO

}

size_t List::find(const string &o) const {
    //TODO

    return 0;
}

std::ostream &operator<<(std::ostream &out, const List &l) const {


    return <#initializer#>;
}





