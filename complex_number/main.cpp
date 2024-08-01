#include <iostream>
#include <cmath>
#include "header.h"
#include "test.h"

int main() {

    assert_get_real();
    assert_get_imaginary();
    assert_test_equel();
    assert_test_operators();
    assert_test_assignment();
    assert_test_bool();
    assert_test_abs();
    assert_test_conjugate();
    assert_test_unary();
    assert_test_input();
    assert_test_output();

    complex c1;
    std::cin >> c1;

    complex c2(5, -7);

    std::cout << "c1 = " << c1 << "\n";
    std::cout << "c2 = " << c2 << "\n";

    std::cout << "addition of complex numbers: (" << c1 << ") + (" << c2 << ") = " << c1 + c2 << "\n";

    std::cout << "multiplication of two complex numbers: (" << c1 << ") * (" << c2 << ") = " << c1 / c2 << "\n";

    if (c1 > c2) {
        std::cout << "comparison of two complex numbers: (" << c1 << ") > (" << c2 << ") - yes " << "\n";
    }
    else {
        std::cout << "comparison of two complex numbers: (" << c1 << ") > (" << c2 << ") - no " << "\n";
    }

    c1 *= c2;
    std::cout << "assignment (complex + complex) : (" << c1 << ") *= (" << c2 << ") = " << c1 << "\n";

    std::cout << "module: " << "abs(" << c1 << ") = " << c1.complex_abs() << "\n";

    std::cout << "conjugate complex number: " << "conjugate(" << c2 << ") = " << c2.conjugate() << "\n";

    std::cout << "dividing a complex number by a number: (" << c2 << ")/5 = " << c2/5 << "\n";

    return 0;
}

