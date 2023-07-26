#pragma once

using namespace std;

#include <iostream>


template <typename T>
class ForwardList
{
    // ------------------------------- LIST NODE -----------------------------------
    struct Node
    {
        T data;
        Node* next;

        Node(T _data, Node* _next = nullptr)
        {
            data = _data;
            next = _next;
        }

        friend ostream& operator <<(ostream&, const Node& N)
        {
            cout << &N << " : >> " << N.data << " >> " << N.next << " >> " << endl;
            return cout;
        }
    };

    Node* Head;
    Node* Tail;

public:

    ForwardList()
    {
        Head = Tail = nullptr;
    }

    // ------------------------- INSERT AT FRONT ----------------------------------
    void insertAtFront(T val)
    {
        if(!Head)
        {
            Head = Tail = new Node(val);
            return;
        }
        
        auto* newNode = new Node(val, Head);
        Head = newNode;
    }

    // -------------------------   INSERT AT END -----------------------------------
    void insertAtEnd(T val)
    {
        if(!Tail)
        {
            insertAtFront(val);
            return;
        }

        auto* newNode = new Node(val);
        Tail -> next = newNode;
        Tail = newNode;
    }

    // ------------------------- DELETE AT FRONT -----------------------------------

    void deleteAtFront()
    {
        if(!Head)
            return;

        auto* node = Head;
        if(Head -> next == nullptr)
            Head = Tail = nullptr;
        else
            Head = Head -> next;

        delete node;
    }

    // ----------------------------- ITERATOR --------------------------------------

    class Iterator
    {
        friend class ForwardList;
        Node* N;

        Iterator(Node* _N)
        {
            N = _N;
        }

    public:
        Iterator(const Iterator& I)
        {
            N = I.N;
        }

        T& operator*()
        {
            return N -> data;
        }

        Iterator operator++()
        {
            N = N -> next;
            return *this;
        }

        bool operator==(const Iterator& I)
        {
            return this -> N == I.N;
        }

        bool operator!=(const Iterator& I)
        {
            return this -> N != I.N;
        }
    };

    Iterator begin()
    {
        return Iterator(Head);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }

    // -------------------------- INSERT AFTER ------------------------------------
    void insertAfter(Iterator I, T val)
    {
        auto* current = I.N;
        auto* newNode = new Node(val, current -> next);
        current -> next = newNode;
    }
};
