#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <iostream>
#include "node.h"

class Stack {
public:
    Stack();
    Stack(const Stack& first);
    Stack(Stack&& copy);

    void copyNodes(const Stack& first);
    void clearNodes();

    ~Stack();

    Stack& operator = (const Stack& first);
    Stack& operator = (Stack&& stack);

    void push(const int value);
    int pop();
    bool is_empty() const;
    int get_front() const;
    void print() const;
    void add();
    void clear();
    size_t size() const;
private:
    Node* head;
};

Stack::Stack(): head(nullptr) {};

Stack::Stack(const Stack& first): head(nullptr) {
    copyNodes(first);
};

Stack::Stack(Stack&& copy): head(copy.head) {
    copy.head = nullptr;
}

void Stack::copyNodes(const Stack& first) {
    Node* current = first.head;
    push(current->value);
    current = current->next;
    Node* old_head = head;
    Node* new_head = head;
    while (current != nullptr) {
        push(current->value);
        old_head->next = head;
        head->next = nullptr;
        head = new_head;
        old_head = old_head->next;
        current = current->next;
    }
}

void Stack::clearNodes() {
    while (head != nullptr) {
        Node* current = head;
        head = head->next;
        delete current;
    }
}

Stack::~Stack() {
    clearNodes();
};

Stack& Stack::operator = (const Stack& first) {
    if (this != (&first)) {
        clear();
        copyNodes(first);
    }
    return *this;
}

Stack& Stack::operator = (Stack&& stack) {
    if (&stack != this) {
        clear();
        head = stack.head;
        stack.head = nullptr;
    }
    return *this;
}

void Stack::push(const int value) {
    Node* node = new Node(value);
    node->next = head;
    head = node;
}

int Stack::pop() {
    int n = head->value;
    Node* current = head;
    head = head->next;
    delete current;
    return n;
}

bool Stack::is_empty() const {
    if (head == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

int Stack::get_front() const {
    return head->value;
}

void Stack::print() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
}

void Stack::add() {
    std::cout << "Enter the number of elements you want to add: \n";
    size_t n;
    std::cin >> n;
    std::cout << "Enter the value of " << n << " elements: \n";
    for (size_t i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        push(value);
    }
}

void Stack::clear() {
    clearNodes();
}

size_t Stack::size() const {
    Node* current = head;
    size_t count = 0;
    while (current != nullptr) {
        ++count;
        current = current->next;
    }
    return count;
}

#endif //STACK_STACK_H
