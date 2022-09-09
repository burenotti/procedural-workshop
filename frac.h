
#ifndef FRAC
#define FRAC

#include <iostream>
#include <numeric>
#include <cmath>


struct Frac {


    Frac() : Frac(0, 1) {
    }

    Frac(int64_t num, int64_t denom) {
        _num = abs(num);
        _denom = abs(denom);
        _sign = (num * denom >= 0) ? 1 : -1;
    }

    static Frac from_int(int64_t int_value) {
        return {int_value, 1};
    }

    static Frac from_double(double float_value) {
        double precision = pow(10, 15);
        auto integral_part = std::floor(float_value);
        auto decimal_part = (int64_t) ((float_value - integral_part) * precision);
        return Frac::from_int((int64_t) (integral_part)) + Frac(decimal_part, (int64_t) precision);
    }

    static const Frac zero() {
        return {0, 1};
    }

    static const Frac pi() {
        return {245850922, 78256779};
    }

    Frac operator+(Frac other) const {
        auto left = this->reduce();
        auto right = other.reduce();

        auto denom = std::lcm(left._denom, right._denom);
        auto _gcd = std::gcd(left._denom, right._denom);
        auto left_mul = right._denom / _gcd;
        auto right_mul = left._denom / _gcd;
        auto num = left.numerator() * left_mul + right.numerator() * right_mul;
        return {num, denom};
    }

    Frac operator-() const {
        return {-numerator(), denominator()};
    }

    Frac operator-(Frac other) const {
        return (*this) + (-other);
    }

    Frac operator*(Frac other) const {
        auto left = this->reduce();
        auto right = other.reduce();
        auto gcd1 = std::gcd(left.numerator(), right.denominator());
        auto gcd2 = std::gcd(left.denominator(), right.numerator());
        auto num = left.numerator() / gcd1 * right.numerator() / gcd2;
        auto denom = left._denom / gcd2 * right._denom / gcd1;
        return Frac(num, denom).reduce();
    }

    Frac operator/(Frac other) const {
        return (*this) * other.inverse();
    }

    [[nodiscard]] Frac reduce() const {
        auto _gcd = std::gcd(_num, _denom);
        return {numerator() / _gcd, _denom / _gcd};
    }

    [[nodiscard]] int64_t numerator() const {
        return _sign * _num;
    }

    [[nodiscard]] int64_t denominator() const {
        return _denom;
    }

    [[nodiscard]] Frac inverse() const {
        return {denominator(), numerator()};
    }

    explicit operator double() const {
        return (double) numerator() / (double) denominator();
    }

private:
    int8_t _sign;
    int64_t _num;
    int64_t _denom;
};


Frac pow(Frac frac, int64_t p) {
    frac = frac.reduce();
    Frac res(1, 1);
    for (int i = 1; i <= p; ++i) {
        res = (res * frac).reduce();
    }
    return res;
}

int64_t factorial(int64_t n) {
    int64_t res = 1;
    for (int i = 2; i <= n; ++i) {
        res *= i;
    }
    return res;
}

Frac sin(Frac frac) {
    frac = (frac / Frac::pi()).reduce();
    Frac res;
    for (int i = 0; i < 9; ++i) {
        int64_t d = 2 * i + 1;
        auto item = pow(frac, d) / Frac::from_int(factorial(d));
        if (i % 2 == 0) {
            res = (res + item).reduce();
        } else {
            res = (res - item).reduce();
        }
    }

    return res;
}

std::ostream& operator<<(std::ostream& out, Frac frac) {
    return out << frac.numerator() << '/' << frac.denominator();
}

#endif