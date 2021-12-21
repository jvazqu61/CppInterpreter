//
// Created by Juan V. on 04/18/2021.
// Node class methods implementation
//

#include "node.h"

Node::Node() { // default constructor
    this->_data.list = nullptr;
    this->_data.integer = 0;
    this->_next = nullptr;
}

Node::Node(int value) { // convenience constructor for int value
    this->_data.integer = value;
    this->_next = nullptr;
    this->type = "integer";
}

Node::Node(Node *value) { // convenience constructor for Node value
    this->_data.list = value;
    this->_next = nullptr;
    this->type = "list";
}
