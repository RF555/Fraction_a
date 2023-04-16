#include "../sources/Fraction.hpp"
#include "Fraction.hpp"

namespace ariel
{

    Fraction::Fraction() : _numerator(0), _denominator(1) {}

    Fraction::Fraction(const int x, const int y) : _numerator(x), _denominator(y) {}

    Fraction::Fraction(const Fraction &q) {}

    Fraction::~Fraction() {}

    ostream &operator<<(ostream &output, const Fraction q) {}
}
