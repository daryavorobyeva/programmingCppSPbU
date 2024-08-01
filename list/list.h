#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <iostream>

class List {
public:
    List();
    List(const List& first);
    ~List();

    List& operator = (const List& first);

    virtual void push(const int n);
    int pop();
    int get_front() const;
    bool is_empty() const;
    size_t size() const;

    friend std::ostream& operator << (std::ostream& output, const List& list);
    friend std::istream& operator >> (std::istream& input, List& list);
protected:
    struct Node {
        int value;
        Node *next;

        Node(int n);
    };
    Node* head;

    void print(std::ostream& output) const;
};



List::List(): head(nullptr) {};

List::List(const List& first) {
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

List::~List() {
    while (head != nullptr) {
        Node *current = head;
        head = head->next;
        delete current;
    }
}

List& List::operator = (const List& first) {
    if (this != (&first)) {
        while (head != nullptr) {
            Node *current = head;
            head = head->next;
            delete current;
        }

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
    return *this;
}

void List::push(const int n) {
    Node* node = new Node(n);
    if (head == nullptr) {
        head = node;
        head->next = nullptr;
    }
    else {
        node->next = head;
        head = node;
    }
}

int List::pop() {
    int n = head->value;
    Node* current = head;
    head = head->next;
    delete current;
    return n;
}

int List::get_front() const {
    return head->value;
}

bool List::is_empty() const {
    return head == nullptr;
}

size_t List::size() const {
    size_t n = 0;
    Node* current = head;
    while (current != nullptr) {
        ++n;
        current = current->next;
    }
    return n;
}

std::ostream& operator << (std::ostream& output, const List& list) {
    list.print(output);
    return output;
}

std::istream& operator >> (std::istream& input, List& list) {
    std::string value;
    std::cout << "Enter List elements: ";
    std::getline(input, value);
    for (const auto &elem: value) {
        if (elem == ' ') {
            continue;
        }
        int n = std::stoi(std::string(1, elem));
        list.push(n);
    }
    return input;
}

void List::print(std::ostream& output) const {
    Node* current = head;
    while (current != nullptr) {
        output << current->value << "->";
        current = current->next;
    }
    output << "nullptr";
}

List::Node::Node(int n) : value(n), next(nullptr) {};

#endif //LIST_LIST_H
