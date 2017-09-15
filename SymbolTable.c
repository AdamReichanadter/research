
#include "SymbolTable.h"
#include <stdlib.h>

int findPos(Node *v);

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
    int position = findPos(v); // Get the position of the variable on the node
    symbol->table[symbol->pos][1] = position; // The index of the variable on the associated node
    symbol->table[symbol->pos][2] = 0; // The current version of the variable
    // Loop backwards through the symbol table to check for versions
    for (int i = symbol->pos - 1; i >= 0; i--) {
        // If the symbol already exists
        if (symbol->table[i][0] == value) {
            symbol->table[symbol->pos][2] = symbol->table[i][2] + 1; // Update the version
            break; // We found the most recent version
        }
    }
    symbol->pos++; // The index is the key for each symbol
}

// Returns the requested symbol
int getSymbol(int value, symbolTable *symbol) {
    for (int i = symbol->pos - 1; i >= 0; i--) {
        if (symbol->table[i][0] == value) {
            return value;
        }
    }
    return -1; // If there is no value
}