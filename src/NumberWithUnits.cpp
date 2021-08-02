#include "NumberWithUnits.hpp"
using namespace ariel;

#include <map>
#include <string>

namespace ariel
{
    const double EPS = 0.001;
    static map<string, map<string, double>> units_converts;

    NumberWithUnits::NumberWithUnits(double num, const string &unit_input)
    {
        if (units_converts.count(unit_input) > 0)
        {
            this->number = num;
            this->unit = unit_input;
        }
        else
        {
            throw "Invalid unit";
        }
    }

    void NumberWithUnits::casting(const string &str1, const string &str2)
    {
        for (auto &p : units_converts[str1])
        {
            double cast = units_converts[str2][str1] * p.second;
            units_converts[str2][p.first] = cast;
            units_converts[p.first][str2] = 1 / cast;
        }
    }

    void NumberWithUnits::read_units(ifstream &f)
    {
        double n1 = 0, n2 = 0;
        string unit1, unit2, eq;
        while (!f.eof())
        {
            f >> n1 >> unit1 >> eq >> n2 >> unit2;
            units_converts[unit1][unit2] = n2;
            units_converts[unit2][unit1] = n1 / n2;
            casting(unit1, unit2);
            casting(unit2, unit1);
        }
    }

    double NumberWithUnits::convert(const string &unit1, const string &unit2, double value)
    {
        if (unit1 == unit2)
        {
            return value;
        }

        if (units_converts[unit2].find(unit1) == units_converts[unit2].end())
        {
            throw "Error!! the numbers aren't the same type";
        }
        return (value * units_converts[unit2][unit1]);
    }

    NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &num) const
    {
        double add = NumberWithUnits::convert(this->unit, num.unit, num.number);
        double result = this->number + add;
        return NumberWithUnits(result, this->unit);
    }

    NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &num)
    {
        *this = *this + num;
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator+()
    {
        return NumberWithUnits(+(this->number), this->unit);
    }
    NumberWithUnits &NumberWithUnits::operator++()
    {
        ++(this->number);
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator++(int)
    {
        double ret = this->number;
        ++(this->number);
        return NumberWithUnits(ret, this->unit);
    }
    NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits &num) const
    {
        double sub = NumberWithUnits::convert(this->unit, num.unit, num.number);
        double result = this->number - sub;
        return NumberWithUnits(result, this->unit);
    }
    NumberWithUnits &NumberWithUnits::operator-=(const NumberWithUnits &num)
    {
        *this = *this - num;
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator-()
    {
        return NumberWithUnits(-(this->number), this->unit);
    }
    NumberWithUnits &NumberWithUnits::operator--()
    {
        --(this->number);
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator--(int)
    {
        double ret = this->number;
        --(this->number);
        return NumberWithUnits(ret, this->unit);
    }
    NumberWithUnits operator*(const double &num1, const NumberWithUnits &num2)
    {
        double result = num1 * num2.number;
        return NumberWithUnits(result, num2.unit);
    }
    NumberWithUnits NumberWithUnits::operator*(const double &num) const
    {
        double result = num * this->number;
        return NumberWithUnits(result, this->unit);
    }
    NumberWithUnits &NumberWithUnits::operator*=(const double &num)
    {
        this->number *= num;
        return *this;
    }
    bool NumberWithUnits::operator<(const NumberWithUnits &num) const
    {
        double res = NumberWithUnits::convert(this->unit, num.unit, num.number);
        return res - this->number > EPS;
    }
    bool NumberWithUnits::operator<=(const NumberWithUnits &num) const
    {
        double res = NumberWithUnits::convert(this->unit, num.unit, num.number);
        if (abs(res - this->number) <= EPS)
        {
            return true;
        }
        return res - this->number > EPS;
    }
    bool NumberWithUnits::operator>(const NumberWithUnits &num) const
    {
        double res = NumberWithUnits::convert(this->unit, num.unit, num.number);
        return this->number - res > EPS;
    }
    bool NumberWithUnits::operator>=(const NumberWithUnits &num) const
    {
        double res = NumberWithUnits::convert(this->unit, num.unit, num.number);
        if (abs(res - this->number) <= EPS)
        {
            return true;
        }
        return this->number - res > EPS;
    }
    bool NumberWithUnits::operator==(const NumberWithUnits &num) const
    {
        double res = NumberWithUnits::convert(this->unit, num.unit, num.number);
        return abs(res - this->number) <= EPS;
    }
    bool NumberWithUnits::operator!=(const NumberWithUnits &num) const
    {
        double res = NumberWithUnits::convert(this->unit, num.unit, num.number);
        return abs(res - this->number) > EPS;
    }
    ostream &operator<<(ostream &out, const NumberWithUnits &num)
    {
        return out << num.number << "[" << num.unit << "]";
    }
    istream &operator>>(istream &in, NumberWithUnits &num)
    {
        double number_input = 0;
        string unit_input;
        char c = '\0';
        in >> number_input >> c;
        while (c != ']')
        {
            if (c != '[')
            {
                unit_input.insert(unit_input.end(), c);
            }
            in >> c;
        }
        if (units_converts.count(unit_input) > 0)
        {
            num.number = number_input;
            num.unit = unit_input;
        }
        else
        {
            throw "Invalid unit";
        }
        return in;
    }
}