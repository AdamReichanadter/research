/*
 * Symbol table
 */
#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
typedef struct {
    int table[10][3]; // Holds symbol/SSA information
    int pos; // Keeps track of where to insert into the table
} symbolTable;
#endif