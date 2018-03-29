//
// Created by Nortalle on 29.03.2018.
//

#include "List.h"

List::Node::Node(int element, Node *next, Node *before) : element(element), next(next), before(before) {}


List::List() {}

void List::append(const string string) {

    if(head == nullptr){
        head = new Node(string, nullptr ,nullptr);
    } else {
        head->next = new Node(string, head ,nullptr);
    }

}
