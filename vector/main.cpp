#include <iostream>
#include "header.h"

int main()
{
    vect <double, 4> v1;
    vect <double, 4> v2;

    std::cout << "enter the first four-dimensional vector in the format [x, x, x, x]: ";
    std::cin >> v1;
    std::cout << "enter the second four-dimensional vector in the format [x, x, x, x]: ";
    std::cin >> v2;

    std::cout << "first vector: " << v1 << "\n" << "second vector: " << v2 << "\n";
    std::cout << "getting the second coordinate of the first vector v1[2] = " << v1[2] << "\n";

    std::cout << "addition of two vectors: v1 + v2 = " << (v1 + v2) << "\n";
    std::cout << "subtracting the second vector from the first: v1 - v2 = " << (v1 - v2) << "\n";
    std::cout << "scalar multiplication of two vectors: v1 * v2 = " << (v1 * v2) << "\n";
    std::cout << "multiplication of vector and scalar: v1 * 5 = " << (v1 * 5) << "\n";
    std::cout << "dividing a vector by a scalar: v1 / 5 = " << (v1 / 5) << "\n";
    std::cout << "euclidian norm (first vector): " << v1.euclidian_norm() << "\n";

    if (v1 > v2) {
        std::cout << "comparison of two vectors: v1 > v2 ? " << "yes" << "\n";
    }
    else {
        std::cout << "comparison of two vectors: v1 > v2 ? " << "no" << "\n";
    }

    return 0;
}
