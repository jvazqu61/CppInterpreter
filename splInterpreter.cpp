//
// Created by Juan V. on 04/21/2021.
//

#include "splInterpreter.h"
#include "splInstImplement.h"

Spl::Spl() { // default constructor
    this->d_ram = new Memory();
    this->instructionCount = 0;
}
// print the identifiers memory with the current PC
void Spl::printList() {
    std::vector<std::pair<std::string,SplInst::ident>> elems(this->identifiers.begin(), this->identifiers.end());
    std::sort(elems.begin(), elems.end(), [](auto a,auto b){
        return (a.first < b.first) ;
    });
    std::sort(elems.begin(), elems.end(), [](auto a,auto b){
        return (a.second.type < b.second.type) ;
    });
    std::cout << "PC: " << d_ram->pc << std::endl;
    for ( const auto&pair: elems) {
        if (pair.second.type == "list"){
            std::cout << pair.first << " [";
            pair.second.list->printList(pair.second.list->head);
            std::cout << " ]\n" ;
        } else
            std::cout << "" << pair.first << ": " << pair.second.integer << "\n";
    }
}

// runs a single instruction read from the d_ram (read only memory)
void Spl::runInstruction() {
    std::unordered_map<std::string,std::string> inst = this->d_ram->getCurInstruction();

    // match the instruction keyword
    if (inst.at("keyword") == "NEWID") {
            NewId::newId(inst.at("params"), this->identifiers);

    }else if(inst.at("keyword") == "COMBINE"){
        Combine::combine(this->identifiers, inst.at("params"));

    }else if(inst.at("keyword") == "COPY"){
        Copy::listCopy(this->identifiers, inst.at("params"));

    }else if(inst.at("keyword") == "HEAD"){
        Head::listHead(this->identifiers, inst.at("params"));

    }else if(inst.at("keyword") == "TAIL"){
        Tail::listTail(this->identifiers, inst.at("params"));

    }else if(inst.at("keyword") == "ASSIGN"){
        Assign::assignInt(this->identifiers, inst.at("params"));

    }else if(inst.at("keyword") == "CHS"){
        Chs::chs(this->identifiers, inst.at("params"));

    }else if(inst.at("keyword") == "ADD"){
        Add::addInt(this->identifiers, inst.at("params"));

    }else if(inst.at("keyword") == "IF"){
        Jump::ifJump(this->identifiers, inst.at("params"),d_ram);

    }else if(inst.at("keyword") == "HLT"){
        printList();
        std::cout << "Finished executing the SPL program..\n";
        exit(1);

    }
    this->d_ram->updatePc();
}

// run the user commands
void Spl::userProgram() {
    std::string filename;
    char userCommand;

    // prompt user for a file name to load to memory
    std::cout << "Enter a filename to execute: ";
    std::cin >> filename;
    this->d_ram->readFileIntoMem(filename);

    // run in a loop the user commands, asking the user to enter a new command every iteration
    while (true){
        std::cout << "\nl: Executes a line of code\na: Executes all the instructions until a halt instruction\nq: quits program\n";
        std::cout << "Enter a command: ";
        std::cin >> userCommand;
        switch (userCommand){
            // l– Executes a line of code, starting from line 0, updates the PC, and the memory according to the
            //    instruction and prints the values of memory, the PC after the line is executed.
            case 'l':
                runInstruction();
                printList();
                this->instructionCount++;
                break;

            // a – Executes all the instructions until a halt instruction is encountered or there are no more instructions
            //     to be executed. The values of the PC and the data memory are printed.
            case 'a':
                while(this->d_ram != nullptr){
                    runInstruction();
                    this->instructionCount++;
                }
                break;

            // quits the program
            case 'q':
                std::cout << "Exiting...";
                exit(1);

            default:
                std::cout << "Wrong command. Try again." << std::endl;

        }
        // program went into an infinite loop
        if (instructionCount > 1000){
            std::cout << "Infinite Loop...\n";
            exit(-1);
        }
    }
}

