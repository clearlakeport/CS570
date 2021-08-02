//    Dong Lin
//    cssc4206
//    redid: 827228799
#ifndef DLL_H
#define DLL_H

#include <iostream>
#include <string>

using namespace std;

template <class T>
struct Node
{
    T Data;

    Node* Next;
    Node* Prev;
};


template <class T>
class DblyLinkedList
{
private:
    Node<T>* Head;
    Node<T>* Current;

public:
    // constructor
    DblyLinkedList();
    // destructor
    ~DblyLinkedList();
    bool isEmpty()
    {
        return Head == NULL;
    }
    // setters
    void addNodeRear(T data);
    void addNodeFront(T data);
    bool deleteNode(Node<T> * tPtr);
    bool removeFront(T &data);
    T retFront();
    void reset();
    Node<T>* nextNode();
    Node<T>* getHead()
    {
        return Head;
    }
    bool find(T data);
    void insertAfter(Node<T>* n, T data);
    void insertBefore(Node<T>* n, T data);
    int size();
    int count(T data);
};

// constructor
template <class T>
DblyLinkedList<T>::DblyLinkedList()
{
    Head = NULL;
    Current = NULL;
}

// destructor
template <class T>
DblyLinkedList<T>::~DblyLinkedList()
{

    Node<T>* p = Head, *delPtr;

    while (p!= NULL)
    {
        delPtr = p;
        p = p->Next;
        delete delPtr;
    }

}

//testing only
template <class T>
void DblyLinkedList<T>::addNodeRear(T data)
{
    if (Head == NULL)
    {
        Head = new Node<T>;
        Head->Data = data;
        Head->Next = NULL;
        Head->Prev = NULL;
    }
    else
    {
        // Set a pointer equal to the head
        Node<T>* p = this->Head;

        // Traverse to the end of the list
        while (p->Next != NULL)
            p = p->Next;

        // Create the new node
        Node<T>* n = new Node<T>;
        n->Data = data;
        n->Next = NULL;

        // Assign the next pointer to the new node
        p->Next = n;

        // Assign the prev pointer to the previous node
        n->Prev = p;

    }
}

template <class T>
void DblyLinkedList<T>::addNodeFront(T data)
{
    if (Head == NULL)
    {
        Head = new Node<T>;
        Head->Data = data;
        Head->Next = NULL;
        Head->Prev = NULL;
    }
    else
    {

        // Create the new Node
        Node<T>* n = new Node<T>;
        n->Data = data;
        n->Prev = nullptr;

        // Assign the prev pointer to the new node
        Head->Prev = n;
        n->Next = Head;

        // Assign head to the new node
        Head = n;
    }
}
//search for pid
template <class T>
bool DblyLinkedList<T>::find(T search)
{

    Node<T>* tmp = Head;
    while (tmp != NULL)
    {
        if (tmp->Data.pid == search.pid)
            return true;
        else
            tmp = tmp->Next;
    }
    return false;
}

template <class T>
bool DblyLinkedList<T>::deleteNode(Node<T>* delPtr)
{
    Node<T>* tPtr;

    if (Head == NULL)
        return false;

    if (delPtr == Head)
    {
        if (Head->Next == NULL)
        {
            delete Head;
            Head = NULL;
        }
        else
        {
            Head = Head->Next;
            Head->Prev = NULL;
            delete delPtr;
        }
        return true;
    }

    if (delPtr->Next == NULL)
    {
        delPtr->Prev->Next = NULL;
        delete delPtr;
        return true;
    }

    tPtr = delPtr->Prev;
    tPtr->Next = delPtr->Next;
    tPtr->Next->Prev = tPtr;
    delete delPtr;

    return true;
}


//for testing
template <class T>
void DblyLinkedList<T>::insertAfter(Node<T> * nodePtr, T data)
{
    Node<T>* tmpPtr = new Node<T>;

    tmpPtr->Data = data;
    if (nodePtr->Next == NULL)
    {
        addNodeRear(data);
        return;
    }

    tmpPtr->Next = nodePtr->Next;
    tmpPtr->Next->Prev = tmpPtr;
    tmpPtr->Prev = nodePtr;
    nodePtr->Next = tmpPtr;

}
//insert the node before the nodeptr
template <class T>
void DblyLinkedList<T>::insertBefore(Node<T>* nPtr, T data)
{
    Node<T>* tPtr = new Node<T>;
    tPtr->Data = data;

    if (nPtr == Head)
    {
        addNodeFront(data);

        return;
    }


    tPtr->Prev = nPtr->Prev;

    nPtr->Prev = tPtr;

    tPtr->Next = nPtr;

    tPtr->Prev->Next = tPtr;

}

template <class T>
bool DblyLinkedList<T>::removeFront(T &data)
{

    if (isEmpty())
        return false;

    Node<T>* delPtr = Head;
    if (Head->Next == NULL && Head->Prev == NULL)
    {
        data = Head->Data;
        delete delPtr;
        Head = NULL;
    }
    else
    {
        data = Head->Data;
        Head = Head->Next;
        delete delPtr;
        Head->Prev = NULL;
    }
    return true;
}


template <class T>
T DblyLinkedList<T>::retFront()
{
    return Head->Data;
}

template <class T>
void DblyLinkedList<T>::reset()
{
    Current = Head;
}

//iterate through the list, must use reset first
template <class T>
Node<T>* DblyLinkedList<T>::nextNode()
{
    if (Current == NULL)
        return NULL;

    Node<T>* tPtr;

    tPtr = Current;
    Current = Current->Next;

    return tPtr;
}


template <class T>
int DblyLinkedList<T>::size()
{
    Node<T>* p = Head;
    int ct = 0;
    while (p != NULL)
    {
        ct++;
        p = p->Next;
    }
    return ct;
}

template <class T>
int DblyLinkedList<T>::count(T data)
{

    int ct = 0;
    Node<T>* p = Head;
    while (p != NULL)
    {
        if (data == p->Data)
            ct++;
        p = p->Next;
    }
    return ct;
}
#endif // !DLL_H
