#include <iostream>
#include <string>
#include "List.h"

using namespace std;

int main()
{

    List l;
    l.append("un");
    l.append("deux");
    l.append("trois");
    for (List<string>::Iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;
// Affichage: un deux trois
    const List c = { 42, 3, 14 };
    for (List::ConstIterator it = --c.end(); it != --c.begin(); --it)
        cout << *it << " ";
    cout << endl;
// Affichage: 14 3 42

}