//
// Created by Vincent Guidoux on 26.04.2018.
//

#ifndef POO2LABO3LISTES_PERSON_H
#define POO2LABO3LISTES_PERSON_H

#include <iostream>

class Person {
protected:
    std::string nom;

public:
    Person(std::string nom) : nom(nom) {
    }

    virtual void display() {
        std::cout << "Person : " << nom << " ";
    }
};

#endif //POO2LABO3LISTES_PERSON_H
