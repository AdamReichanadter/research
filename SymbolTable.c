
#include "SymbolTable.h"
#include <stdlib.h>

int findPos(Node *v);
int findVar(Node *v, void *value);

symbolTable *initTable();

// Initializes the table with a given size n
symbolTable *initTable() {
    symbolTable *table = malloc(sizeof(symbolTable));
    table->pos = 0;
    return table;
}

// Inserts data into the symbol table
void add(void *value, Node *v, symbolTable *symbol) {
    symbol->table[symbol->pos][0] = value; // The value of the symbol
    symbol->table[symbol->pos][1] = findPos(v); // The index of the associated node
    symbol->table[symbol->pos][2] = 0; // The current version of the variable
    symbol->table[symbol->pos][3] = findVar(v, value); // The index of the variable on the current node
    // Loop backwards through the symbol table to check for versions
    for (int i = symbol->pos - 1; i >= 0; i--) {
        // If the symbol already exists
        if (symbol->table[i][0] == value) {
            symbol->table[symbol->pos][2] = symbol->table[i][2] + 1; // Update the version and add it
            break; // We found the most recent version
        }
    }
    symbol->pos++; // The index is the key for each symbol
}

// Returns the symbol associated with the position of its value in variables[] on Node
int getSymbol(int position, symbolTable *symbol) {
    for (int i = symbol->pos - 1; i >= 0; i--) {
        if (symbol->table[i][1] == position) {
            return symbol->table[i][0];
        }
    }
    return -1; // If there is no value
}