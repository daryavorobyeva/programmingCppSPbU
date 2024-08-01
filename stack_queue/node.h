#ifndef STACK_NODE_H
#define STACK_NODE_H

struct Node {
    int value;
    Node* next;

    Node(int n);
};

Node::Node(int n): value(n), next(nullptr) {};

#endif //STACK_NODE_H
