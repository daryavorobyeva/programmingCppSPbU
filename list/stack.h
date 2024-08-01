#ifndef LIST_STACK_H
#define LIST_STACK_H

#include <iostream>
#include "list.h"

class Stack: public List {
public:
    Stack();
    Stack(const Stack& first);
    Stack(Stack&& copy);
    ~Stack();

    Stack& operator = (const Stack& first);
    Stack& operator = (Stack&& stack);
};



Stack::Stack() {};
Stack::Stack(const Stack& first): List(first) {};
Stack::~Stack() = default;

Stack::Stack(Stack&& copy) {
    head = copy.head;
    copy.head = nullptr;
}

Stack& Stack::operator = (Stack&& stack) {
    if (&stack != this) {
        while (head != nullptr) {
            Node *current = head;
            head = head->next;
            delete current;
        }
        head = stack.head;
        stack.head = nullptr;
    }
    return *this;
}

Stack& Stack::operator = (const Stack& first) {
    List::operator = (first);
    return *this;
}


#endif //LIST_STACK_H
