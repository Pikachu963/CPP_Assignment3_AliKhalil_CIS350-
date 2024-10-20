#include <iostream>
#include "DLinkedList.h"

using namespace std;

int main(void) {

    // Initialize a DLinkedList object
    DLinkedList list;

    // Is list empty? Yes, cause none of the elements have been inserted yet
    cout << "Is the list empty: " << (list.empty() ? "True" : "False") << endl;

    // Add Elements at front and back
    list.addFront("JFK");
    list.addFront("PVD");
    list.addFront("SFO");
    // Print Front and back elements in the list
    cout << "Front: " << list.front() << endl;
    cout << "Back: " << list.back() << endl << endl;
    cout << "Entire list:" << endl;
    list.printList();
    cout << endl;
    Ele e = "PVD";
    cout << "searching for " << e << endl;
    list.find(e);
    cout << endl;
    Ele f = "NMO";
    cout << "searching for " << f << endl;
    list.find(f);
    cout << endl;
    Ele newElement = "BWI";
    list.insertAfter(e, newElement);;
    // Print all the elements
    cout << "list after adding BWI after PVD" << endl;
    list.printList();
    cout << endl;
    // Print all the elements in reverse order
    cout << "Reversing list." << endl;
    list.reverse();
    cout << "Printing reversed list:" << endl;
    list.printList();

    // Check if the list is empty now
    cout << "Is the list empty: " << (list.empty() ? "True" : "False") << endl << endl;

    // Remove elements at front
    cout << "list before removing front" << endl;
    list.printList();
    cout << endl;
    list.removeFront();
    cout << "list after removing front" << endl;
    list.printList();

    // Remove elements at back
    list.removeBack();
    cout << "list after removing back" << endl;
    // Print list
    list.printList();

    // Check if the list is empty now
    cout << "Is the list empty: " << (list.empty() ? "True" : "False") << endl;

    return 0;
}
