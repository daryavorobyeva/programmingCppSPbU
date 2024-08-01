#ifndef V2D_H_INCLUDED
#define V2D_H_INCLUDED

#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <cctype>
#include <cmath>

template <class T, size_t N>
class vect {
private:
    T x[N];
public:
    vect() {
        for (size_t i = 0; i < N; ++i) {
            x[i] = T();
        }
    }
    vect(const T* arr) {
        for (size_t i = 0; i < N; ++i) {
            x[i] = arr[i];
        }
    }

    vect& operator += (const vect& v) {
        for (size_t i = 0; i < N; ++i) {
            x[i] += v.x[i];
        }
        return *this;
    }
    vect operator + (const vect& v) const {
        vect sum = *this;
        sum += v;
        return sum;
    }

    vect& operator -= (const vect& v) {
        for (size_t i = 0; i < N; ++i) {
            x[i] -= v.x[i];
        }
        return *this;
    }
    vect operator - (const vect& v) const {
        vect razn = *this;
        razn -= v;
        return razn;
    }

    T operator * (const vect& v) const {
        T product = T();
        for (size_t i = 0; i < N; ++i) {
            product += x[i] * v.x[i];
        }
        return product;
    }

    vect& operator *= (const T& sc) {
        for (size_t i = 0; i < N; ++i) {
            x[i] *= sc;
        }
        return *this;
    }
    vect operator * (const T& sc) const {
        vect product = *this;
        product *= sc;
        return product;
    }

    vect& operator /= (const T& sc) {
        for (size_t i = 0; i < N; ++i) {
            x[i] /= sc;
        }
        return *this;
    }
    vect operator / (const T& sc) const {
        vect result = *this;
        result /= sc;
        return result;
    }

    bool operator == (const vect& v) const {
        for (size_t i = 0; i < N; ++i) {
            if (x[i] != v.x[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator != (const vect& v) const {
        return !(*this == v);
    }

    bool operator > (const vect& v) const {
        for (size_t i = 0; i < N; ++i) {
            if (x[i] <= v.x[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator < (const vect& v) const {
        for (size_t i = 0; i < N; ++i) {
            if (x[i] >= v.x[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator >= (const vect& v) const {
        for (size_t i = 0; i < N; ++i) {
            if (x[i] < v.x[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator <= (const vect& v) const {
        for (size_t i = 0; i < N; ++i) {
            if (x[i] > v.x[i]) {
                return false;
            }
        }
        return true;
    }

    vect& operator + () const {
        return *this;
    }
    vect operator - () const {
        vect result = *this;
        for (size_t i = 0; i < N; ++i) {
            result.x[i] = -(result.x[i]);
        }
        return result;
    }

    vect& operator = (const vect& v) {
        if (&v != this) {
            for (size_t i = 0; i < N; ++i) {
                x[i] = v.x[i];
            }
        }
        return *this;
    }

    const T& operator [] (size_t i) const {
        return x[i-1];
    }

    double euclidian_norm() const {
        T sum = 0;
        for (size_t i = 0; i < N; ++i) {
            sum += x[i] * x[i];
        }
        return sqrt(sum);
    }

    template <class U, size_t M>
    friend std::ostream& operator << (std::ostream& out, const vect<U, M>& v) {
        out << "[";
        for (size_t i = 0; i < M; ++i) {
            if (i > 0)
                out << ", ";
            out << v.x[i];
        }
        out << "]";
        return out;
    }

    template <class U, size_t M>
    friend std::istream& operator >> (std::istream& in, vect<U, M>& v) {  
        std::string input;
        std::getline(in, input);

        std::stringstream ss(input);

        char symbol;
        U elem;

        if ((ss >> symbol) && (symbol == '[')) {
            for (int i = 0; i < M; ++i) {
                if (i > 0) {
                    ss >> symbol;
                }
                if (ss >> elem) {
                    v.x[i] = elem;
                }
                else {
                    break;
                }
            }
        }
        return in;
    }
};

#endif // V2D_H_INCLUDED






