#ifndef FIGURE_HEADER_H
#define FIGURE_HEADER_H

#include <iostream>
#include <cmath>

class Figure {
public:
    virtual ~Figure () {};

    virtual double s() const = 0;
    virtual double p() const = 0;

    friend std::ostream& operator << (std::ostream& output, const Figure& f);

    virtual Figure& operator = (const Figure& f) = 0;
protected:
    virtual void print(std::ostream& output) const = 0;
};

class Circle: public Figure {
public:
    Circle(double r0);

    double s() const override;
    double p() const override;

    Circle& operator = (const Figure& f);
protected:
    void print(std::ostream& output) const override;
private:
    double r;
};

class Rectangle: public Figure {
public:
    Rectangle(double a0, double b0);

    double s() const override;
    double p() const override;

    Rectangle& operator = (const Figure& f);
protected:
    void print(std::ostream& output) const override;
private:
    double a;
    double b;
};

class Ellipse: public Figure {
public:
    Ellipse(double a0, double b0);

    double s() const override;
    double p() const override;

    Ellipse& operator = (const Figure& f);
protected:
    void print(std::ostream& output) const override;
private:
    double a;
    double b;
};

#endif //FIGURE_HEADER_H
