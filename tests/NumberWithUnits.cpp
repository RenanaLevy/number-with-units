#include "NumberWithUnits.hpp"
using namespace ariel;

namespace ariel
{
    void NumberWithUnits::read_units(ifstream &f)
    {
    }

    bool checkIfTheSameType(const NumberWithUnits &num1, const NumberWithUnits &num2)
    {
        return true;
    }

    NumberWithUnits operator+(const NumberWithUnits &num1, const NumberWithUnits &num2)
    {
        if (!checkIfTheSameType(num1, num2))
        {
            throw "Not the same type";
        }
        NumberWithUnits a(5, "min");
        return a;
    }

    NumberWithUnits& operator+=(NumberWithUnits &num1, const NumberWithUnits &num2)
    {
        return num1;
    }
    NumberWithUnits &NumberWithUnits::operator+()
    {
        return *this;
    }
    NumberWithUnits &NumberWithUnits::operator++()
    {
        return *this;
    }
    NumberWithUnits &NumberWithUnits::operator++(int)
    {
        return *this;
    }
    NumberWithUnits operator-(const NumberWithUnits &num1, const NumberWithUnits &num2)
    {
        NumberWithUnits a(5, "min");
        return a;
    }
    NumberWithUnits& operator-=(NumberWithUnits &num1, const NumberWithUnits &num2)
    {
        return num1;
    }
    NumberWithUnits &NumberWithUnits::operator-()
    {
        return *this;
    }
    NumberWithUnits &NumberWithUnits::operator--()
    {
        return *this;
    }
    NumberWithUnits &NumberWithUnits::operator--(int)
    {
        return *this;
    }
    NumberWithUnits operator*(const double &num2, const NumberWithUnits &num1)
    {
        NumberWithUnits a(5, "min");
        return a;
    }
    NumberWithUnits operator*(const NumberWithUnits &num1, const double &num2)
    {
        NumberWithUnits a(5, "min");
        return a;
    }
    NumberWithUnits &NumberWithUnits::operator*=(const double &num)
    {
        return *this;
    }
    bool NumberWithUnits::operator<(const NumberWithUnits &num) const
    {
        return false;
    }
    bool NumberWithUnits::operator<=(const NumberWithUnits &num) const
    {
        return false;
    }
    bool NumberWithUnits::operator>(const NumberWithUnits &num) const
    {
        return false;
    }
    bool NumberWithUnits::operator>=(const NumberWithUnits &num) const
    {
        return false;
    }
    bool NumberWithUnits::operator==(const NumberWithUnits &num) const
    {
        return false;
    }
    bool NumberWithUnits::operator!=(const NumberWithUnits &num) const
    {
        return false;
    }
    ostream &operator<<(ostream &out, const NumberWithUnits &num)
    {
        return out;
    }
    istream &operator>>(istream &in, const NumberWithUnits &num)
    {
        return in;
    }
}