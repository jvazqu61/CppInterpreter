/*
 * Created by Juan V. on 04/18/2021.
 * Memory class: a read-only memory that stores an SPL program loaded from the
 *                input file. Uses a linked list as the "memory"
*/

#ifndef PROJECT4_RO_MEM_H
#define PROJECT4_RO_MEM_H
#include "LList.h"
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>

class Memory{
protected:
    std::vector<std::unordered_map<std::string,std::string >> memory;
public:
    int pc;
    Memory();
    std::unordered_map<std::string,std::string > parseLine(std::string line);
    void readFileIntoMem(std::string file);
    std::unordered_map<std::string, std::string> getCurInstruction();
    void setPc(int);
    void updatePc();

};

#endif //PROJECT4_RO_MEM_H
