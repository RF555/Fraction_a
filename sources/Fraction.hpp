#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <string>

using namespace std;
namespace ariel {
    class Fraction {
        int _numerator, _denominator;

    public:
        Fraction();

        Fraction(int x, int y);

        Fraction(const Fraction &q);

        Fraction(const int &n);

        Fraction(const double &d);

        Fraction(const float &f);

        ~Fraction();

        int numerator();

        int denominator();

        Fraction &operator=(const Fraction &q);

        // Arithmetic operations:
        Fraction &operator+=(const Fraction &q);

        Fraction &operator-=(const Fraction &q);

        Fraction &operator*=(const Fraction &q);

        Fraction &operator++();

        Fraction operator++(int);

        Fraction &operator--();

        Fraction operator--(int);

        Fraction operator-() const;


        friend Fraction operator+(const Fraction &a, const Fraction &b);

        friend Fraction operator-(const Fraction &a, const Fraction &b);

        friend Fraction operator*(const Fraction &a, const Fraction &b);

        friend Fraction operator/(const Fraction &a, const Fraction &b);

        // Boolean operations:
        bool operator!() const;

        friend bool operator!=(const Fraction &a, const Fraction &b);

        friend bool operator==(const Fraction &a, const Fraction &b);

        friend bool operator>=(const Fraction &a, const Fraction &b);

        friend bool operator<=(const Fraction &a, const Fraction &b);

        friend bool operator<(const Fraction &a, const Fraction &b);

        friend bool operator>(const Fraction &a, const Fraction &b);

        // Conversions:

        explicit operator double() const;

        explicit operator float() const;

        // I/O operations:
        friend std::ostream &operator<<(ostream &output, const Fraction &q);

        friend std::istream &operator>>(istream &input, Fraction &q);

    private:
        void reducedForm();

        static istream &checkNextChar(istream &input, char expectedChar);



    };
}
#endif