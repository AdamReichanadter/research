#ifndef PREDICATE_H
#define PREDICATE_H

// Predicate object
typedef struct Predicate {
    int type; // And, true, or
    struct Predicate *pred[10]; // Stores pointers to other predicates
    int numberOfChildren;
    int bitvec[10]; // Index corresponds to the key in predTable
    int complement[10]; // Inverse of bitvec to show the complement
} Predicate;

#endif