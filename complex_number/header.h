#ifndef COMPLEX_NUMBER_HEADER_H
#define COMPLEX_NUMBER_HEADER_H

#include <istream>
#include <ostream>
#include <cassert>
#include "test.h"

class complex {
private:
    double a, b;
public:
    complex (double a = 0, double b = 0);

    double get_real() const;
    double get_imaginary() const;

    complex& operator += (const complex& c);
    complex& operator += (const double t);

    complex& operator -= (const complex& c);
    complex& operator -= (const double t);

    complex operator + (const complex& c);
    complex operator + (const double t);
    friend complex operator + (const double t, const complex& c);

    complex operator - (const complex& c);
    complex operator - (const double t);
    friend complex operator - (const double t, const complex& c);

    complex& operator *= (const complex& c);
    complex& operator *= (const double t);

    complex& operator /= (const double t);
    complex& operator /= (const complex& c);

    complex operator * (const complex& c);
    complex operator * (const double t);
    friend complex operator * (const double t, const complex& c);

    complex operator / (const complex& c);
    complex operator / (const double t);
    friend complex operator / (const double t, const complex& c);

    complex& operator = (const complex& c);

    bool operator == (const complex& c) const;
    bool operator != (const complex& c) const;

    bool operator == (const double t) const;
    bool operator != (const double t) const;

    friend bool operator == (const double t, const complex& c);
    friend bool operator != (const double t, const complex& c);

    bool operator > (const complex& c) const;
    bool operator < (const complex& c) const;

    bool operator > (const double t) const;
    bool operator < (const double t) const;

    friend bool operator > (const double t, const complex& c);
    friend bool operator < (const double t, const complex& c);

    bool operator >= (const complex& c) const;
    bool operator <= (const complex& c) const;

    bool operator >= (const double t) const;
    bool operator <= (const double t) const;

    friend bool operator >= (const double t, const complex& c);
    friend bool operator <= (const double t, const complex& c);

    complex& operator - ();
    complex& operator + ();

    friend std::ostream& operator << (std::ostream& out, const complex& c);
    friend std::istream& operator >> (std::istream& in, complex& c);

    double complex_abs() const;

    complex conjugate() const;
};

#endif //COMPLEX_NUMBER_HEADER_H
