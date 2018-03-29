//
// Created by Nortalle on 29.03.2018.
//

#include "List.h"

List::Node::Node(const string& element, Node *next, Node *before) : element(element), next(next), before(before) {}

List::Node::Node(const string &element) : element(element), next(nullptr), before(nullptr) {}

List::List() : head(nullptr), length(0) {}

List::List(const List &list) {
    //TODO
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
    //TODO
}

void List::append(const string &o) {
    //TODO

    if(length == 0){
        head = new Node(o, nullptr, nullptr);
    } else {

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
    //TODO

    return <#initializer#>;
}





