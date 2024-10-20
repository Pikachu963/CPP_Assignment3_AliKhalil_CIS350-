#include <iostream>
#include "DLinkedList.h"

using namespace std;

DLinkedList::DLinkedList() {
    header = new DNode;
    trailer = new DNode;
    header->right = trailer;
    trailer->left = header;
}

DLinkedList::~DLinkedList() {
    while (!empty()) removeFront();
    delete header;
    delete trailer;
}

bool DLinkedList::empty() const {
    return (header->right == trailer) && (trailer->left == header);
}

const Ele& DLinkedList::front() const {
    return header->right->ele;
}

const Ele& DLinkedList::back() const {
    return trailer->left->ele;
}

void DLinkedList::add(DNode* v, const Ele& e) { // add before v
    DNode* u = new DNode;
    u->ele = e;
    u->right = v;
    u->left = v->left;
    v->left->right = u;
    v->left = u;
}

void DLinkedList::addFront(const Ele& e) {
    add(header->right, e);
}

void DLinkedList::addBack(const Ele& e) {
    add(trailer, e);
}

void DLinkedList::remove(DNode* v) {
    DNode* u = v->left;
    DNode* w = v->right;
    u->right = w;
    w->left = u;
    delete v;
}

void DLinkedList::removeFront() {
    remove(header->right);
}

void DLinkedList::removeBack() {
    remove(trailer->left);
}

void DLinkedList::printList() const {
    DNode* temp = header->right;

    if (temp == trailer) {  // List is empty if header's right points to trailer
        cout << "List is empty" << endl;
        return;
    }

    while (temp != trailer) {
        cout << temp->ele << endl;
        temp = temp->right;
    }
}

int DLinkedList::find(const Ele& findElement) {
    DNode* temp = header->right;
    int positionCounter = 1;
    while (temp != trailer && temp->ele != findElement) { // this loop iterates through the linkedlist by checking each node's next value to see if it was the accepted value
        temp = temp->right; // changes temp if correct string was not found
        positionCounter += 1;
    }
    if (temp->ele == findElement) {
        cout << findElement << " is found!" << endl;
        cout << findElement << " is in the " << positionCounter << " position." << endl;
        return positionCounter;
    }
    cout << "Element not found." << endl;
    
}

DNode* DLinkedList::findNode(const Ele& findElement) {
    DNode* temp = header->right;
    while (temp != trailer && temp->ele != findElement) {
        temp = temp->right;
    }
    if (temp->ele == findElement) {
        return temp;
    }
    return nullptr;
}

void DLinkedList::insertAfter(const Ele& existingElement, const Ele& newElement) {
    DNode* newNode = new DNode;
    newNode->ele = newElement;
    DNode* existingNode = findNode(existingElement); // finding where node of existingElement is 
    newNode->right = existingNode->right; // making newNode's right existingNode's right b/c it will be in position existingNode was
    newNode->left = existingNode; // making newNode's left existingNode b/c now existingNode will be to the left of it
    existingNode->right = newNode; // newNode is now right of existingNode
}

void DLinkedList::reverse() {
    if (header == nullptr || header->right == nullptr) { // if list is empty or only has one node, then end function
        return;
    }
    DNode* next = new DNode;
    DNode* current = header;
    DNode* previous = NULL;

    while (current != NULL) {
        next = current->right; // setting up next node to be reversed
        current->right = previous; // right of header, which normally points to a non-NULL node, now reverses and points to NULL.
        current->left = next; // left of header, normally NULL, now points to a non-NULL node
        previous = current; // changes previous to current to setup for the next node to be reversed
        current = next; // changes current to next as next will be the next node to be reversed
    }
    DNode* tempHeader = header;
    header = trailer; // reversing header by making it trailer
    trailer = tempHeader; // reversing trailer by setting it to what header used to be
}