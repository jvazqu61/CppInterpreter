/*
* Created by Juan V. on 04/18/2021.
* Node class: each node contains a pointer to the next node. The
*             data can be of type Node or an integer.
*
*/

#ifndef PROJECT4_NODE_H
#define PROJECT4_NODE_H

#include <string>

class Node{
protected:
    union {
        Node* list;
        int integer;
    }_data{};
    Node* _next;
    Node* _previous{} ;


public:
    std::string type;
    Node(); // default constructor
    explicit Node(int value); // convenience constructor for int value
    explicit Node(Node* value);// convenience constructor for Node value

    // inline functions
     inline int valueInt() {
        return _data.integer;
    }
    inline Node* valueList() {
        return _data.list;
    }
    inline Node* next() {
        return _next ;
    }
    inline Node* previous() {
        return _previous ;
    }
    inline Node& value(int newValue) {
        _data.integer = newValue ;
        return *this ;
    }
    inline Node& value(Node* newValue) {
        _data.list = newValue ;
        return *this ;
    }
    inline Node& next(Node* newNext) {
        _next = newNext ;
        return *this ;
    }
    inline Node& previous(Node* newPrevious) {
        _previous = newPrevious ;
        return *this ;
    }

};





#endif //PROJECT4_NODE_H
