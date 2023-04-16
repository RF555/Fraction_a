#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Constructors initiated correctly") {
    Fraction a;
    CHECK(a.numerator() == 0);
    CHECK(a.denominator() == 1);
    Fraction b(1, 2);
    CHECK(b.numerator() == 1);
    CHECK(b.denominator() == 2);
}

TEST_CASE("Reduced form") {
    Fraction c(2, 4);
    CHECK(c.numerator() == 1);
    CHECK(c.denominator() == 2);
    Fraction d(3, 9);
    CHECK(d.numerator() == 1);
    CHECK(d.denominator() == 3);
}

TEST_CASE("Error when dividing by 0") {
    CHECK_THROWS(Fraction(3, 0));
    Fraction a(2, 5);
    Fraction b;
    CHECK_THROWS(a / b);
    CHECK_THROWS(a / 0);
}

TEST_CASE("Copy constructor and = operation") {
    Fraction a(5, 9);
    Fraction b(a);
    CHECK(&a != &b);
    CHECK(a.numerator() == b.numerator());
    CHECK(a.denominator() == b.denominator());
    Fraction c = a;
    CHECK(&a != &c);
    CHECK(a.numerator() == c.numerator());
    CHECK(a.denominator() == c.denominator());
}

TEST_CASE("Arithmetic operations") {
    Fraction a;
    Fraction b(1, 5);
    Fraction c = a + b;
    CHECK(c == 1 / 5);
    Fraction d = b * c;
    CHECK(d == 1 / 25);
    Fraction e = b - d;
    CHECK(e == (1 / 5 - 1 / 25));
    c += b;
    CHECK(c == 2 / 5);
    e -= d;
    CHECK(e == (1 / 5 - 2 / 25));
    d *= b;
    CHECK(d == 1 / 125);
    CHECK(a++ == 0);
    CHECK(a == 1);
    CHECK(++a == 2);
    Fraction f(20, 7);
    CHECK(f-- == 20 / 7);
    CHECK(f == 13 / 7);
    CHECK(--f == 6 / 7);
    Fraction g = c / f;
    CHECK(g == 7 / 15);
    Fraction gg = -g;
    CHECK(gg == -7 / 15);
}

TEST_CASE("Boolean operations") {
    Fraction a;
    Fraction b(2, 5);
    Fraction bb(2, 5);
    Fraction c(3, 10);
    Fraction d(-5, 8);
    Fraction dd(10, -16);
    CHECK(!a);
    CHECK_FALSE(!b);
    CHECK(a != b);
    CHECK(c != d);
    CHECK(b == bb);
    CHECK(d == dd);
    CHECK(a >= a);
    CHECK(bb >= b);
    CHECK(c >= c);
    CHECK(dd >= d);
    CHECK(a <= a);
    CHECK(b <= bb);
    CHECK(c <= c);
    CHECK(d <= dd);
    CHECK(b > a);
    CHECK(d < a);
    CHECK(b > d);
}
