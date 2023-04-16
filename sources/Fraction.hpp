#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>
#include <string>

using namespace std;
namespace ariel
{
    class Fraction
    {
        int _numerator, _denominator;

    public:
        Fraction();

        Fraction(const int x, const int y);

        Fraction(const Fraction &q);

        Fraction(const float d);

        ~Fraction();

        Fraction &operator+=(const Fraction &q) const;
        Fraction &operator-=(const Fraction &q) const;
        Fraction &operator*=(const Fraction &q) const;
        Fraction &operator++();
        Fraction &operator--();
        Fraction operator-();
        Fraction &operator++(int);
        Fraction &operator--(int);

        friend Fraction operator+(Fraction a, Fraction b);
        friend Fraction operator-(Fraction a, Fraction b);
        friend Fraction operator*(Fraction a, Fraction b);
        friend Fraction operator/(Fraction a, Fraction b);

        // Boolean operations:
        bool operator!() const;
        friend bool operator!=(Fraction a, Fraction b);
        friend bool operator==(Fraction a, Fraction b);
        friend bool operator>=(Fraction a, Fraction b);
        friend bool operator<=(Fraction a, Fraction b);
        friend bool operator<(Fraction a, Fraction b);
        friend bool operator>(Fraction a, Fraction b);

        // I/O operations:
        friend std::ostream &operator<<(ostream &output, const Fraction &q);
        friend std::istream &operator>>(istream &input, const Fraction &q);

    private:
        void reducedForm();
    };
}
#endif