#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "Node.h"
#include "tests.c"
#include "SymbolTable.c"
#include "PredicateTable.c"
#include "Predicate.h"
#include "CC.c"

Node *getPredecessor(Node *v);

Node *getSuccessor(Node *v);

Node *addNode();

void addVariable(Node *node, void *v, int usedef, symbolTable* table);

Node *addEdge(Node *u, Node *v);

void setEdge(Node *edge, void *v, int usedef);

Node *removeNode(Node *v);

int findPos(Node *v);

void freeAll();

void initArrays(int n);

void printNodes();

void printMatrix();

// -------------- End of prototypes ------------------ //

int size = 0; // Number of nodes
Node *nodes[20]; // Holds all the nodes
int valid[20]; // 0 if the node has been removed, 1 if it has not
Node *matrix[20][20]; // Holds all the edges between the nodes

// Initializes the arrays of the specified size
void initArrays(int n) {
    nodes[20] = nodes[n];
    matrix[20][20] = matrix[n][n];
    valid[20] = valid[n];
}


// Input: a generic node
// Finds the index of the node or -1 if not found
int findPos(Node *v) {
    for (int i = 0; i < size; i++) {
        if (nodes[i] == v) {
            return i;
        }
    }
    return -1; // if there is no match
}

// Input: generic value v, int usedef 0 (use) 1 (def) -1(neither)
// Creates a new object and adds it to nodes[], returns the created node
Node *addNode() {
    Node *newNode = malloc(sizeof(Node));
    newNode->index = 0; // Initialize the index to 0
    nodes[size] = newNode;
    valid[size] = 1; // Mark the node as valid
    size++;
    return newNode;
}

//Input: a node, and a new value
// Updates the node with a new instance of a variable
void addVariable(Node *node, void *v, int usedef, symbolTable* table) {
    int i = node->index;
    node->variable[i] = v;
    node->usedef[i] = usedef;
    add(v, node, table); // Adding it to the symbol table
    node->index++; // Keep sequential ordering
}

//Input: generic value e, starting node u, ending node v
// Adds an edge into matrix between the specified nodes
Node *addEdge(Node *u, Node *v) {
    int i = findPos(u); // Getting their positions in nodes[]
    int j = findPos(v);
    Node *newEdge = malloc(sizeof(Node));
    newEdge->index = 0;
    matrix[i][j] = newEdge;
    return newEdge;
}

// Input: a node
// Output: the removed node, returns the removed node
//TODO: give a meaningful value when adding an edge
//TODO: be able to connect multiples nodes with multiple edges
Node *removeNode(Node *v) {
    int pos = findPos(v);
    Node *removed = v;
    Node *predecessor = getPredecessor(removed);
    Node *successor = getSuccessor(removed);
    valid[pos] = 0; // Marking the node as removed

    // Remove incoming edges
    for (int i = 0; i < size; i++) {
        if (matrix[i][pos] != NULL) {
            matrix[i][pos] = NULL;
        }
    }
    // Remove outgoing edges
    for (int j = 0; j < size; j++) {
        if (matrix[pos][j] != NULL) {
            matrix[pos][j] = NULL;
        }
    }
    // Connect the predecessor and successor nodes if its an inner node
    if (findPos(predecessor) != -1 || findPos(successor) != -1) {
        addEdge(predecessor, successor);
    }
    return removed;
}

// Input: any node
// Output: the first successor it finds
// TODO: return ALL its successors
Node *getSuccessor(Node *v) {
    int node = findPos(v); // -1 if nothing is found
    if (node != -1) {
        for (int j = 0; j < size; j++) {
            if (matrix[node][j] != NULL) {
                return nodes[j]; // Found the successor
            }
        }
    }
    printf("This node has no successors\n"); // Debug
    return NULL;
}

// Input: any node
// Output: the first predecessor it finds
// TODO: return ALL its predecessors
Node *getPredecessor(Node *v) {
    int node = findPos(v); // -1 if nothing is found
    if (node != -1) {
        for (int i = 0; i < size; i++) {
            if (matrix[i][node] != NULL) {
                return nodes[i]; // Found the predecessor
            }
        }
    }
    printf("This node has no predecessors\n"); // Debug
    return NULL;
}

// Frees all the memory used
void freeAll() {
    //Free the nodes
    for (int i = 0; i < size; i++) {
        if (nodes[i] != NULL) {
            free(nodes[i]);
        }
    }
    //Free the edges
    for (int j = 0; j < size; ++j) {
        for (int i = 0; i < size; ++i) {
            if (matrix[i][j] != NULL) {
                free(matrix[j][i]);
            }
        }
    }
}

// Prints out everything in nodes
void printNodes() {
    for (int i = 0; i < size; i++) {
        if (valid[i] != 0) {
            printf("nodes[%d] = ", i);
            // For each variable in the node
            for (int j = 0; j < nodes[i]->index; j++) {
                printf("0x%04x ", (int) nodes[i]->variable[j]);
                if (nodes[i]->usedef[j] == 0) {
                    printf("is a use ");
                }
                if (nodes[i]->usedef[j] == 1) {
                    printf("is a def ");
                }
            }
            printf("\n");
        }
    }
}

// Prints out everything in matrix
void printMatrix() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != NULL) {
                printf("edge between [%d] and [%d] = %d\n", i, j, (int) matrix[i][j]->variable[matrix[i][j]->index]);
            }
        }
    }
}

int main() {
    // Testing purposes
//    predTable* table = createTable();
//    addKey('p', table);
//    addKey('q', table);
//    addKey('r', table);
//    addKey('s', table);
//    Predicate* a = addPred(2);
//    Predicate* b = addPred(2);
//    Predicate* c = addChild(a, 0);
//    Predicate* d = addChild(a, 0);
//    Predicate* e = addChild(b, 0);
//    Predicate* f = addChild(b, 0);
//    addValue('p', c, table);
//    addValue('q', d, table);
//    addValue('r', e, table);
//    addValue('s', f, table);
//    Predicate* g = combineAnd(a, b, table);
//    printChildren(a, table);
//    traverse(a, table);

    Node* a = addNode();
    Node* b = addNode();
    symbolTable* symbolTable = initTable();
    addVariable(a, (void *) 'a', 0, symbolTable);
    addVariable(a, (void *) 'a', 1, symbolTable);
    addVariable(a, (void *) 'b', 0, symbolTable);
    addVariable(a, (void *) 'b', 1, symbolTable);
    addVariable(b, (void *) 'c', 1, symbolTable);
    addVariable(b, (void *) 'd', 0, symbolTable);
    addVariable(b, (void *) 'c', 1, symbolTable);
    addVariable(b, (void *) 'd', 0, symbolTable);
    addCC(nodes, size);
    updateExposed(nodes, size);

    return 0;
}