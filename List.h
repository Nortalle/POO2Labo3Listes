//
// Created by Nortalle on 29.03.2018.
//

#ifndef POO2LABO3LISTES_LIST_H
#define POO2LABO3LISTES_LIST_H

#include <string>
#include <stdexcept>

using namespace std;

class Node;

/**
 * Classe générique doublement chaînée permettant de stocker des listes
 * d’objets ou de pointeurs sur des objets.
 */
class List {
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

public:

    /**
     * Constructeur sans paramètre
     */
    List();

    //TODO: Constructeur avec une liste d’initialiseurs

    /**
     * Constructeur de copie
     *
     * @param list : list à copier dans le nouvel élément
     */
    List(const List &list);

    /**
    * Opréateur d'affectation
    *
    * @param other   : List à affecter
    * @return la List affectée
    */
    List& operator=(const List& other);

    /**
     * Accès à un élément de la liste
     * l'indice 0 étant celui du premier élément
     *
     * @param i : indice de l'élément désiré
     * @return  : le ième élément
     */
    string operator[](size_t i) const throw (std::out_of_range);

    /**
     * Accès à un élément modifiable de la liste
     * l'indice 0 étant celui du premier élément
     *
     * @param i : indice de l'élément désiré
     * @return  : le ième élément
     */
    string& operator[](size_t i) throw (std::out_of_range);

    /**
     * @return le nombre d’éléments de la liste,
     */
    size_t size();

    /**
     * Insère un élément au début de la list
     * @param o : élément à inserer à la début de la List
     */
    void insert(const string& o);

    /**
     * Insère un élément à la fin de la List
     * @param o : élément à inserer à la fin de la List
     */
    void append(const string& o);

    /**
     * Supprime l'élément à l'index donné
     *
     * @param index : index de l'élément à supprimer
     */
    void removeAt(size_t index);

    /**
     * Supprime l'élément donné, s'il est dans la List
     * @param o : élément à supprimer
     */
    void remove(const string& o);

};


#endif //POO2LABO3LISTES_LIST_H
