#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H 1
#include <string>

using namespace std;

typedef string Ele;

class DNode {
private:
    Ele ele;
    DNode* left;
    DNode* right;
    friend class DLinkedList;
};

class DLinkedList {
private:
    DNode* header;
    DNode* trailer;
protected:

public:
    DLinkedList();
    ~DLinkedList();
    bool empty() const;
    const Ele& front() const;
    const Ele& back() const;
    void addFront(const Ele& e);
    void addBack(const Ele& e);
    void removeFront();
    void removeBack();
    void printList() const;
    void add(DNode* v, const Ele& e); // add before v
    void remove(DNode* v);
    friend class DLinkedListTest;
    int find(const Ele& e);
    DNode* findNode(const Ele& findElement);
    void insertAfter(const Ele& existingElement, const Ele& newElement);
    void reverse();
};

#endif
