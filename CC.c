#include "Node.h"
#include "CC.h"


// Creates congruence classes from all of the current nodes
// TODO: Add the variable from the symbol table
void addCC(Node *nodes[], int size) {
    CC *newCC;
    // Loop through all the nodes
    for (int i = 0; i < size; i++) {
        int classPos = 0; // Where to add the CC in classes[] on the node
        nodes[i]->numOfClasses = 0;
        // Loop through all the variables in the node
        for (int j = 0; j < nodes[i]->index + 1; j++) {
            // Create the first CC for the node
            if (j == 0) {
                newCC = malloc(sizeof(CC));
                nodes[i]->classes[0] = newCC; // Create the first cc on the node
                newCC->size = 0;
            }
            // Update the use bit vector if its a use
            if (nodes[i]->usedef[j] == 0) {
                newCC->variables[j] = nodes[i]->variable[j]; // Add the variable to the CC
                newCC->use[j] = 1;
                newCC->size++;
            }
            // Update the def bit vector if its a def, create a new CC, and move on
            if (nodes[i]->usedef[j] == 1) {
                if (j != 0) {
                    newCC = malloc(sizeof(CC)); // Create a new CC
                    nodes[i]->numOfClasses++;
                }
                newCC->variables[j] = nodes[i]->variable[j]; // Add the variable to the CC
                newCC->def[j] = 1; // A def ends the congruence class
                newCC->size = 0;
                classPos++;
                nodes[i]->classes[nodes[i]->numOfClasses] = newCC;
                newCC->size++;
            }
        }
        nodes[i]->numOfClasses++; // Fix off by one
    }
}

// Updates the upwards and downwards exposed classes for each node
void updateExposed(Node *nodes[], int size) {
    // Loop through all the nodes
    for (int i = 0; i < size; i++) {
        // Case 1
        if (nodes[i]->numOfClasses == 0) {
            nodes[i]->upward = NULL;
            nodes[i]->downward = NULL;
            continue;
        }
        // Case 2
        if (nodes[i]->numOfClasses == 1 && nodes[i]->classes[0]->use[0] == 1) {
            nodes[i]->upward = nodes[i]->classes[0];
            nodes[i]->downward = nodes[i]->classes[0];
            continue;
        }
        // Case 3
        if (nodes[i]->classes[0]->def[0] == 1) {
            nodes[i]->upward = NULL;
            nodes[i]->downward = nodes[i]->classes[nodes[i]->numOfClasses - 1];
            continue;
        }
        // Case 4
        if (nodes[i]->classes[0]->use[0] == 1) {
            nodes[i]->upward = nodes[i]->classes[0];
        } else {
            nodes[i]->upward = NULL;
        }
        nodes[i]->downward = nodes[i]->classes[nodes[i]->numOfClasses - 1]; // The last class is always downwards exposed
    }
}

// Input: nodes[] is an array of nodes, size is the number of nodes
// Prints out all nodes, congruence classes, and associated variables
// Doesn't show the break up the classes between nodes but I can assure you that they are broken up
void printCC(Node *nodes[], int size) {
    // For each node
    for (int i = 0; i < size; i++) {
        printf("nodes[%d] = %d\n", i, nodes[i]);
        // For each CC in each node
        for (int j = 0; j < 3; j++) {
            printf("  classes[%d] = 0x%04x\n", j, nodes[i]->classes[j]);
            for (int k = 0; k < 6; k++) {
                printf("    variables[%d] = 0x%04x\n", j, nodes[i]->classes[j]->variables[k]);
            }
        }
    }
}