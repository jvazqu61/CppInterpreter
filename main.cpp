/* Author: Juan Vazquez
* Last modified: 4-26-21
* CS 474: Project 4
* SPL interpreter in C++ -> Simple Programming Language Interpreter that has a set of instructions.
*                    SPL has just two data structures, integer numbers and linked lists. Linked
*                    list elements can be integers or linked lists themselves. Identifiers must be
*                    declared before they are used, but are not typed
*/

#include "splInterpreter.h"
int main() {
    Spl a;
    a.userProgram();
    return 0;
}
