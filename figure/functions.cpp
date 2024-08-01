#include "header.h"

std::ostream& operator << (std::ostream& output, const Figure& f) {
    f.print(output);
    return output;
}
inline Figure& Figure::operator = (const Figure& f) = default;

Circle::Circle(double r0): r(r0) {};

double Circle::s() const {
    return M_PI * r * r;
}
double Circle::p() const {
    return 2 * M_PI * r;
}
void Circle::print(std::ostream& output) const {
    output << "Circle: r = " << r << ", s = " << s() << ", p = " << p() << "\n";
}
Circle& Circle::operator = (const Figure& f) {
    if (this == &f) return *this;
    const Circle& c = dynamic_cast <const Circle&> (f);
    *this = c;
    return *this;
}

Rectangle::Rectangle(double a0, double b0): a(a0), b(b0) {};

double Rectangle::s() const {
    return a * b;
}
double Rectangle::p() const {
    return 2 * (a + b);
}
void Rectangle::print(std::ostream& output) const {
    output << "Rectangle: a = " << a << ", b = " << b << ", s = " << s() << ", p = " << p() << "\n";
}
Rectangle& Rectangle::operator = (const Figure& f) {
    if (this == &f) return *this;
    const Rectangle& r = dynamic_cast <const Rectangle&> (f);
    *this = r;
    return *this;
}

Ellipse::Ellipse(double a0, double b0): a(a0), b(b0) {};

double Ellipse::s() const {
    return M_PI * a * b;
}
double Ellipse::p() const {
    return 4 * ((M_PI * a * b + (a - b)) / (a + b));
}
void Ellipse::print(std::ostream& output) const {
    output << "Ellipse: a = " << a << ", b = " << b << ", s = " << s() << ", p = " << p() << "\n";
}
Ellipse& Ellipse::operator = (const Figure& f) {
    if (this == &f) return *this;
    const Ellipse& e = dynamic_cast <const Ellipse&> (f);
    *this = e;
    return *this;
}