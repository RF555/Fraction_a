#include "../sources/Fraction.hpp"
#include "Fraction.hpp"

namespace ariel {

    Fraction::Fraction() : _numerator(0), _denominator(1) {}

    Fraction::Fraction(int x, int y = 1) : _numerator(x), _denominator(y) {
        if (y == 0) {
            throw overflow_error("ARITHMETIC ERROR: Denominator can not be 0!\n");
        }
        this->reducedForm();
    }

    Fraction::Fraction(const Fraction &q)
            : _numerator(q._numerator), _denominator(q._denominator) {
        this->reducedForm();
    }

    Fraction::Fraction(const double &d) : _numerator(d), _denominator(1) {
        this->reducedForm();
    }

    Fraction::Fraction(const float &f) : _numerator(f), _denominator(1) {
        this->reducedForm();
    }

    Fraction::~Fraction() = default;

    Fraction &Fraction::operator=(const Fraction &q) {
        if (this != &q) {
            this->_numerator = q._numerator;
            this->_denominator = q._denominator;
        }
        return *this;
    }

    Fraction operator+(const Fraction &a, const Fraction &b) {
        return {a._numerator * b._denominator + b._numerator * a._denominator, a._denominator * b._denominator};
    }

    Fraction operator-(const Fraction &a, const Fraction &b) {
        return {a._numerator * b._denominator - b._numerator * a._denominator, a._denominator * b._denominator};
    }

    Fraction operator*(const Fraction &a, const Fraction &b) {
        return {a._numerator * b._numerator, a._denominator * b._denominator};
    }

    Fraction operator/(const Fraction &a, const Fraction &b) {
        if (b == 0 || b._numerator == 0) {
            throw overflow_error("ARITHMETIC ERROR: Can not divide by 0!");
        }
        return {a._numerator * b._denominator, a._denominator * b._numerator};
    }

    Fraction &Fraction::operator+=(const Fraction &q) {
        this->_numerator = this->_numerator * q._denominator + q._numerator * this->_denominator;
        this->_denominator *= q._denominator;
        this->reducedForm();
        return *this;
    }

    Fraction &Fraction::operator-=(const Fraction &q) {
        this->_numerator = this->_numerator * q._denominator - q._numerator * this->_denominator;
        this->_denominator *= q._denominator;
        this->reducedForm();
        return *this;
    }

    Fraction &Fraction::operator*=(const Fraction &q) {
        this->_numerator *= q._numerator;
        this->_denominator *= q._denominator;
        this->reducedForm();
        return *this;
    }

    Fraction &Fraction::operator++() {
        this->_numerator += this->_denominator;
        this->reducedForm();
        return *this;
    }

    Fraction Fraction::operator++(int) {
        Fraction copy = *this;
        this->_numerator += this->_denominator;
        this->reducedForm();
        return copy;
    }

    Fraction &Fraction::operator--() {
        this->_numerator -= this->_denominator;
        this->reducedForm();
        return *this;
    }

    Fraction Fraction::operator--(int) {
        Fraction copy = *this;
        this->_numerator -= this->_denominator;
        this->reducedForm();
        return copy;
    }

    Fraction Fraction::operator-() const {
        return {-this->_numerator, -this->_denominator};
    }

    bool Fraction::operator!() const {
        return this->_numerator == 0;
    }

    bool operator==(const Fraction &a, const Fraction &b) {
        return a._numerator == b._numerator && a._denominator == b._denominator;
    }

    bool operator!=(const Fraction &a, const Fraction &b) {
        return a._numerator != b._numerator || a._denominator != b._denominator;
    }

    bool operator>=(const Fraction &a, const Fraction &b) {
        return a._numerator / a._denominator >= b._numerator / b._denominator;
    }

    bool operator<=(const Fraction &a, const Fraction &b) {
        return a._numerator / a._denominator <= b._numerator / b._denominator;
    }

    bool operator>(const Fraction &a, const Fraction &b) {
        return a._numerator / a._denominator > b._numerator / b._denominator;
    }

    bool operator<(const Fraction &a, const Fraction &b) {
        return a._numerator / a._denominator < b._numerator / b._denominator;
    }

    std::ostream &operator<<(ostream &output, const Fraction &q) {
        return output << q._numerator << '/' << q._denominator;
    }

    istream &Fraction::checkNextChar(istream &input, char expectedChar) {
        char actualChar;
        input >> actualChar;
        if (!input) { return input; }
        if (actualChar != expectedChar) {
            input.setstate(ios::failbit);
        }
        return input;
    }

    std::istream &operator>>(istream &input, Fraction &q) {
        int new_num = 0, new_den = 0;
        // remember place for rewinding
        ios::pos_type startPosition = input.tellg();

        if ((!(input >> new_num)) ||
            (!Fraction::checkNextChar(input, '/')) ||
            (!(input >> new_den))) {

            // rewind on error
            auto errorState = input.rdstate(); // remember error state
            input.clear(); // clear error so seekg will work
            input.seekg(startPosition); // rewind
            input.clear(errorState); // set back the error flag
        } else {
            q._numerator = new_num;
            q._denominator = new_den;
        }
        return input;
    }

    void Fraction::reducedForm() {

    }


}
