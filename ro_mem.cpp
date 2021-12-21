//
// Created by Juan V. on 04/18/2021.
// Memory class methods implementation
//

#include "ro_mem.h"

Memory::Memory() { // default constructor
this->pc = 0;

}

// parse each line from the file into tokens
std::unordered_map<std::string, std::string> Memory::parseLine(std::string line) {
    std::unordered_map<std::string, std::string> tokens;

    std::vector<std::string> lineSplit;
    std::istringstream f(line);
    std::string s;
    while (getline(f, s, ' ')) {
        lineSplit.push_back(s);
    }

    std::string params;
    tokens.insert({"keyword", lineSplit.back()});
    lineSplit.pop_back();
    for(const auto &l: lineSplit ) params += (l + " ");
    tokens.insert({"params", params});
    return tokens;
}


// add the file into the read-only memory
void Memory::readFileIntoMem(std::string file) {
    std::ifstream f;
    f.open(file);

    if (!f.is_open()){
        std::cout << "File was not found\n";
        exit(-1);
    }
    std::string line;
    while (getline(f,line)){
        std::unordered_map<std::string, std::string> t = parseLine(line);
        this->memory.push_back(t);
    }
//    this->pc = 0;
}

// return contents of the instruction the PC is currently in
std::unordered_map<std::string, std::string> Memory::getCurInstruction() {
    return this->memory[pc];
}

// update the PC
void Memory::updatePc() {
    this->pc++;
}


//set the PC to another instruction
void Memory::setPc(int c) {
    this->pc = c;
}

