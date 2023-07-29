using namespace std;

#include <iostream>
#include "forward_list.h"


int main()
{
    ForwardList<int> fList;

    fList.insertAtFront(3); // H=3; T=3;
    fList.insertAtEnd(5); // H=3; T=5;

    fList.insertAtFront(8); // H=8; N1=3; T=5;
    fList.insertAtEnd(10); // H=8; N1=3; N2=5; T=10;

    cout << "Forward List Values : ";
    for(ForwardList<int>::Iterator i = fList.begin(); i != fList.end(); ++i)
    {
        cout << *i << " ";
    }

    // ------------------ DELETE AT FRONT --------------------------------

    fList.deleteAtFront(); // H=3; N2=5; T=10;

    cout << endl << "\nLinked List Values after 'Delete at Front' : ";
    for(ForwardList<int>::Iterator i = fList.begin(); i != fList.end(); ++i)
    {
        cout << *i << " ";
    }

    // ------------------ DELETE AT END --------------------------------

    fList.deleteAtEnd(); // H=3; N2=5;

    cout << endl << "\nLinked List Values after 'Delete at End' : ";
    for(ForwardList<int>::Iterator i = fList.begin(); i != fList.end(); ++i)
    {
        cout << *i << " ";
    }

    // -------------------- INSERT AFTER --------------------------------

    // insert at position 2
    ForwardList<int>::Iterator it = fList.begin(); // it is at head
    fList.insertAfter(it, 0); // H=3; N1=0; N2=5;

    cout << endl << "\nLinked List Values after 'Insert After' : ";
    for(ForwardList<int>::Iterator i = fList.begin(); i != fList.end(); ++i)
    {
        cout << *i << " ";
    }

    cout << endl;

}
