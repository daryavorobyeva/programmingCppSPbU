#include <cassert>
#include <cmath>
#include <sstream>
#include "header.h"
#include "test.h"

complex c1(8, 2);
complex c2(4, 1);
complex c3(-5, 5);
complex c4(-3, -2);

void assert_get_real() {
    assert((c1.get_real()) == 8);
    assert((c3.get_real()) == -5);
}

void assert_get_imaginary() {
    assert((c2.get_imaginary()) == 1);
    assert(c4.get_imaginary() == -2);
}

complex s1(8, 2);
complex s2(4, 1);

void assert_test_equel() {
    s1 = s2;
    assert ((s1.get_real() == s2.get_real()) && (s1.get_imaginary() == s2.get_imaginary()));
}

double n = 5;
complex c5(c1.get_real() + c2.get_real(), c1.get_imaginary() + c2.get_imaginary());
complex c6(c3.get_real() + c4.get_real(), c3.get_imaginary() + c4.get_imaginary());
complex c7(c1.get_real() + n, c1.get_imaginary());
complex c8(c3.get_real() + n, c3.get_imaginary());

complex p5(c1.get_real() * c2.get_real() - c1.get_imaginary() * c2.get_imaginary(),
                  c1.get_real() * c2.get_imaginary() + c1.get_imaginary() * c2.get_real());
complex p6(c3.get_real() * c4.get_real() - c3.get_imaginary() * c4.get_imaginary(),
                  c3.get_real() * c4.get_imaginary() + c3.get_imaginary() * c4.get_real());
complex p7(c1.get_real() * n, c1.get_imaginary() * n);
complex p8(c3.get_real() * n, c3.get_imaginary() * n);

complex m5(c1.get_real() - c2.get_real(), c1.get_imaginary() - c2.get_imaginary());
complex m6(c1.get_real() - n, c1.get_imaginary());
complex m7(n - c1.get_real(), -(c1.get_imaginary()));
complex m8(c3.get_real() - n, c3.get_imaginary());

complex d5((c1.get_real()*c2.get_real() + c1.get_imaginary()*c2.get_imaginary())/
                  (c2.get_real()*c2.get_real() + c2.get_imaginary()*c2.get_imaginary()),
                  ((c2.get_real()*c1.get_imaginary() - c1.get_real()*c2.get_imaginary())/
                  (c2.get_real()*c2.get_real() + c2.get_imaginary()*c2.get_imaginary())));
complex d6((c1.get_real()*c2.get_real() + c1.get_imaginary()*c2.get_imaginary())/
           (c1.get_real()*c1.get_real() + c1.get_imaginary()*c1.get_imaginary()),
           ((c1.get_real()*c2.get_imaginary() - c2.get_real()*c1.get_imaginary())/
            (c1.get_real()*c1.get_real() + c1.get_imaginary()*c1.get_imaginary())));
complex d7(c1.get_real()/n, c1.get_imaginary()/n);
complex d8(n*c2.get_real()/
           (c2.get_real()*c2.get_real() + c2.get_imaginary()*c2.get_imaginary()),
           ((- n*c2.get_imaginary())/
            (c2.get_real()*c2.get_real() + c2.get_imaginary()*c2.get_imaginary())));


void assert_test_operators() {
    assert((c1 + c2) == c5);
    assert((c3 + c4) == c6);
    assert((c1 + n) == c7);
    assert((n + c1) == c7);
    assert((c3 + n) == c8);
    assert((n + c3) == c8);

    assert((c1 * c2) == p5);
    assert((c3 * c4) == p6);
    assert((c1 * n) == p7);
    assert((n * c1) == p7);
    assert((c3 * n) == p8);
    assert((n * c3) == p8);

    assert((c1 - c2) == m5);
    assert((c2 - c1) == -m5);
    assert((c1 - n) == m6);
    assert((n - c1) == m7);
    assert((c3 - n) == m8);

    assert((c1 / c2) == d5);
    assert((c2 / c1) == d6);
    assert((c1 / n) == d7);
    assert((n / c2) == d8);
}

complex c9(c5.get_real() + n, c5.get_imaginary());
complex c10(c6.get_real() + n, c6.get_imaginary());

complex p9 = c9 * c2;
complex p10 = c10 * c4;

complex pd9 = p9 * n;
complex pd10 = p10 * n;

complex m9 = pd9 - c2;
complex m10 = pd10 - c4;

complex md9 = m9 - n;
complex md10 = m10 - n;

complex d9 = md9 / c2;
complex d10 = md10 / c4;

complex dd9 = d9 / n;
complex dd10 = d10 / n;


void assert_test_assignment() {
    assert((c1 += c2) == c5);
    assert((c3 += c4) == c6);
    assert((c1 += n) == c9);
    assert((c3 += n) == c10);

    assert((c1 *= c2) == p9);
    assert((c3 *= c4) == p10);
    assert((c1 *= n) == pd9);
    assert((c3 *= n) == pd10);

    assert((c1 -= c2) == m9);
    assert((c3 -= c4) == m10);
    assert((c1 -= n) == md9);
    assert((c3 -= n) == md10);

    assert((c1 /= c2) == d9);
    assert((c3 /= c4) == d10);
    assert((c1 /= n) == dd9);
    assert((c3 /= n) == dd10);
}

complex b1(5, 7);
complex b_1(5, 7);
complex b_1_(-5, -7);
complex b2(3, -3);
complex b_2(3, -3);
complex b_2_(-3, 3);
complex b3(-3, 5);
complex b_3(-3, 5);
complex b_3_(3, -5);
complex b4(-7, -11);
complex b_4(-7, -11);
complex b_4_(7, 11);

complex bt(3, 0);
double t = 3;

complex bb1(5, -7);
complex bb2(3, 3);
complex bb3(-3, -5);
complex bb4(-7, 11);

void assert_test_abs() {
    assert (b1.complex_abs() == sqrt(74));
    assert (b2.complex_abs() == sqrt(18));
    assert (b3.complex_abs() == sqrt(34));
    assert (b4.complex_abs() == sqrt(170));
}

void assert_test_bool() {
    assert ((b1 == b_1) == 1);
    assert ((b2 == b_2) == 1);
    assert ((b3 == b_3) == 1);
    assert ((b4 == b_4) == 1);
    assert ((bt == t) == 1);
    assert ((t == bt) == 1);

    assert ((b1 != b_1_) == 1);
    assert ((b2 != b_2_) == 1);
    assert ((b3 != b_3_) == 1);
    assert ((b4 != b_4_) == 1);
    assert ((b1 != t) == 1);
    assert ((t != b1) == 1);

    assert((b2 < b1) == 1);
    assert((b3 < b2) == 1);
    assert((b4 < b3) == 1);
    assert ((b_1 < t) == 0);
    assert ((t < b_1) == 1);

    assert((b2 <= b1) == 1);
    assert((b3 <= b2) == 1);
    assert((b4 <= b3) == 1);
    assert ((bt <= t) == 1);
    assert ((t <= bt) == 1);
    assert ((b_1 <= t) == 0);
    assert ((t <= b_1) == 1);

    assert((b2 > b1) == 0);
    assert((b3 > b2) == 0);
    assert((b4 > b3) == 0);
    assert ((b_1 > t) == 1);
    assert ((t > b_1) == 0);

    assert((b2 >= b1) == 0);
    assert((b3 >= b2) == 0);
    assert((b4 >= b3) == 0);
    assert ((b_1 >= t) == 1);
    assert ((t >= b_1) == 0);
    assert ((bt >= t) == 1);
    assert ((t >= bt) == 1);
}

void assert_test_conjugate() {
    assert (b1.conjugate() == bb1);
    assert (b2.conjugate() == bb2);
    assert (b3.conjugate() == bb3);
    assert (b4.conjugate() == bb4);
}

void assert_test_unary() {
    assert ((-b1 == b_1_) == 1);
    assert ((-b2 == b_2_) == 1);
    assert ((-b3 == b_3_) == 1);
    assert ((-b4 == b_4_) == 1);

    assert ((+b1 == b1) == 1);
    assert ((+b2 == b2) == 1);
    assert ((+b3 == b3) == 1);
    assert ((+b4 == b4) == 1);
}

void assert_test_input() {
    complex k;
    std::istringstream in ("3 + 4i");
    in >> k;
    assert (k.get_real() == 3);
    assert (k.get_imaginary() == 4);
}

void assert_test_output() {
    complex g(3, 4);
    std::ostringstream out;
    out << g;
    assert (out.str() == "3 + 4i");
}


