///*
// * Some test cases
// */
//
//#include "Node.h"
//
//Node *addNode();
//
//Node *addEdge(Node *u, Node *v);
//
//void addVariable(Node *node, void *v, int usedef);
//
//void setPath(Node *node, bool b);
//
//void test1() {
//    Node *start = addNode();
//    Node *a = addNode();
//    Node *b = addNode();
//    addVariable(b, (void *) 'z', 0);
//    addVariable(b, (void *) 'x', 1);
//    Node *c = addNode();
//    addVariable(c, (void *) 'z', 0);
//    addVariable(c, (void *) 'y', 1);
//    Node *d = addNode();
//    Node *end = addNode();
//    addEdge(start, a);
//    Node *A = addEdge(a, b);
//    Node *B = addEdge(b, c);
//    Node *C = addEdge(c, d);
//    addEdge(d, end);
//}
//
//void test2() {
//    Node *start = addNode();
//    Node *a = addNode();
//    Node *b = addNode();
//    addVariable(b, (void *) 'a', 0);
//    addVariable(b, (void *) 'x', 1);
//    addVariable(b, (void *) 'x', 0);
//    addVariable(b, (void *) 'x', 1);
//    Node *c = addNode();
//    addVariable(c, (void *) 'x', 0);
//    addVariable(c, (void *) 'b', 1);
//    Node *d = addNode();
//    Node *end = addNode();
//    addEdge(start, a);
//    addEdge(a, b);
//    addEdge(b, c);
//    addEdge(c, d);
//    addEdge(d, end);
//}
//
//void test3() {
//
//}
//
//void test4() {
//    Node *start = addNode();
//    Node *a = addNode();
//    Node *b = addNode();
//    Node *c = addNode();
//    Node *d = addNode();
//    Node *end = addNode();
//    addEdge(start, a);
//    addEdge(a, b);
//    addEdge(b, c);
//    addEdge(c, d);
//    addEdge(b, d);
//    addEdge(d, end);
//    addVariable(b, 'x', 1);
//    setPath(b, true);
//    if (b->path) {
//        addVariable(c, 'x', 1);
//    }
//    addVariable(d, 'x', 0);
//    addVariable(d, 'z', 1);
//}
//
//void test5() {
//    Node *start = addNode();
//    Node *a = addNode();
//    Node *b = addNode();
//    Node *c = addNode();
//    Node *d = addNode();
//    Node *e = addNode();
//    Node *end = addNode();
//    addEdge(start, a);
//    addEdge(a, b);
//    addEdge(b, c);
//    addEdge(b, d);
//    addEdge(c, e);
//    addEdge(d, e);
//    addEdge(e, end);
//    setPath(b, false);
//    if (b->path) {
//        addVariable(c, 'x', 1);
//    } else {
//        addVariable(d, 'x', 1);
//    }
//    addVariable(e, 'x', 0);
//    addVariable(e, 'z', 1);
//}
//
//void test6() {
//    Node *start = addNode();
//    Node *a = addNode();
//    Node *b = addNode();
//    Node *c = addNode();
//    Node *d = addNode();
//    Node *e = addNode();
//    Node *f = addNode();
//    Node *g = addNode();
//    Node *end = addNode();
//    addEdge(start, a);
//    addEdge(a, b);
//    addEdge(b, c);
//    addEdge(b, d);
//    addEdge(c, g);
//    addEdge(d, e);
//    addEdge(d, f);
//    addEdge(e, g);
//    addEdge(f, g);
//    addEdge(g, end);
//    setPath(b, false);
//    if (b->path) {
//        addVariable(c, 'x', 1);
//    } else {
//        setPath(d, false);
//        if (d->path) {
//            addVariable(e, 'x', 1);
//        } else {
//            addVariable(f, 'x', 1);
//        }
//    }
//    addVariable(g, 'x', 0);
//    addVariable(g, 'y', 1);
//}
//
//void test7() {
//    Node *start = addNode();
//    Node *a = addNode();
//    Node *b = addNode();
//    Node *c = addNode();
//    Node *d = addNode();
//    Node *e = addNode();
//    Node *f = addNode();
//    Node *g = addNode();
//    Node *h = addNode();
//    Node *end = addNode();
//    addEdge(start, a);
//    addEdge(a, b);
//    addEdge(b, c);
//    addEdge(b, d);
//    addEdge(c, e);
//    addEdge(d, e);
//    addEdge(e, f);
//    addEdge(e, g);
//    addEdge(f, h);
//    addEdge(g, h);
//    addEdge(h, end);
//    setPath(b, true);
//    if (b->path) {
//        addVariable(c, 'x', 1);
//    } else {
//        addVariable(d, 'x', 1);
//    }
//    setPath(e, true);
//    if (e->path) {
//        addVariable(f, 'x', 0);
//        addVariable(f, 'y', 1);
//    } else {
//        addVariable(g, 'x', 0);
//        addVariable(g, 'y', 1);
//    }
//    addVariable(h, 'y', 0);
//    addVariable(h, 'z', 1);
//}
//
//void test8() {
//    Node *start = addNode();
//    Node *a = addNode();
//    Node *b = addNode();
//    Node *c = addNode();
//    Node *d = addNode();
//    Node *e = addNode();
//    Node *f = addNode();
//    Node *g = addNode();
//    Node *end = addNode();
//    addEdge(start, a);
//    addEdge(a, b);
//    addEdge(b, c);
//    addEdge(b, d);
//    addEdge(c, e);
//    addEdge(c, f);
//    addEdge(d, e);
//    addEdge(d, f);
//    addEdge(e, g);
//    addEdge(f, g);
//    addEdge(g, end);
//    setPath(b, false);
//    if (b->path) {
//        setPath(c, true);
//        if (c->path) {
//            addVariable(e, 'x', 1);
//        } else {
//            addVariable(f, 'x', 1);
//        }
//    } else {
//        setPath(d, true);
//        if (d->path) {
//            addVariable(f, 'x', 1);
//        } else {
//            addVariable(e, 'x', 1);
//        }
//    }
//    addVariable(g, 'x', 0);
//    addVariable(g, 'y', 1);
//}
//
//void test9() {
//    Node *start = addNode();
//    Node *a = addNode();
//    Node *b = addNode();
//    Node *c = addNode();
//    Node *d = addNode();
//    Node *e = addNode();
//    Node *f = addNode();
//    Node *g = addNode();
//    Node *end = addNode();
//    addEdge(start, a);
//    addEdge(a, b);
//    addEdge(b, c);
//    addEdge(b, d);
//    addEdge(c, e);
//    addEdge(d, e);
//    addEdge(d, f);
//    addEdge(e, g);
//    addEdge(f, g);
//    addEdge(e, end);
//    setPath(b, true);
//    if (b->path) {
//        addVariable(c, 'x', 1);
//    } else {
//        setPath(d, false);
//        addVariable(d, 'x', 1);
//    }
//    if (b->path || d->path) {
//        addVariable(e, 'x', 0);
//        addVariable(e, 'y', 1);
//    }
//    addVariable(g, 'y', 0);
//    addVariable(g, 'z', 1);
//}
//
//void test10() {
//    Node *start = addNode();
//    Node *a = addNode();
//    Node *b = addNode();
//    Node *c = addNode();
//    Node *end = addNode();
//    addEdge(start, a);
//    addEdge(a, b);
//    addEdge(b, b);
//    addEdge(b, c);
//    addEdge(c, end);
//    addVariable(a, 'x', 1);
//    addVariable(b, 'x', 0);
//    addVariable(b, 'x', 1);
//    setPath(b, false);
//    if (!b->path) {
//        addVariable(b, 'x', 0);
//        addVariable(b, 'x', 1);
//    }
//    addVariable(c, 'x', 0);
//    addVariable(c, 'y', 1);
//}
//
//void test11() {
//    Node *start = addNode();
//    Node *a = addNode();
//    Node *b = addNode();
//    Node *c = addNode();
//    Node *d = addNode();
//    Node *e = addNode();
//    Node *end = addNode();
//    addEdge(start, a);
//    addEdge(a, b);
//    addEdge(b, c);
//    addEdge(c, d);
//    addEdge(d, c);
//    addEdge(d, e);
//    addEdge(e, end);
//    addVariable(b, 'x', 1);
//    addVariable(d, 'x', 0);
//    addVariable(d, 'x', 1);
//    setPath(d, false);
//    if (!d->path) {
//        addVariable(d, 'x', 0);
//        addVariable(d, 'x', 1);
//    }
//}
//
//void test12() {
//    Node *start = addNode();
//    Node *a = addNode();
//    Node *b = addNode();
//    Node *c = addNode();
//    Node *end = addNode();
//    addEdge(start, a);
//    addEdge(a, b);
//    addEdge(b, b);
//    addEdge(b, c);
//    addEdge(c, end);
//    addVariable(b, 'x', 1);
//    setPath(b, false);
//    if (!b->path) {
//        addVariable(b, 'x', 1);
//    }
//    addVariable(c, 'p', 0);
//    addVariable(c, 'y', 1);
//}
//
//void test13() {
//    Node *start = addNode();
//    Node *a = addNode();
//    Node *b = addNode();
//    Node *c = addNode();
//    Node *d = addNode();
//    Node *end = addNode();
//    addEdge(start, a);
//    addEdge(a, b);
//    addEdge(b, c);
//    addEdge(c, c);
//    addEdge(c, d);
//    addEdge(d, end);
//    addVariable(b, 'z', 1);
//    setPath(c, false);
//    if (!c->path) {
//
//    }
//    addVariable(c, 'z', 0);
//    addVariable(c, 'y', 1);
//}
//
//// Incomplete
//void test14() {
//    Node *start = addNode();
//    Node *a = addNode();
//    Node *b = addNode();
//    Node *c = addNode();
//    Node *d = addNode();
//    Node *e = addNode();
//    Node *f = addNode();
//    Node *g = addNode();
//    Node *h = addNode();
//    Node *end = addNode();
//    addEdge(start, a);
//    addEdge(a, b);
//    addEdge(a, c);
//    addEdge(b, d);
//    addEdge(b, e);
//    addEdge(c, d);
//    addEdge(c, e);
//    addEdge(d, f);
//    addEdge(d, g);
//    addEdge(e, f);
//    addEdge(e, g);
//    addEdge(f, h);
//    addEdge(g, h);
//    addEdge(h, end);
//    setPath(a, false);
//    if (a->path) {
//        setPath(c, true);
//        if (c->path) {
//            addVariable(b, 'x', 1);
//        } else {
//            addVariable(f, 'x', 1);
//        }
//    } else {
//        setPath(d, true);
//        if (d->path) {
//            addVariable(f, 'x', 1);
//        } else {
//            addVariable(e, 'x', 1);
//        }
//    }
//    addVariable(g, 'x', 0);
//    addVariable(g, 'y', 1);
//}
//
////void test15() {
////    Node *start = addNode((void *) -1);
////    Node *a = addNode((void *) 10);
////    Node *b = addNode((void *) 20);
////    Node *c = addNode((void *) 30);
////    Node *d = addNode((void *) 40);
////    Node *end = addNode((void *) 0);
////    addEdge((void *) -1, start, a);
////    addEdge((void *) 1, a, b);
////    addEdge((void *) 2, a, c);
////    addEdge((void *) 3, b, d);
////    addEdge((void *) 4, c, d);
////    addEdge((void *) 5, d, b);
////    addEdge((void *) 0, d, end);
////}
////
////void test16() {
////    Node *start = addNode((void *) -1);
////    Node *a = addNode((void *) 10);
////    Node *b = addNode((void *) 20);
////    Node *c = addNode((void *) 30);
////    Node *d = addNode((void *) 40);
////    Node *e = addNode((void *) 50);
////    Node *f = addNode((void *) 60);
////    Node *g = addNode((void *) 70);
////    Node *end = addNode((void *) 0);
////    addEdge((void *) -1, start, a);
////    addEdge((void *) 1, a, b);
////    addEdge((void *) 2, b, c);
////    addEdge((void *) 3, b, d);
////    addEdge((void *) 4, c, g);
////    addEdge((void *) 5, d, e);
////    addEdge((void *) 6, d, f);
////    addEdge((void *) 7, e, g);
////    addEdge((void *) 8, f, g);
////    addEdge((void *) 0, g, end);
////}
////
////void test19() {
////    Node *start = addNode((void *) -1);
////    Node *a = addNode((void *) 10);
////    Node *b = addNode((void *) 20);
////    Node *c = addNode((void *) 30);
////    Node *d = addNode((void *) 40);
////    Node *e = addNode((void *) 50);
////    Node *f = addNode((void *) 60);
////    Node *g = addNode((void *) 70);
////    Node *h = addNode((void *) 80);
////    Node *end = addNode((void *) 0);
////    addEdge((void *) -1, start, a);
////    addEdge((void *) 1, a, b);
////    addEdge((void *) 2, a, c);
////    addEdge((void *) 3, b, d);
////    addEdge((void *) 4, b, e);
////    addEdge((void *) 5, c, e);
////    addEdge((void *) 6, d, h);
////    addEdge((void *) 7, e, f);
////    addEdge((void *) 8, e, g);
////    addEdge((void *) 9, f, h);
////    addEdge((void *) 10, g, h);
////    addEdge((void *) 0, h, end);
////}