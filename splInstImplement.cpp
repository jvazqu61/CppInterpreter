//
// Created by Juan V. on 04/21/2021.
// method implementation for subclasses
//

#include "splInstImplement.h"

void NewId::newId(std::string& identifier, std::unordered_map<std::string,ident>& identifierMem) {
    ident t{};
    t.list = nullptr;
    t.integer = -1;
    t.type = " ";
    identifier.erase(std::remove(identifier.begin(), identifier.end(), ' '), identifier.end());
    identifierMem.insert({identifier, t});

}

void Assign::assignInt(std::unordered_map<std::string, ident> &identifierMem, std::string params) {
    std::vector<std::string>  p = SplInst::splitParams(params);
    ident t{};
    t.integer = std::stoi(p[1]); // assign the value
    t.type = "integer"; // set the type
    identifierMem[p[0]] = t;
}


void Add::addInt(std::unordered_map<std::string, ident> &identifierMem, std::string params) {
    std::vector<std::string>  p = SplInst::splitParams(params);

    // check that both identifiers are integers
    if (identifierMem[p[0]].type == "integer" && identifierMem[p[1]].type == "integer"){
        auto i1 = identifierMem[p[0]];
        auto i2 = identifierMem[p[1]];
        // add both values and store results in identifier 1
        identifierMem[p[0]].integer = ( i1.integer + i2.integer);;
    }
}

void Combine::combine(std::unordered_map<std::string, ident> &identifierMem, std::string params) {
    std::vector<std::string>  p = SplInst::splitParams(params);

    // check that second arg is an nil or list
    if (identifierMem[p[1]].list != nullptr){
        // if list is an integer, run time error
        if (identifierMem[p[1]].type == "integer"){
            std::cout << "Error -> second arg must be a list\n";
            exit(-1);
        }
        else if (identifierMem[p[1]].type == "list"){
            if (identifierMem[p[0]].type == "integer"){
                identifierMem[p[1]].list->prepend(identifierMem[p[0]].integer); // prepend the value of first identifier

            }else{
                identifierMem[p[1]].list->prepend(identifierMem[p[0]].list->head);
            };
        }
    }
    else{ // identifier is bound to nil, create a new linked list or integer
        identifierMem[p[1]].type = "list";
        identifierMem[p[1]].list = new LList();
        if (identifierMem[p[0]].type == "integer"){
            identifierMem[p[1]].list->prepend(identifierMem[p[0]].integer);
        } else{
            identifierMem[p[1]].list->prepend(identifierMem[p[0]].list->head);
        }

    }
}

void Copy::listCopy(std::unordered_map<std::string, ident> &identifierMem, std::string params) {
    std::vector<std::string>  p = SplInst::splitParams(params);
    identifierMem[p[1]].type = "list";
    identifierMem[p[1]].list = new LList();
    if (identifierMem[p[0]].list != nullptr){

        auto t = identifierMem[p[0]].list->head;
        // make deep copies of all nodes in list 1 and add to list 2
        while (t != nullptr){
            if (t->type == "list"){
                auto l = t->valueList();
                identifierMem[p[1]].list->append(l);
            }else if (t->type == "integer"){
                identifierMem[p[1]].list->append(t->valueInt());
            }
            t = t->next();
        }
    }

}

void Head::listHead(std::unordered_map<std::string, ident> &identifierMem, std::string params) {\
    std::vector<std::string>  p = SplInst::splitParams(params);

    // check if head is an integer or another list
    if ((identifierMem[p[0]].type == "list" && identifierMem[p[0]].list != nullptr)  ){
        // check if list is actually a list, if an integer is passed: runtime error
        if (identifierMem[p[0]].type == "integer"){
            std::cout << "Error -> first argument must be a list..\n";
            exit(-1);
        } else if (identifierMem[p[0]].type == "list"){
            auto val = identifierMem[p[0]];
            if ( identifierMem[p[0]].list->head != nullptr){
                if (identifierMem[p[0]].list->head->type == "integer"){
                    identifierMem[p[1]].type = "integer";
                    identifierMem[p[1]].integer = val.list->head->valueInt();
                }
                else{
                    identifierMem[p[1]].type = "list";
                    identifierMem[p[1]].list = new LList();
                    identifierMem[p[1]].list->head = val.list->head->valueList();
                }
            }else{
                if (val.list->head == nullptr){
                    identifierMem[p[1]].type = "list";
                    identifierMem[p[1]].list = nullptr;
                }
                else{
                    identifierMem[p[1]].type = "list";
                    identifierMem[p[1]].list = new LList();
                    identifierMem[p[1]].list->head = val.list->head->valueList();
                }
            }
        }
    }else{ // empty list, identifier 2 also bound to nil
        identifierMem[p[1]].type = "list";
        identifierMem[p[1]].list = nullptr;
    }

}

void Tail::listTail(std::unordered_map<std::string, ident> &identifierMem, std::string params) {
    std::vector<std::string>  p = SplInst::splitParams(params);

    // check that identifier 1 is a list
    if (identifierMem[p[0]].list != nullptr){
        // runtime error if not a list
        if (identifierMem[p[0]].type == "integer"){
            std::cout << "ERROR -> second argument must be a list\n";
            exit(-1);
        }
         // set the 'tail' node to be bound to identifier 2
         if (identifierMem[p[0]].type == "list"){
             identifierMem[p[1]].type = "list";
            identifierMem[p[1]].list = new LList();
            identifierMem[p[1]].list->head = identifierMem[p[0]].list->tail;
            if (identifierMem[p[1]].list->head != nullptr){
                identifierMem[p[1]].list->tail = identifierMem[p[1]].list->head->next();
            }
        }
    }else{ // identifier for list 1 is bound to empty new list
        identifierMem[p[1]].type = "list";
        identifierMem[p[1]].list = new LList();
    }

}

void Chs::chs(std::unordered_map<std::string, ident> &identifierMem, std::string params) {
    std::vector<std::string>  p = SplInst::splitParams(params);

    // make sure identifier is not a list
    if (identifierMem[p[0]].type == "list"){
        std::cout << "Error -> identifier should be of type integer..\n";
        exit(-1);
    }
    // set the sign of the value
    auto val = identifierMem[p[0]].integer;
    identifierMem[p[0]].integer = val*-1;

}

void Jump::ifJump(std::unordered_map<std::string, ident> &identifierMem, std::string params,Memory* d_ram) {

    std::vector<std::string>  p = SplInst::splitParams(params);
    if ((identifierMem[p[0]].type == "integer" && identifierMem[p[0]].integer == 0) ||
            (identifierMem[p[0]].type == "list" && identifierMem[p[0]].list->head == nullptr)){
        d_ram->setPc(std::stoi(p[1])-1);
    }
}
