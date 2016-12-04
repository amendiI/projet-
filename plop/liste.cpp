#include "liste.h"

    template<class T>
    Liste<T>::Liste(){t=0;head=NULL;}
    template<class T>
    int  Liste<T>::size(){return t;}
    template<class T>
    Node<T>*  Liste<T>::getHead(){return head;}
    template<class T>
    bool  Liste<T>::isEmpty(){return t<=0;}
    template<class T>
    void Liste<T>::setnext(T val)
    {
        t++;
        Node<T> tmp=this->head;
        while(tmp->getNext()!=NULL){tmp=tmp->getNext();}
        tmp.setNext(new Node<T>(val));
    }

    template<class T>
    Node<T>::Node(){val=0;next=NULL;}
    template<class T>
    Node<T>::Node(T v)
    {
        val=v;
        next=NULL;
    }
    template<class T>
    T Node<T>::getVal(){return val;}
    template<class T>
    Node<T>* Node<T>::getNext(){return next;}
    template<class T>
    void Node<T>::setNext(Node<T>* ptrNode){next=ptrNode;}
    template<class T>
    Node<T>::~Node(){next=NULL;val=0;cout<<'.';}
