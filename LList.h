/*
* Created by Juan V. on 04/18/2021.
* Linked List class: nodes appended to the list and be of type integer or Node.
*/

#ifndef PROJECT4_LLIST_H
#define PROJECT4_LLIST_H

#include <iostream>
#include "node.h"

class LList{
    // Keep the syntax of insertion operator by defining in file scope
    friend std::ostream& operator<<(std::ostream& oStream, const LList& aDLList) ;
protected:
    int size;

public:
    Node* head;
    Node* tail;
    Node* last;
    LList() ;                      // default constructor
    explicit LList(int value) ;  // convenience constructor
    explicit LList(Node* value) ;  // convenience constructor
    LList(const LList& other)  ;  // copy constructor for deep copy
    virtual ~LList() ;             // destructor is virtual
    LList& append(int x) ;       // insertion method
    LList& append(Node* x) ;       // overloaded insertion method for list type
    LList& prepend(int x) ;
    LList& prepend(Node* x) ;
    int find_element(int x) ;       // membership test - return element position or -1
    void printList(Node*);
private:
    // auxiliary methods invoked
    bool DL_scan(int x, Node* node_ptr) ;
    void recursive_delete(Node* aNode) ;

};

#endif //PROJECT4_LLIST_H
