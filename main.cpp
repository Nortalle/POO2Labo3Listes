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

using namespace std;

int main() {

    List<string> l;

    /**
     * Test append
     */
    l.append("un");
    l.append("deux");
    l.append("trois");

    l.affiche();
    //cout << l << endl;

    /**
     * Test append
     */
    l.insert("quatre");
    l.insert("cinq");
    l.insert("six");

    l.affiche();
    //cout << l << endl;

    /**
     * Test find
     */

    cout << l.find("six") << endl;
    cout << l.find("cinq") << endl;
    cout << l.find("quatre") << endl;
    cout << l.find("un") << endl;
    cout << l.find("deux") << endl;
    cout << l.find("trois") << endl;
    cout << l.find("nicolas") << endl;

    /**
     * Test remove
     */

    l.remove("six");
    l.remove("nicolas");

    l.affiche();

    l.removeAt(3);

    l.affiche();
    //cout << l << endl;

    /*
    for (List::Iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;
// Affichage: un deux trois




    /**
     * Tests donnés dans le labo
     */
    /*
    List<string> l;
    l.append("un");
    l.append("deux");
    l.append("trois");
    for (List<string>::Iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;
// Affichage: un deux trois
    const List<int> c = {42, 3, 14};
    for (List<int>::ConstIterator it = --c.end(); it != --c.begin(); --it)
        cout << *it << " ";
    cout << endl;
// Affichage: 14 3 42
*/
}