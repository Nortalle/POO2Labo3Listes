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

    List<int> r;

    /**
     * Test append
     */
    r.append(1);
    r.append(2);
    r.append(3);

    r.affiche();
    //cout << l << endl;

    /**
     * Test append
     */
    r.insert(4);
    r.insert(5);
    r.insert(6);

    r.affiche();
    //cout << l << endl;

    /**
     * Test find
     */

    cout << r.find(6) << endl;
    cout << r.find(5) << endl;
    cout << r.find(4) << endl;
    cout << r.find(1) << endl;
    cout << r.find(2) << endl;
    cout << r.find(3) << endl;
    cout << r.find(69) << endl;

    /**
     * Test remove
     */

    r.remove(6);
    r.remove(69);

    r.affiche();

    r.removeAt(3);

    r.affiche();
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