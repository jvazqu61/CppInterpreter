//
// Created by Juan V on 04/18/2021.
//

#include "LList.h"

LList::LList(int value) { // convenience constructor for integers
    this->head = this->tail = this->last = new Node(value);
    this->size = 1;
}
LList::LList(Node *value) { // convenience constructor for nodes of type Node
    this->head = this->tail= this->last = new Node(value);
    this->size = 1;
}
LList::LList() { // default constructor
    this->head = this->tail= this->last = nullptr;
    this->size = 0;
}


LList::LList(const LList &other) { // copy constructor
    if (other.head == nullptr) {   // Do not dereference reference identifier other
        head = tail = last = nullptr ;
        size = 0 ;
        return ;
    }


    else {
        // other not empty -> copy all other's nodes to new nodes linked in receiver
        head = new Node(other.head->valueInt()) ;  // Copy first node
        head->previous(nullptr) ;
        Node* node1 = head  ;
        Node* node2 = other.head->next() ;

        // make copies of each node
        while (node2) {
            Node* next_node = new Node(node2->valueInt()) ;
            node1->next(next_node) ;
            next_node->previous(node1) ;
            node2 = node2->next() ;
            node1 = next_node ;
        }

        // fix the last node
        node1->next(nullptr) ;
        last = node1 ;
        size = other.size ;
    }
}

LList::~LList() { //destructor
    if (head) {
        recursive_delete(head) ;  // recursively delete from last node
    }
}

LList &LList::append(int x) { // append to the end of the list (for integers)
    // empty list
    if (head == nullptr) {
        head = tail = last = new Node(x) ;
    }
    else {
        // otherwise insert at end of list
        last->next(new Node(x)) ;
        last = last->next() ;
    }
    if (this->head->next() != nullptr){
        this->tail = this->head->next();
    }else{
        this->tail = nullptr;
    }
    size++ ;

    // return receiver by reference to support cascading of calls
    return *this ;
}

LList &LList::append(Node *x) { // overloaded append method to the end of the list (for Node types)
    // empty list
    if (head == nullptr) {
        head = tail = last = new Node(x) ;
    }
    else {
        // otherwise insert at end of list
        last->next(new Node(x)) ;
        last = last->next() ;
    }
    if (this->head->next() != nullptr){
        this->tail = this->head->next();
    }else{
        this->tail = nullptr;
    }
    size++ ;

    // return receiver by reference to support cascading of calls
    return *this ;
}



int LList::find_element(int x) { // find an element with specific value
    Node* cursor = head ;
    int position = 0 ;
    while (cursor != nullptr) {
        if (cursor->valueInt() == x)
            return position ;
        position++ ;
        cursor = cursor->next() ;
    }
    return -1 ; // not found
}

bool LList::DL_scan(int x, Node *node_ptr) {
    if (!node_ptr) {
        return false ;
    }
    if (node_ptr->valueInt() == x)
        return true ;
    return DL_scan(x, node_ptr->next()) ;
}

// recursively delete nodes from list
void LList::recursive_delete(Node *aNode) {
    if (aNode->next() != nullptr) {
        recursive_delete(aNode->next()) ;// go down to last node
    }
    delete aNode ;
}


std::ostream &operator<<(std::ostream &oStream, const LList &aList) {
    oStream << "LList with elements: "  ;
    Node* cursor = aList.head ;
    while (cursor) {
        if (cursor->type == "integer"){
            oStream << cursor->valueInt() << ", " ;
            cursor = (*cursor).next() ;
        }
        else if (cursor->type == "list"){
//            oStream << LList(cursor->_data.integer);
        }

    }
    oStream << std::endl ;
    return oStream ;
}

// print the list
void LList::printList(Node* head) {
    Node* t = head;
    while (t){
        if (t->type == "integer"){
            std::cout << t->valueInt() << ", " ;

        }
        else if (t->type == "list"){
            std::cout <<" [";
            printList(t->valueList());
            std::cout <<"], ";
        }
        t = (*t).next() ;
    }
}

// prepend integer node to the beginning of the list
LList &LList::prepend(int x) {
    auto newNode = new Node(x);
    // empty list
    if (head == nullptr) {
        head  = newNode ;
    }
    else {
        // otherwise insert at end of list
        newNode->next(this->head);
        this->head = newNode;
    }
    if (this->head->next() != nullptr){
        this->tail = this->head->next();
    }else{
        this->tail = nullptr;
    }

    size++ ;

    // return receiver by reference to support cascading of calls
    return *this ;
}

// prepend Node node to the beginning of the list
LList &LList::prepend(Node* x) {
    auto newNode = new Node(x);
    // empty list
    if (head == nullptr) {
        head  = newNode ;
    }
    else {
        // otherwise insert at end of list
        newNode->next(this->head);
        this->head = newNode;
    }
    if (this->head->next() != nullptr){
        this->tail = this->head->next();
    }else{
        this->tail = nullptr;
    }

    size++ ;

    // return receiver by reference to support cascading of calls
    return *this ;
}


