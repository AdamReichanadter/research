/*
 * Symbol table
 */
#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
typedef struct {
    int table[10][4]; // Holds symbol/SSA information, [0] is the symbol, [1] is the location of the variable in the node, [2] is the current version of the variable, [3] is the position of the variable on the node
    int pos; // Keeps track of where to insert into the table
} symbolTable;
#endif