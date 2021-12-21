/*
 * Created by Juan V. on 04/21/2021.
 * SplInst class: abstract superclass for SPL instructions with concrete
 *                subclasses for each particular instruction.
*/

#ifndef PROJECT4_SPLINSTRUCTIONS_H
#define PROJECT4_SPLINSTRUCTIONS_H
#include "LList.h"
#include "ro_mem.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
class SplInst{
public:

    struct ident{
        int integer;
        LList* list;
        std::string type; // integer or Node
    };

protected:
    static std::vector<std::string>  splitParams(const std::string& params){
        std::istringstream iss(params);
        std::vector<std::string> p(std::istream_iterator<std::string>{iss},
                                   std::istream_iterator<std::string>());
        return p;
    }
    void newId( std::string& identifier, std::unordered_map<std::string,ident>& identifierMem);
    void combine(std::unordered_map<std::string, ident> &identifierMem, std::string params);
    void listCopy(std::unordered_map<std::string, ident> &identifierMem, std::string params);
    void listHead(std::unordered_map<std::string, ident> &identifierMem, std::string params);
    void listTail(std::unordered_map<std::string, ident> &identifierMem, std::string params);
    void assignInt(std::unordered_map<std::string,ident>& identifierMem, std::string params);
    void chs(std::unordered_map<std::string,ident>& identifierMem, std::string params);
    void addInt(std::unordered_map<std::string, ident> &identifierMem, std::string params);
    void ifJump(std::unordered_map<std::string, ident> &identifierMem, std::string params,Memory* d_ram);
    void hlt(std::unordered_map<std::string, ident> &identifierMem, std::string params);


};




#endif //PROJECT4_SPLINSTRUCTIONS_H
