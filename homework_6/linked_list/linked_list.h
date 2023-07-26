#pragma once

using namespace std;

#include <iostream>


template <typename T>
class LinkedList
{
    // ------------------------- LIST NODE ----------------------------------------
    struct Node{
        Node* prev;
        T data;
        Node* next;

    public:
        Node(T _data, Node* _prev = nullptr, Node* _next = nullptr)
        {
            prev = _prev;
            data = _data;
            next = _next;
        }

        friend ostream& operator << (ostream&, const Node& N)
        {
            cout << &N << " : >> " << N.prev << " >> " << N.data << " >> " 
            << N.next << " >> " << endl;
            return cout;
        }
    };

    Node* Head;
    Node* Tail;

public:

    LinkedList()
    {
        Head = nullptr;
        Tail = nullptr;
    }

    // ------------------------- INSERTION -------------------------------------

    void insertAtFront(T val)
    {
        if(!Head) // if head is null then the new node will be head and tail
        {
            Tail = Head = new Node(val);
            return;
        }

        auto* temp = new Node(val, nullptr, Head); // if head exists, create new node and point its next to head
        Head -> prev = temp; // update head prev from null to new node
        Head = temp; // point head to new node
    }

    void insertAtEnd(T val)
    {
        if(!Tail)  // If head or tail doesn't exist. Create new node and assign it to head or tail
        {
            Tail = Head = new Node(val);
            return;
        }

        auto* temp = new Node(val, Tail, nullptr); // if tail exists, create new node and point its prev to tail
        Tail -> next = temp; // point tail's next pointer to new node
        Tail = temp;  // update tail
    }

    // ----------------------------- DELETION -----------------------------------

    void deleteAtFront()
    {
        auto* temp = Head;

        if(!Head) // if list doesn't exist
            return;

        else if(Head -> next == nullptr) // if there is only one node
            Head = Tail = nullptr;

        else
        {
            Head = Head -> next; // point head to its next
            Head -> prev = nullptr; // set prev to null to avoid dangling pointer
        }

        delete temp; // release memory
    }

    void deleteAtEnd()
    {
        auto* temp = Tail;

        if(!Tail)  // list doesn't exist
            return;

        else if(Tail -> prev == nullptr) // if there is only one node
            Head = Tail = nullptr;

        else
        {
            Tail = Tail -> prev; // point tail to previous node
            Tail -> next = nullptr; // set tail's next to null to avoid dangling pointer
        }
        delete temp; // release memory
    }

    // ---------------------------- ITERATOR -----------------------------------------

    class Iterator
    {
        friend class LinkedList;
        Node* N;

        Iterator(Node* n)
        {
            N = n;
        }

    public:
        Iterator(const Iterator &I)
        {
            N = I.N;
        }

        Iterator operator++()
        {
            N = N -> next;
            return *this;
        }

        Iterator operator--()
        {
            N = N -> prev;
            return *this;
        }

        T& operator*()
        {
            return N -> data;
        }

        bool operator==(const Iterator& I)const
        {
            return this -> N == I.N;
        }

        bool operator!=(const Iterator& I)const
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

    // ----------------------- INSERTIONS USING ITERATOR -------------------------------

    void insertBefore(Iterator I, T val)
    {
        // if(I == Head || (I == nullptr && !Head))
        // {
        //     insertAtFront(val);
        //     return;
        // }
        // else if(I == nullptr)
        // {
        //     insertAtEnd(val);
        // }

        auto* newNode = new Node(val); // create new node
        auto* current = I.N;
        auto* previous = current -> prev;

        newNode -> next = current;
        newNode -> prev = previous;

        previous -> next = newNode;
        current -> prev = newNode;
    }

    void InsertAfter(Iterator I, T val)
	{
        auto* newNode = new Node(val); // create new node
        auto* current = I.N;
        auto* nextNode = current -> next;

        newNode -> next = nextNode;
        newNode -> prev = current;

        current -> next = newNode;
        nextNode -> prev = newNode;
	}

    // ------------------------------ DELETION --------------------------------------

    void DeleteAt(Iterator I)
    {
        auto* current = I.N;
        auto* previous = current -> prev;
        auto* nextNode = current -> next;

        previous -> next = nextNode;
        nextNode -> prev = previous;

        delete current;
    }

};