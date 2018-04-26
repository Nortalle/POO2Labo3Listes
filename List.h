/*
 ------------------------------------------------------------------------------
 Labo        : 3
 File        : List.h
 Author(s)   : Guillaume Hochet et Vincent Guidoux
 Date        : 25.04.2018

 Goal        : Implémente une liste circulaire avec une sentinelle comme le
               fait la stl. Nous permettons donc à l'utlilisateur de faire
               (--(--begin()). C'est un choix d'implémentation comme un autre.

               Elle propose deux iterateurs, un constant et un non-constant.

 commentaires : Tout se trouve dans le .h, car nous avons vu en cours
                que du moment où ça touchait la générécité, un .h suffisait
                Nous avons décidé d'implémenter une liste circulaire.
 ------------------------------------------------------------------------------
*/

#ifndef POO2LABO3LISTES_LIST_H
#define POO2LABO3LISTES_LIST_H

#include <stdexcept>

using namespace std;

/**
 * Classe générique doublement chaînée permettant de stocker des listes
 * d’objets ou de pointeurs sur des objets.
 */
template<typename T>
class List {
private:
    struct Node {
        Node *previous;
        Node *next;

    };

    struct DataNode : Node {
        T element;

        DataNode() : element(T()) {
        }
    };

    //pointe sur le début de la liste
    DataNode *head;

    //pointe sur la fin de la liste
    DataNode *tail;

    //Taille de la liste
    size_t length;

    //used for --begin() and end()
    Node *sentinal;

    /**
     * Supprimme tous les éléments de la liste
     */
    void removeAll() {
        while (length != 0) {
            removeAt(0);
        }
    }

    /**
     * Concatène une liste avec celle donnée en paramètre
     *
     * @param list : liste à rajouter à la fin de la liste actuelle
     */
    void appendList(const List &list) {
        ConstIterator endit = list.cend();
        for (ConstIterator it = list.cbegin(); it != endit; ++it) {
            append(*it);
        }
    }

    /**
     * Lorsque nous ajontons un nouvel élément à une liste vide
     * ce code est nécessaire
     *
     * @param to_add : noeuds à ajouter à la liste
     */
    void firstAdd(DataNode *to_add) {
        head = to_add;

        head->next = sentinal;
        head->previous = sentinal;

        sentinal->next = head;
        sentinal->previous = head;

        tail = head;
    }

    /**
     * Valide si l'index passé en paramètre ne sort pas de la liste
     * @param i : index à vérifier
     */
    void validIndex(size_t i) const throw(std::out_of_range) {
        if (i >= length) {
            throw std::out_of_range("out of range");
        }
    }

    /**
     * Retourne une référence sur l'élément du noeuds à
     * l'index donné
     *
     * @param i : index du noeuds à retournr
     * @return l'objet à retourner
     */
    T &at(size_t i) {
        validIndex(i);
        Iterator tmp = begin();
        int index = 0;

        while (tmp != nullptr) {
            if (index == i) {
                return *tmp;
            }
            ++tmp;
            index++;
        }
    }

    /**
     * Retourne une copie  sur l'élément du noeuds à
     * l'index donné
     *
     * @param i : index du noeuds à retournr
     * @return l'objet à retourner
     */
    T at(size_t i) const {
        validIndex(i);
        ConstIterator tmp = cbegin();
        int index = 0;

        while (tmp != nullptr) {
            if (index == i) {
                return *tmp;
            }
            ++tmp;
            index++;
        }
    }

public:
    /**
     * Constructeur sans paramètre
     */
    List() : sentinal(new Node), length(0) {
        head = (reinterpret_cast<DataNode *>(sentinal));
        tail = (reinterpret_cast<DataNode *>(sentinal));
    }

    /**
     * Constructeur de copie
     *
     * @param list : list à copier dans le nouvel élément
     */
    explicit List(const List &list) : List() {

        appendList(list);
    }

    /**
     * Constructeur avec une liste d’initialiseurs
     *
     * @param args : liste d'initialisateurs
     */
    List(std::initializer_list<T> args) : List() {
        //nous sortons le end() pour un soucis d'efficacité.
        const T *endit = args.end();
        for (const T *val = args.begin(); val != endit; ++val) {
            append(*val);
        }
    }

    /**
     * Destructeur
     */
    ~List() {
        removeAll();
        delete sentinal;
    }

    /**
    * Opréateur d'affectation
    *
    * @param other   : List à affecter
    * @return la List actuelle dans son état après l'affectation
    */
    List &operator=(const List &other) {
        if (&other != this) {
            removeAll();
            appendList(other);
        }
        return *this;
    }

    /**
     * Accès à un élément de la liste
     * l'indice 0 étant celui du premier élément
     *
     * @param i : indice de l'élément désiré
     * @return  : le ième élément
     */
    T operator[](size_t i) const throw(std::out_of_range) {
        at(i);
    }

    /**
     * Accès à un élément modifiable de la liste
     * l'indice 0 étant celui du premier élément
     *
     * @param i : indice de l'élément désiré
     * @return  : le ième élément
     */
    T &operator[](size_t i) throw(std::out_of_range) {
        at(i);
    }

    /**
     * @return le nombre d’éléments de la liste,
     */
    size_t size() const {
        return length;
    }

    /**
     * Insère un élément au début de la list
     * @param o : élément à inserer à la début de la List
     */
    List &insert(const T &o) {

        DataNode *to_insert = new DataNode();

        to_insert->element = o;

        //est-ce que la liste est vide ?
        if (head == sentinal) {

            firstAdd(to_insert);
        } else {
            head->previous = to_insert;
            to_insert->next = head;
            head = to_insert;
            head->previous = sentinal;
            sentinal->next = head;
        }
        length++;
        return *this;
    }

    /**
     * Insère un élément à la fin de la List
     * @param o : élément à inserer à la fin de la List
     * @return la liste sur laquelle nous avons opéré le concaténage
     */
    List &append(const T &o) {

        DataNode *to_append = new DataNode();
        to_append->element = o;

        //est-ce que la liste est vide ?
        if (tail == sentinal) {
            firstAdd(to_append);
        } else {
            tail->next = to_append;
            to_append->previous = tail;
            tail = to_append;
            tail->next = sentinal;
            sentinal->previous = tail;
        }
        length++;

        return *this;
    }

    /**
     * Supprime l'élément à l'index donné
     *
     * @param index : index de l'élément à supprimer
     */
    void removeAt(size_t index)  throw(std::out_of_range) {

        validIndex(index);
        Node *current_node = head;
        size_t i = 0;

        while (current_node != nullptr) {
            if (index == i) {
                if (current_node == head) {
                    sentinal->previous = nullptr;
                    sentinal->next = nullptr;
                    head = reinterpret_cast<DataNode *>(sentinal);
                    tail = reinterpret_cast<DataNode *>(sentinal);
                    break;
                } else if (current_node == tail) {
                    tail = reinterpret_cast<DataNode *>(current_node->previous);
                    tail->next = sentinal;
                    sentinal->previous = tail;
                } else {
                    current_node->next->previous = current_node->previous;
                    current_node->previous->next = current_node->next;
                }

                head = reinterpret_cast<DataNode *>(sentinal->next);
                tail = reinterpret_cast<DataNode *>(sentinal->previous);
                delete current_node;
                break;
            } else {
                current_node = current_node->next;
                i++;
            }
        }
        length--;
    }

    /**
     * Supprime  la première occurance de l'élément donné,
     * s'il est dans la List
     * @param o : élément à supprimer
     */
    void remove(const T &o) {

        int index = find(o);
        if (index != -1) {
            removeAt(index);
        }
    }

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
    int find(const T &o) const {

        ConstIterator tmp = cbegin();
        int index = 0;

        while (tmp != nullptr) {
            if (*tmp == o) {
                return index;
            }
            ++tmp;

            index++;
        }
        return -1;
    }

    /**
     * Classe ConstIterator, est un itérateur qui lorsqu'il donne accès
     * à l' élément de l'itérateur, ne permet pas de les modifier
     */
    class ConstIterator {
    private:
        //noeuds courant
        Node *m_node;
    public:

        /**
         * Constructeur
         * @param node : noeuds sur lequel pointer
         */
        ConstIterator(Node *node) : m_node(node) {}

        /**
         * Mets l'itérteur sur le noeuds suivant
         *
         * @return un itérateur sur l'élément suivant
         */
        ConstIterator &operator++() {
            m_node = m_node->next;
            return *this;
        }

        /**
         *  Mets l'itérteur sur le noeuds précédant
         *
         * @return un itérateur sur l'élément précédant
         */
        ConstIterator &operator--() {
            m_node = m_node->previous;
            return *this;
        }

        /**
         * @param o :  iterateur à comparer
         * @return si les iterateurs sont égaux
         */
        bool operator==(const ConstIterator &o) const {
            return m_node == o.m_node;
        }

        /**
        * @param o :  iterateur à comparer
        * @return si les iterateurs ne sont pas égaux
        */
        bool operator!=(const ConstIterator &o) const {
            return m_node != o.m_node;
        }

        /**
         * @return  accès aux méthodes et aux attributs
         *              de l'élément courant pas modifiable
         */
        const T *operator->() const {
            return &operator*();
        }

        /**
        * @return accès à l'élément courant, sans la possibilité de le modifié
        */
        const T &operator*() const {
            return reinterpret_cast<DataNode *>(m_node)->element;
        }
    };

    /**
    * Classe Iterator, est un itérateur qui lorsqu'il donne accès
    * à l' élément de l'itérateur,  permet  de les modifier
    */
    class Iterator {
    private:
        //noeuds courant
        Node *m_node;

    public:

        /**
         * Constructeur
         * @param node : noeuds sur lequel pointer
         */
        Iterator(Node *node) : m_node(node) {}

        /**
         * Mets l'itérteur sur le noeuds suivant
         *
         * @return un itérateur sur l'élément suivant
         */
        Iterator &operator++() {
            m_node = m_node->next;
            return *this;
        }

        /**
         *  Mets l'itérteur sur le noeuds précédant
         *
         * @return un itérateur sur l'élément précédant
         */
        Iterator &operator--() {
            m_node = m_node->previous;
            return *this;
        }

        /**
         * @param o :  iterateur à comparer
         * @return si les iterateurs sont égaux
         */
        bool operator==(const Iterator &o) const {
            return m_node == o.m_node;
        }

        /**
         * @param o :  iterateur à comparer
         * @return si les iterateurs ne sont pas égaux
         */
        bool operator!=(const Iterator &o) const {
            return m_node != o.m_node;
        }

        /**
         * @return  accès aux méthodes et aux attributs
         *              de l'élément courant pas
         *
         * (retourne un pointeur et non une référence,
         *  nulle part dans nos recherches sur internet le
         *  retour d'une référence est faite)
         */
        T *operator->() {
            return &operator*();
        }

        /**
        * @return accès à l'élément courant, sans la possibilité de le modifié
        */
        T &operator*() {
            return reinterpret_cast<DataNode *>(m_node)->element;
        }
    };

    /**
     * @return un itérateur placé au début de la liste
     */
    Iterator begin() const {
        return Iterator(head);
    }

    /**
     * @return un itérateur placé après la fin de la liste
     */
    Iterator end() const {
        return Iterator(sentinal);
    }

    /**
     * @return un itérateur placé au début de la liste
     */
    ConstIterator cbegin() const {
        return ConstIterator(head);
    }

    /**
     * @return un itérateur placé après la fin de la liste
     */
    ConstIterator cend() const {
        return ConstIterator(sentinal);
    }

    /**
     *  Affichage dans un flux la liste et son contenu.
     *
     * @param out : flux dans lequel afficher la liste et son contenu
     * @param l : Élément à afficher
     * @return le flux dans lequel afficher la liste et son contenu
     */
    friend
    std::ostream &operator<<(std::ostream &out, const List<T> &l) {
        const string arrow = " -> ";

        List<T>::Iterator tmp = l.begin();

        while (tmp != l.end()) {
            out << arrow << *tmp;
            ++tmp;
        }
        return out;
    }
};

#endif //POO2LABO3LISTES_LIST_H
