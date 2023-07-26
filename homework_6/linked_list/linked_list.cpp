using namespace std;

#include <iostream>
#include "linked_list.h"

int main()
{
    LinkedList<int> list;  // H=null; T=null;

    list.insertAtFront(3); // H=3; T=3;
    list.insertAtEnd(5); // H=3; T=5;

    list.insertAtFront(8); // H=8; N1=3; T=5;
    list.insertAtEnd(10); // H=8; N1=3; N2=5; T=10;

    cout << "Linked List Values : ";
    for(LinkedList<int>::Iterator i = list.begin(); i != list.end(); ++i)
    {
        cout << *i << " ";
    }

    list.deleteAtFront(); // H=3; N2=5; T=10;
    list.deleteAtEnd(); // H=3; T=5;

    cout << endl << "\nLinked List Values after deletion at Front and End: ";
    for(LinkedList<int>::Iterator i = list.begin(); i != list.end(); ++i)
    {
        cout << *i << " ";
    }

    list.deleteAtFront(); // H=5; T=5;

    cout << endl << "\nLinked List Values after deletion at Front: ";
    for(LinkedList<int>::Iterator i = list.begin(); i != list.end(); ++i)
    {
        cout << *i << " ";
    }

    list.deleteAtFront(); // H=null; T=null;

    cout << endl << "\nLinked List Values after deletion of all values: empty list ";
    for(LinkedList<int>::Iterator i = list.begin(); i != list.end(); ++i)
    {
        cout << *i << " ";
    }

    // ------------------- CREATE LIST -------------------------

    list.insertAtFront(3); // H=3; T=3;
    list.insertAtEnd(5); // H=3; T=5;
    list.insertAtFront(8); // H=8; N1=3; T=5;
    list.insertAtEnd(10); // H=8; N1=3; N2=5; T=10;

    cout << endl << "\nCreated new list: ";
    for(LinkedList<int>::Iterator i = list.begin(); i != list.end(); ++i)
    {
        cout << *i << " ";
    }

    // ------------------- INSERT BEFORE -------------------------

    // insert at position 2
    LinkedList<int>::Iterator it = list.begin(); // it is at head now which is 1st index

    // Iterate to the second position
    // assume this list starts with index 1
    for(int i=1; i<2; i++)
    {
        ++it;  // increment to the 2nd index and exit
    }

    list.insertBefore(it, 1);  // Now list will be : 8, 1, 3, 5, 10

    cout << endl << "\nLinked List Values after 'Insert 1 Before 3': ";
    for(LinkedList<int>::Iterator i = list.begin(); i != list.end(); ++i)
    {
        cout << *i << " "; 
    }

    // -------------------------- INSERT AFTER -------------------------------

    list.InsertAfter(it, 6);  // Now list will be : 8, 1, 3, 6, 5, 10

    cout << endl << "\nLinked List Values after 'Insert 6 After 3': ";
    for(LinkedList<int>::Iterator i = list.begin(); i != list.end(); ++i)
    {
        cout << *i << " "; 
    }

    // -------------------------- DELETE AT -----------------------------------

    list.DeleteAt(it);  // Now list will be : 8, 1, 6, 5, 10

    cout << endl << "\nLinked List Values after 'Delete At 3': ";
    for(LinkedList<int>::Iterator i = list.begin(); i != list.end(); ++i)
    {
        cout << *i << " "; 
    }

    cout << endl;

}