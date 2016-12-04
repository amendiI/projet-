#ifndef LISTE_H
#define LISTE_H

template<class T>
class Node{
private:
    T val;
    Node* next;
public:
    Node();
    Node(T v);
    T getVal();
    Node* getNext();
    void setNext(Node* ptrNode);
    ~Node();
};

template<class T>
class Liste
{
private:
    int t;
    Node<T>* head;

public:
    Liste();
    int  size();
    Node<T>*  getHead();
    bool  isEmpty();
    void setnext(T val);

};

#endif // LISTE_H
