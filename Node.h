#include "CC.h"

#ifndef NODE_H
#define NODE_H
// Generic object for all the nodes AND edges in CFG
typedef struct {
    void *variable[10]; // Holds all the variables in the node
    int usedef[10]; // 0 if use, 1 if def
    int index; // Keeps track of sequential ordering
    CC *classes[10]; // All the CC's associated with the node
    int numOfClasses; // Number of CC's on the node
    CC *upward; // The upwards exposed class
    CC *downward; // The downwards exposed class
} Node;
#endif