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

    DataNode *head;
    DataNode *tail;

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
        for (Iterator it = list.begin(); it != list.end(); ++it)
            append(*it);
    }

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


    T at(size_t i){
        Iterator tmp = begin();
        int index = 0;

        while (tmp != nullptr) {
            if (index == i) {
                return *tmp;
            }
            ++tmp;

            index++;
        }
        return -1;
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

        for (const T *val = args.begin(); val != args.end(); ++val) {
            append(*val);
        }
    }
/*
    ~List() {
        removeAll();
        delete sentinal;
    }
*/
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
        //at(i);
    }

    /**
     * Accès à un élément modifiable de la liste
     * l'indice 0 étant celui du premier élément
     *
     * @param i : indice de l'élément désiré
     * @return  : le ième élément
     */
    T &operator[](size_t i) throw(std::out_of_range) {
        //at(i);
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
     */

    /**
     * Insère un élément à la fin de la List
     * @param o : élément à inserer à la fin de la List
     * @return la liste sur laquelle nous avons opéré le concaténage
     */
    List &append(const T &o) {

        DataNode *to_append = new DataNode();
        to_append->element = o;

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
    void removeAt(size_t index) {

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
                tail = reinterpret_cast<DataNode *>(sentinal->previous) ;
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
     * Supprime l'élément donné, s'il est dans la List
     * @param o : élément à supprimer
     */
    void remove(const T &o) {

        int index = find(o);
        if (index != -1)
            removeAt(index);
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

        Iterator tmp = begin();
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

    class ConstIterator {
    protected:
        ConstIterator() {}

    private:
        Node *m_node;
    public:

        ConstIterator(Node *node) : m_node(node) {}

        ConstIterator &operator++() {
            m_node = m_node->next;
            return *this;
        }

        ConstIterator &operator--() {
            m_node = m_node->previous;
            return *this;
        }

        bool operator==(const ConstIterator &o) const {
            return m_node == o.m_node;
        }

        bool operator!=(const ConstIterator &o) const {
            return m_node != o.m_node;
        }

        const T *operator->() {
            return &m_node;
            //return &operator*();
        }

        const T &operator*() {
            return reinterpret_cast<DataNode *>(m_node)->element;
        }
    };

    class Iterator {
    protected:
        Iterator() {}

    private:
        Node *m_node;

    public:

        Iterator(Node *node) : m_node(node) {}

        Iterator &operator++() throw(std::out_of_range) {
            m_node = m_node->next;
            return *this;
        }

        Iterator &operator--() {
            m_node = m_node->previous;
            return *this;
        }

        bool operator==(const Iterator &o) const {
            return m_node == o.m_node;
        }

        bool operator!=(const Iterator &o) const {
            return m_node != o.m_node;
        }

        T *operator->() {
            return &m_node;
            // return &operator*();
        }

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
