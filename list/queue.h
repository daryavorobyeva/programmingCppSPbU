#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H

#include <iostream>
#include "list.h"

class Queue: public List {
public:
    Queue();
    Queue(const Queue& first);
    Queue(Queue&& copy);
    ~Queue();

    Queue& operator = (Queue&& queue);
    Queue& operator = (const Queue& first);

    void push(const int value) override;
    int get_tail() const;
private:
    Node* tail;
};



Queue::Queue(): tail(nullptr) {};

Queue::Queue(const Queue& first): tail(nullptr) {
    Node* current = first.head;
    while (current != nullptr) {
        push(current->value);
        current = current->next;
    }
};

Queue::~Queue() = default;

Queue::Queue(Queue&& copy) {
    head = copy.head;
    copy.head = nullptr;
}

Queue& Queue::operator = (Queue&& queue) {
    if (&queue != this) {
        while (head != nullptr) {
            Node *current = head;
            head = head->next;
            delete current;
        }
        head = queue.head;
        queue.head = nullptr;
    }
    return *this;
}

Queue& Queue::operator = (const Queue& first) {
    if (this != (&first)) {
        Node *current = first.head;
        while (current != nullptr) {
            push(current->value);
            current = current->next;
        }
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

int Queue::get_tail() const {
    return tail->value;
}

#endif //LIST_QUEUE_H
