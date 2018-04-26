/*
 ------------------------------------------------------------------------------
 Labo        : 3
 File        : main.cpp
 Author(s)   : Guillaume Hochet et Vincent Guidoux
 Date        : 25.04.2018

 Goal        : Main class that test the implementation of List chained double

 commentaires    :
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
    for (List<string>::Iterator it = l.begin(); it != l.end(); ++it) {
        it->insert(2, "a");
        cout << *it << " " << " taille: " << it->length() << " ";
    }
    cout << endl;
    //1 un  taille: 2 deux  taille: 4 trois  taille: 5

    cout << 2 << " ";
    for (List<string>::ConstIterator it = --l.cend();
         it != --l.cbegin(); --it) {
        //it->insert(2, "a"); Ne compile pas ==> const Ok
        cout << *it << " ";
    }
    cout << endl;
    //2 trois deux un

    cout << 2 << "bis ";
    for (List<string>::Iterator it = l.begin(); it != l.end(); ++it) {
        *it = "tout";
        cout << *it << " ";
    }
    cout << endl;
    //2bis tout tout tout

    l.remove("tout");
    cout << 2 << "tris ";
    for (List<string>::Iterator it = l.begin(); it != l.end(); ++it) {
        *it = "tout";
        cout << *it << " ";
    }
    cout << endl;
    //tris

    List<Person *> persons;

    Person *jean = new Person("Jean");

    persons.insert(jean);
    persons.insert(new Student("Nicolas", "Chill"));
    persons.insert(new Person("Pierre"));

    cout << 3 << " ";
    for (List<Person *>::Iterator it = persons.begin();
         it != persons.end(); ++it) {
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

    cout << 9 << " ";
    en[1] = "too";
    cout << te << endl;
    //9  -> one -> too -> tree -> apple


    const List<int> videNeDevraitPasPlanter;
    cout << videNeDevraitPasPlanter << endl;
    //videNeDevraitPasPlanter.insert(3); ne compile pas, liste constante

    List<int> appendlist;

    appendlist.append(1).insert(2).append(3).insert(4).append(5).insert(6);

    cout << 10 << " ";
    cout << appendlist << endl;
    //10  -> 6 -> 4 -> 2 -> 1 -> 3 -> 5

    appendlist[4] = 69;

    cout << 11 << " ";
    for (size_t i = 0; i < appendlist.size(); ++i) {
        cout << appendlist[i] << " ";
    }
    cout << endl;
    //11 6 4 2 1 3 5

    const List<int> test = {1, 4, 2, 3, 6, 5};

    //test[4] = 69; ne passe pas

    cout << test << endl;


    return EXIT_SUCCESS;
}

