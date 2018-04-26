/*
 ------------------------------------------------------------------------------
 Labo        : 3
 File        : Person.h
 Author(s)   : Guillaume Hochet et Vincent Guidoux
 Date        : 25.04.2018

 Goal        : Classe qui définit une personne simple voir basique
 ------------------------------------------------------------------------------
*/

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
