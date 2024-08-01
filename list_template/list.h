#ifndef LIST_TEMPLATE_LIST_H
#define LIST_TEMPLATE_LIST_H

#include <iostream>
#include "stack.h"

template<typename T>
class List {
public:
    List() = default;
    virtual ~List() = default;

    virtual void push(const T& n) = 0;
    virtual T pop() = 0;
    virtual T get_front() const = 0;
    virtual bool is_empty() const = 0;
    virtual size_t size() const = 0;

    class const_iterator;
    class iterator;

    virtual iterator begin() = 0;
    virtual iterator end() = 0;
    virtual const_iterator begin() const = 0;
    virtual const_iterator end() const = 0;
    virtual const_iterator cbegin() const = 0;
    virtual const_iterator cend() const = 0;

protected:
    struct Node {
        T value;
        Node* next;

        Node(const T& n);
    };
};

template<typename T>
class List<T>::iterator {
public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = value_type*;
    using reference = value_type&;

    iterator(Node* p0 = nullptr): p(p0) {};

    reference operator * () const {return p->value;}
    pointer operator -> () const {return &(p->value);}

    iterator& operator ++ () {  // префикс
        p = p->next;
        return *this;
    }
    iterator operator ++ (int) {  // постфикс
        iterator i = *this;
        ++p;
        return i;
    }
    bool operator == (const iterator& i) const { return p == i.p; }
    bool operator != (const iterator& i) const { return p != i.p; }

    bool operator == (const const_iterator& i) const { return p == i.p; };
    bool operator != (const const_iterator& i) const { return p != i.p; };

    friend class const_iterator;
private:
    Node* p;
};

template<typename T>
class List<T>::const_iterator {
public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = const T;
    using pointer = const value_type*;
    using reference = const value_type&;

    const_iterator(Node* p0 = nullptr): p(p0) {};
    const_iterator(const iterator& i): p(i.p) {};

    const T& operator * () const {return p->value;}
    pointer operator -> () const {return &(p->value);}

    const_iterator& operator ++ () {  // префикс
        p = p->next;
        return *this;
    }
    const_iterator operator ++ (int) {  // постфикс
        const_iterator i = *this;
        ++p;
        return i;
    }
    bool operator == (const const_iterator& i) const { return p == i.p; }
    bool operator != (const const_iterator& i) const { return p != i.p; }

    bool operator == (const iterator& i) const { return p == i.p; }
    bool operator != (const iterator& i) const { return p != i.p; }

    friend class iterator;
private:
    Node* p;
};

template<typename T>
std::ostream& operator << (std::ostream& output, const List<T>& list) {
    for (const auto& i: list) {
        output << i << "->";
    }
    output << "nullptr";
    return output;
}

template<typename T>
std::istream& operator >> (std::istream& input, List<T>& list) {
    std::string value;
    T element;
    std::cout << "Enter List elements: ";
    std::getline(input, value);
    std::stringstream ss(value);
    while (ss >> element) {
        list.push(element);
    }
    return input;
}

template<typename T>
List<T>::Node::Node(const T& n) : value(n), next(nullptr) {};

#endif //LIST_TEMPLATE_LIST_H
