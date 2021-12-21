/*
* Created by Juan V. on 04/21/2021.
* SPL class
* contains 2 memories, a read-only memory that stores an SPL program loaded from the input file,
* and a memory holding identifiers declared in the program and the values bound to each identifier.
* the SPL Interpreter keeps a program counter (PC) holding the index position of the statement being currently executed
*/

#ifndef PROJECT4_SPLINTERPRETER_H
#define PROJECT4_SPLINTERPRETER_H
#include "ro_mem.h"
#include "splInstructions.h"
class Spl{
protected:
    Memory* d_ram;
    std::unordered_map<std::string,SplInst::ident> identifiers;
    int instructionCount;
public:
    Spl(); //default constructor
    void runInstruction();
    void userProgram();
    void printList();


};


#endif //PROJECT4_SPLINTERPRETER_H
