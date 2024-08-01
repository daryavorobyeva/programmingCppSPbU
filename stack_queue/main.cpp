#include <iostream>
#include "stack.h"
#include "queue.h"

int main() {
    std::cout << "Stack: \n";
    Stack stack1;
    std::cout << "We're going to fill the stack1. \n";
    stack1.add();

    std::cout << "Stack2 takes the values of stack1... \n";
    Stack stack2 = stack1;

    std::cout << "Elements of stack2: ";
    stack2.print();
    std::cout << "\n";

    std::cout << "\nQueue: \n";
    Queue queue1;
    std::cout << "We're going to fill the queue1. \n";
    queue1.add();

    std::cout << "Queue2 takes the values of queue1... \n";
    Queue queue2 = queue1;

    std::cout << "Elements of queue2: ";
    queue2.print();
    std::cout << "\n";

    return 0;
}
