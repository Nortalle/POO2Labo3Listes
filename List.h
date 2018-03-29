//
// Created by Nortalle on 29.03.2018.
//

#ifndef POO2LABO3LISTES_LIST_H
#define POO2LABO3LISTES_LIST_H

#include <string>

using namespace std;

class Node;

class List {
public:
    List();

    void append(const string string);

private:
    Node *head;

    class Node {
    public:
        Node(string element, Node *next, Node *before);

    private:
        string element;
        Node *next;
        Node *before;
    };
};


#endif //POO2LABO3LISTES_LIST_H
