/*
 ------------------------------------------------------------------------------
 Labo        : 3
 File        : Student.h
 Author(s)   : Guillaume Hochet et Vincent Guidoux
 Date        : 25.04.2018

 Goal        : Classe qui définit un étudiant simple qui est une personne
               basique
 ------------------------------------------------------------------------------
*/

#ifndef POO2LABO3LISTES_STUDENT_H
#define POO2LABO3LISTES_STUDENT_H

#include "Person.h"

class Student : public Person {
    std::string orientation;

public:
    Student(std::string nom,
            std::string orientation) : Person(nom), orientation(orientation) {}

    void display() {
        std::cout << "Student : " << nom << ", " << orientation << " ";
    }
};

#endif //POO2LABO3LISTES_STUDENT_H
