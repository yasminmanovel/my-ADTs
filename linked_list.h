#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct bodyNode *Node;
typedef struct headNode *Head;

struct bodyNode {
    Node next;
    char *data;
};

struct headNode {
    int numElems;
    Node first;
    Node last;
};

Node newNode(char *input);
Head newHead();
void insertIntoList(Node, Head); 

#endif