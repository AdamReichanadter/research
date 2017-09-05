
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
// TODO: 0's always get turned into null
void add(void *value, Node *v, symbolTable *symbol) {
    symbol->table[symbol->pos][0] = (int) value; // The value of the symbol
    symbol->table[symbol->pos][1] = (int) findPos(v); // The index of the associated node
    // Because it keeps turning 0's into NULL
    if (symbol->table[symbol->pos][1] == NULL) {
        symbol->table[symbol->pos][1] = NULL;
    }
    symbol->table[symbol->pos][2] = (int) 1; // The current version of the variable
    // Loop backwards through the symbol table to check for versions
    for (int i = symbol->pos - 1; i >= 0; i--) {
        // If the symbol already exists
        if (symbol->table[i][0] == value) {
            symbol->table[symbol->pos][2] = (int) symbol->table[i][2] + 1; // Update the version
            break; // We found the most recent version
        }
    }
    symbol->pos++; // The index is the key for each symbol
}

// Returns the symbol at the given index
void *getSymbol(int i, symbolTable *symbol) {
    return symbol->table[i][0];
}