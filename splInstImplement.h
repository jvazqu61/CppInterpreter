/*
 * Created by Juan V. on 04/21/2021.
 * sub classes for the abstract SPLInst class
 */

#ifndef PROJECT4_SPLINSTIMPLEMENT_H
#define PROJECT4_SPLINSTIMPLEMENT_H

#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "splInstructions.h"
#include "ro_mem.h"


//identifier NEWID-> This statement declares a new identifier, which can be used in
//subsequent statements. The identifier is initialized with the null value
//(i.e., an empty list)
class NewId: public SplInst{
public:
    static void newId( std::string& identifier, std::unordered_map<std::string,ident>& identifierMem);
};


// identifier integer ASSIGN-> This statement assigns (binds) an integer constant to identifier.
class Assign: public SplInst{
public:
    static void assignInt(std::unordered_map<std::string,ident>& identifierMem, std::string params);
};


// identifier1 identifier2 ADD-> This statement adds the integers bound to the two arguments
// and stores the result in identifier1.
// **** Assuming both identifiers are of type integer
class Add: public SplInst{
public:
    static void addInt(std::unordered_map<std::string, ident> &identifierMem, std::string params);
};


// id list COMBINE-> The value bound to id is appended to the list bound to list.
// The value bound to id (i.e., an integer or a list) becomes the first element of the list
// bound to list. If id is bound to a list l1, l1 will become the first element of list
class Combine: public SplInst{
public:
    static void combine(std::unordered_map<std::string, ident> &identifierMem, std::string params);
};


// list1 list2 COPY-> The list bound to list1 is deep-copied and bound to identifier list2.
class Copy: public SplInst{
public:
    static void listCopy(std::unordered_map<std::string, ident> &identifierMem, std::string params);
};

// identifier1 identifier2 HEAD-> The first element of the list bound to identifier1 is
// bound to identifier2. This list is not modified
class Head: public SplInst{
public:
    static void listHead(std::unordered_map<std::string, ident> &identifierMem, std::string params);
};

// identifier1 identifier2 TAIL-> A list containing all elements but the first of identifier1
// is bound to identifier2. The list is not copied.
class Tail: public SplInst{
public:
    static void listTail(std::unordered_map<std::string, ident> &identifierMem, std::string params);
};

// identifier CHS-> This statement changes the sign of the integer value bound to identifier.
class Chs: public SplInst{
public:
    static void chs(std::unordered_map<std::string,ident>& identifierMem, std::string params);
};

// identifier1 positive int IF-> If identifier1 is an empty list or the number zero, jump to
// instruction at line positive int
// **** Assuming that the instruction the user asks for is in range 1-> last instruction
class Jump: public SplInst{
public:
    static void ifJump(std::unordered_map<std::string, ident> &identifierMem, std::string params,Memory* d_ram);
};

#endif //PROJECT4_SPLINSTIMPLEMENT_H
