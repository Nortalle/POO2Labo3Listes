/*
 ------------------------------------------------------------------------------
 Labo        : 3
 File        : List.h
 Author(s)   : Guillaume Hochet et Vincent Guidoux
 Date        : 25.04.2018

 Goal        :

 Compiler    :
 ------------------------------------------------------------------------------
*/

#ifndef POO2LABO3LISTES_LIST_H
#define POO2LABO3LISTES_LIST_H

#include <string>
#include <stdexcept>

using namespace std;

class Iterator;

class ConstIterator;

/**
 * Classe générique doublement chaînée permettant de stocker des listes
 * d’objets ou de pointeurs sur des objets.
 */
class List {
private:

    typedef struct Node {
        string element;
        struct Node *previous;
        struct Node *next;
    } Node;

    Node *head;
    Node *tail; //TODO doublement chainé implique de stocker la fin de la liste ?

    //TODO : Est-ce une bonne idée de stocker la taille ?
    size_t length;


public:
    //TODO: Je sais que tu m'avais dit qu'il ne fallait jamais faire les Signatures en avance, mais là se sont celles qui sont demandées

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
    List &operator=(const List &other);

    /**
     * Accès à un élément de la liste
     * l'indice 0 étant celui du premier élément
     *
     * @param i : indice de l'élément désiré
     * @return  : le ième élément
     */
    string operator[](size_t i) const throw(std::out_of_range);

    /**
     * Accès à un élément modifiable de la liste
     * l'indice 0 étant celui du premier élément
     *
     * @param i : indice de l'élément désiré
     * @return  : le ième élément
     */
    string &operator[](size_t i) throw(std::out_of_range);

    /**
     * @return le nombre d’éléments de la liste,
     */
    size_t size() const;

    /**
     * Insère un élément au début de la list
     * @param o : élément à inserer à la début de la List
     */
    void insert(const string &o);

    /**
     * Insère un élément à la fin de la List
     * @param o : élément à inserer à la fin de la List
     */
    void append(const string &o);

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
    void remove(const string &o);

    /**
     * Recherche un élément dans la liste et rendant l’indice du
     * premier élément correspondant dans la liste ou, sinon, -1
     *
     * Renvoie un int pour envoyer -1 au cas où nous n'avons pas
     * trouvé l'élément
     *
     * @param o : Élément de la liste à chercher
     * @return l’indice du
     * premier élément correspondant dans la liste ou, sinon, -1
     */
    int find(const string &o) const;

    /**
     * @return an iterator placed at the beginning of the list
     */
    Iterator begin();

    /**
     * @return an iterator placed at the end of the list
     */
    Iterator end();

    /**
     * @return an iterator placed at the beginning of the list
     */
    Iterator begin() const;

    /**
     * @return an iterator placed at the end of the list
     */
    Iterator end() const;


    class Iterator {
    private:
    public:
        Iterator &operator++();

        bool operator==(const Iterator &o) const;

        bool operator!=(const Iterator &o) const;

        string &operator*();
    };

    class ConstIterator : public Iterator {
    private:
    public:
    };

    /**
     *  Affichage dans un flux de la liste et de son contenu.
     *
     * @param out : flux dans lequel afficher la liste et son contenu
     * @param l : Élément à afficher
     * @return le flux dans lequel afficher la liste et son contenu
     */
    friend std::ostream &operator<<(std::ostream &out, const List &l);
};


#endif //POO2LABO3LISTES_LIST_H
