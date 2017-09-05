#include "Predicate.h"

// Key for the predicate object
typedef struct {
    char predTable[10];
    int size;
} predTable;

// Creates the predicate table
predTable *createTable() {
    predTable *table = malloc(sizeof(predTable));
    table->size = 0;
    return table;
}

// Adds a character to the predicate table
void addKey(char c, predTable *table) {
    table->predTable[table->size] = c;
    table->size++;
}

// Creates a predicate
// Input: 0 if AND, 1 if TRUE, and 2 if OR; returns the predicate
Predicate *addPred(int type) {
    Predicate *newPred = malloc(sizeof(Predicate));
    newPred->type = type;
    newPred->numberOfChildren = 0;
    newPred->pred[0] = newPred;
    return newPred;
}

// Input: parent predicate
// Input: 0 if AND, 1 if TRUE, and 2 if OR; returns the predicate
Predicate *addChild(Predicate *predicate, int type) {
    Predicate *newPred = malloc(sizeof(Predicate));
    newPred->type = type;
    predicate->numberOfChildren++;
    predicate->pred[predicate->numberOfChildren] = newPred; // Link it to the parent
    return newPred;
}

// Checks if the value is in the key and then marks the appropriate index in the bit vector
void addValue(char c, Predicate *pred, predTable *predTable) {
    for (int i = 0; i < predTable->size; i++) {
        if (predTable->predTable[i] == c) {
            pred->complement[i] = 0;
            pred->bitvec[i] = 1;
        }
    }
}

// Computes a new predicate from a || b
Predicate *combineOr(Predicate *a, Predicate *b, predTable *table) {
    // If one predicate is true then the resulting predicate is the other
    Predicate* result;
    if (a->type == 1) {
        result = b;
        return result;
    }
    if (b->type == 1) {
        result = a;
        return result;
    }
    // or || or
    if (a->type == 2 && b->type == 2) {
        for (int i = 1; i <= b->numberOfChildren; i++) {
            a->pred[a->numberOfChildren + 1] = b->pred[i];
            a->numberOfChildren++;
        }
        result = a;
        return result;
    }
    // and || and
    if (a->type == 0 && b->type == 0) {
        result = addPred(2); // The combination of a and b
        Predicate *c = addChild(result, 0);
        Predicate *d = addChild(result, 0);
        // Copy the bit vectors
        for (int i = 0; i < table->size; i++) {
            c->bitvec[i] = a->bitvec[i];
            d->bitvec[i] = b->bitvec[i];
        }
        return result;
    }
    // and || or
    if (a->type == 0 && b->type == 2) {
        b->pred[b->numberOfChildren + 1] = a;
        b->numberOfChildren++;
        result = b;
        return result;
    }
    // or || and
    if (b->type == 0 && a->type == 2) {
        a->pred[a->numberOfChildren + 1] = b;
        a->numberOfChildren++;
        result = a;
        return result;
    }
}

// Computes a new predicate from a && b
Predicate *combineAnd(Predicate *a, Predicate *b, predTable *table) {
    // If one predicate is true then the resulting predicate is the other
    Predicate* result;
    if (a->type == 1) {
        result = b;
        return result;
    }
    if (b->type == 1) {
        result = a;
        return result;
    }
    // AND && AND
    if (a->type == 0 && b->type == 0) {
        result = addPred(0);
        // Combine the bit vectors into a new one
        for (int i = 0; i < table->size; i++) {
            if (a->bitvec[i] == 1 || b->bitvec[i] == 1) {
                result->bitvec[i] = 1;
            }
        }
        return result;
    }
    // AND && OR
    if (a->type == 0 && b->type == 2) {
        // For each child
        for (int i = 0; i < b->numberOfChildren; i++) {
            // For each position in the bit vector
            for (int j = 0; j < table->size; j++) {
                if (a->bitvec[j] == 1) {
                    b->pred[i + 1]->bitvec[j] = 1;
                }
            }
        }
        result = b;
        return result;
    }

    // OR && AND
    if (b->type == 0 && a->type == 2) {
        for (int i = 0; i < a->numberOfChildren; i++) {
            // For each position in the bit vector
            for (int j = 0; j < table->size; j++) {
                if (b->bitvec[j] == 1) {
                    a->pred[i + 1]->bitvec[j] = 1;
                }
            }
        }
        result = a;
        return result;
    }
    // OR && OR
    if (a->type == 2 && b->type == 2) {
        Predicate *result = addPred(2); // New OR predicate
        // For each child in a
        for (int i = 1; i <= a->numberOfChildren; i++) {
            // For each child in b
            for (int j = 1; j <= b->numberOfChildren; j++) {
                addChild(result, 0);
                // For each entry in their bit vectors
                for (int k = 0; k < table->size; k++) {
                    // OR them together
                    if ((b->pred[j]->bitvec[k] == 1) || (a->pred[i]->bitvec[k] == 1)) {
                        result->pred[result->numberOfChildren]->bitvec[k] = 1;
                    }
                }
            }
        }
        return result;
    }
}


void printChildren(Predicate *predicate, predTable *predTable) {
    for (int i = 0; i <= predicate->numberOfChildren; i++) {
        for (int j = 0; j < predTable->size; j++) {
            int current = predicate->pred[i]->bitvec[j]; // Current entry in the bit vector
            if (current == 1) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n"); // New line for formatting
    }
}

void traverse(Predicate *predicate, predTable *predTable) {
    for (int i = 0; i <= predicate->numberOfChildren; i++) {
        int type = predicate->pred[i]->type; // Type of the current predicates
        // AND case
        if (type == 0) {
            bool and = true;
            for (int j = 0; j < predTable->size; j++) {
                int current = predicate->pred[i]->bitvec[j]; // Current entry in the bit vector
                if (current != 1) {
                    and = false;
                    break;
                }
            }
            if (and) {
                printf("true\n");
            } else {
                printf("false\n");
            }
        }

        // TRUE case
        if (type == 1) {
            printf("true\n");
        }

        // OR case
        if (type == 2) {
            bool or = false;
            for (int j = 0; j < predTable->size; j++) {
                int current = predicate->pred[i]->bitvec[j]; // Current entry in the bit vector
                if (current == 1) {
                    or = true;
                    break;
                }
            }
            if (or) {
                printf("true\n");
            } else {
                printf("false\n");
            }
        }
    }
}