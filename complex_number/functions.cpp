#include <cmath>
#include "header.h"

complex::complex (double a0, double b0): a(a0), b(b0) {}

double complex::get_real() const {
    return a;
}
double complex::get_imaginary() const {
    return b;
}

complex& complex::operator += (const complex& c) {
    a += c.a;
    b += c.b;
    return *this;
}
complex complex::operator + (const complex& c) {
    complex tt = *this;
    tt += c;
    return tt;
}
complex& complex::operator += (const double t) {
    a += t;
    return *this;
}
complex complex::operator + (const double t) {
    complex tt = *this;
    tt += t;
    return tt;
}
complex operator + (const double t, const complex& c) {
    complex tt;
    tt.a = t;
    tt += c;
    return tt;
}

complex& complex::operator -= (const complex& c) {
    a -= c.a;
    b -= c.b;
    return *this;
}
complex complex::operator - (const complex& c) {
    complex tt = *this;
    tt -= c;
    return tt;
}
complex& complex::operator -= (const double t) {
    a -= t;
    return *this;
}
complex complex::operator - (const double t) {
    complex tt = *this;
    tt -= t;
    return tt;
}
complex operator - (const double t, const complex& c) {
    complex tt;
    tt.a = t;
    tt -= c;
    return tt;
}

complex& complex::operator *= (const complex& c) {
    double aa = a;
    a = a*c.a - b*c.b;
    b = aa*c.b + b*c.a;
    return *this;
}
complex complex::operator * (const complex& c) {
    complex tt = *this;
    tt *= c;
    return tt;
}
complex& complex::operator *= (const double t) {
    a *= t;
    b *= t;
    return *this;
}
complex complex::operator * (const double t) {
    complex tt = *this;
    tt *= t;
    return tt;
}
complex operator * (const double t, const complex& c) {
    complex tt;
    tt.a = t;
    tt *= c;
    return tt;
}

complex& complex::operator /= (const double t) {
    a /= t;
    b /= t;
    return *this;
}
complex complex::operator / (const double t) {
    complex tt = *this;
    tt /= t;
    return tt;
}
complex& complex::operator /= (const complex& c) {
    double aa = a;
    a = (a*c.a + b*c.b)/(c.a*c.a + c.b*c.b);
    b = (c.a*b - aa*c.b)/(c.a*c.a+c.b*c.b);
    return *this;
}
complex complex::operator / (const complex& c) {
    complex tt = *this;
    tt /= c;
    return tt;
}
complex operator / (const double t, const complex& c) {
    complex tt;
    tt.a = t;
    tt /= c;
    return tt;
}

complex& complex::operator = (const complex& c) {
    a = c.a;
    b = c.b;
    return *this;
}

bool complex::operator == (const complex& c) const {
    return a == c.a && b == c.b;
}
bool complex::operator != (const complex& c) const {
    return !(*this == c);
}
bool complex::operator == (const double t) const {
    return a == t && b == 0;
}
bool complex::operator != (const double t) const {
    return !(*this == t);
}
bool operator == (const double t, const complex& c) {
    return c.a == t && c.b == 0;
}
bool operator != (const double t, const complex& c) {
    return !(c == t);
}

bool complex::operator > (const complex& c) const {
    if (a > c.a) {
        return true;
    }
    else if (a < c.a) {
        return false;
    }
    else if (b > c.b) {
        return true;
    }
    return false;
}
bool complex::operator < (const complex& c) const {
    if (*this == c) {
        return false;
    }
    return !(*this > c);
}
bool complex::operator > (const double t) const {
    if (a > t) {
        return true;
    }
    else if (a < t) {
        return false;
    }
    else if (b > 0) {
        return true;
    }
    return false;
}
bool complex::operator < (const double t) const {
    if (*this == t) {
        return false;
    }
    return !(*this > t);
}
bool operator > (const double t, const complex& c) {
    if (t > c.a) {
        return true;
    }
    else if (t < c.a) {
        return false;
    }
    else if (c.b < 0) {
        return true;
    }
    return false;
}
bool operator < (const double t, const complex& c) {
    if (t == c) {
        return false;
    }
    return (c > t);
}
bool complex::operator >= (const complex& c) const {
    return ((*this > c) || (*this == c));
}
bool complex::operator <= (const complex& c) const {
    if (!(*this >= c) || (*this == c)) {
        return true;
    }
    return false;
}
bool complex::operator >= (const double t) const {
    return (((*this) > t) || ((*this) == t));
}
bool complex::operator <= (const double t) const {
    if (!(*this >= t) || (*this == t)) {
        return true;
    }
    return false;
}
bool operator >= (const double t, const complex& c) {
    return ((t > c) || (t == c));
}
bool operator <= (const double t, const complex& c) {
    if (!(t >= c) || (t == c)) {
        return true;
    }
    return false;
}

complex& complex::operator - () {
    a = -a;
    b = -b;
    return *this;
}
complex& complex::operator + () {
    return *this;
}

std::ostream& operator << (std::ostream& out, const complex& c) {
    if (c.b == 1) {
        out << c.a << " + " << "i";
    }
    else if (c.b == -1) {
        out << c.a << " - " << "i";
    }
    else if (c.b < 0) {
        out << c.a << " - " << -c.b << "i";
    }
    else if (c.b > 0) {
        out << c.a << " + " << c.b << "i";
    }
    else {
        out << c.a;
    }
    return out;
}
std::istream& operator >> (std::istream& in, complex& c) {
    double a0;
    double b0;
    char sign;
    char i;

    in >> a0 >> sign >> b0 >> i;
    if (in) {
        c.a = a0;
        if (sign == '+') {
            c.b = b0;
        }
        else if (sign == '-') {
            c.b = -b0;
        }
    }
    return in;
}

double complex::complex_abs() const {
    double z;
    z = sqrt(a*a + b*b);
    return z;
}

complex complex::conjugate() const {
    complex c;
    c.a = a;
    c.b = -b;
    return c;
}
