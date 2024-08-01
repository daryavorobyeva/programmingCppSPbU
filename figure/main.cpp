#include <iostream>
#include "header.h"

int main() {
    Circle c1(2);
    Figure& f = c1;

    Circle c2(6);
    f = c2;
    std::cout << f;


    Rectangle r(3, 8);
    std::cout << r;

    Ellipse e(2, 4);
    std::cout << e;

    return 0;
}
