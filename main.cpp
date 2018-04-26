/*
 ------------------------------------------------------------------------------
 Labo        : 3
 File        : main.cpp
 Author(s)   : Guillaume Hochet et Vincent Guidoux
 Date        : 25.04.2018

 Goal        : Main class that test the implementation of List chained double

 Compiler    :
 ------------------------------------------------------------------------------
*/
#include <iostream>
#include <string>
#include "List.h"
#include "Person.h"
#include "Student.h"

using namespace std;

int main() {
    List<string> l;
    l.append("un");
    l.append("deux");
    l.append("trois");
    cout << 1 << " ";
    for (List<string>::Iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;
    //1 un deux trois

    cout << 2 << " ";
    for (List<string>::Iterator it = --l.end(); it != --l.begin(); --it)
        cout << *it << " ";
    cout << endl;
    //2 trois deux un

    List<Person *> persons;

    Person *jean = new Person("Jean");

    persons.insert(jean);
    persons.insert(new Student("Paul", "IL"));
    persons.insert(new Person("Jacques"));

    cout << 3 << " ";
    for (List<Person *>::Iterator it = persons.begin(); it != persons.end(); ++it) {
        (*it)->display();
        cout << ", ";
    }
    cout << endl;
    //3 Person : Jacques , Student : Paul, IL , Person : Jean ,

    List<Person *> personsCopy;
    personsCopy = persons;

    cout << 4 << " ";
    cout << personsCopy << endl;
    //4  -> 0x3256e40 -> 0x3256de8 -> 0x3256da8 (du moins des pointeurs
    //Comme dit dans le mail à M. Nanchen
    persons.remove(jean);

    cout << 5 << " ";
    cout << persons << endl;
    //5  -> 0x31e6e40 -> 0x31e6de8

    cout << 6 << " ";
    cout << personsCopy << endl;
    //6  -> 0x3256e40 -> 0x3256de8 -> 0x3256da8

    cout << 7 << " ";
    List<string> en = {"one", "two", "tree", "apple"};
    cout << en << endl;
    //7  -> one -> two -> tree -> apple

    List<string> te = {"truck", "blade", "support", "tip"};

    en = te;

    cout << 8 << " ";
    cout << en << endl;
    //8  -> one -> two -> tree -> apple

    List<int> videNeDevraitPasPlanter;
    cout << videNeDevraitPasPlanter << endl;



    return EXIT_SUCCESS;
}
