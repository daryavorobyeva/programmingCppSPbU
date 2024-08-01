#ifndef STACK_QUEUE_H
#define STACK_QUEUE_H

#include <iostream>
#include "node.h"

class Queue {
public:
    Queue();
    Queue(const Queue& first);
    Queue(Queue&& copy);

    void copyNodes(const Queue& first);
    void clearNodes();

    ~Queue();

    Queue& operator = (const Queue& first);
    Queue& operator = (Queue&& queue);

    void push(const int value);
    int pop();
    bool is_empty() const;
    int get_front() const;
    int get_tail() const;
    void print() const;
    void add();
    void clear();
    size_t size() const;
private:
    Node* head;
    Node* tail;
};

Queue::Queue(): head(nullptr), tail(nullptr) {};

Queue::Queue(const Queue& first): head(nullptr), tail(nullptr) {
    copyNodes(first);
};

Queue::Queue(Queue&& copy): head(copy.head), tail(copy.tail) {
    copy.head = nullptr;
    copy.tail = nullptr;
}

void Queue::copyNodes(const Queue& first) {
    Node* current = first.head;
    while (current != nullptr) {
        push(current->value);
        current = current->next;
    }
}

void Queue::clearNodes() {
    while (head != nullptr) {
        Node* current = head;
        head = head->next;
        delete current;
    }
    tail = nullptr;
}

Queue::~Queue() {
    clearNodes();
};

Queue& Queue::operator = (const Queue& first) {
    if (this != (&first)) {
        clear();
        copyNodes(first);
    }
    return *this;
}

Queue& Queue::operator = (Queue&& queue) {
    if (&queue != this) {
        clear();
        head = queue.head;
        queue.head = nullptr;
        tail = queue.tail;
        queue.tail = nullptr;
    }
    return *this;
}

void Queue::push(const int value) {
    Node* node = new Node(value);
    if (head == nullptr) {
        head = node;
        tail = node;
    }
    else {
        tail->next = node;
        node->next = nullptr;
        tail = node;
    }
}

int Queue::pop() {
    int n = head->value;
    Node* current = head;
    head = head->next;
    delete current;
    return n;
}

bool Queue::is_empty() const {
    if (head == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

int Queue::get_front() const {
    return head->value;
}

int Queue::get_tail() const {
    return tail->value;
}

void Queue::print() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
}

void Queue::add() {
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

void Queue::clear() {
    clearNodes();
}

size_t Queue::size() const {
    Node* current = head;
    size_t count = 0;
    while (current != nullptr) {
        ++count;
        current = current->next;
    }
    return count;
}

#endif //STACK_QUEUE_H