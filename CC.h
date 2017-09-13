#ifndef CC_H
#define CC_H
// Congruence class
typedef struct {
    int use[10]; // Bit vector corresponding to uses
    int def[10]; // Bit vector corresponding to definitions
    void *variables[10]; // Stores the variables from the node into the congruence class, has same index as nodes[]
    int size; // Number of variable in the cc
} CC;

#endif