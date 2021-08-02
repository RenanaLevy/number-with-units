#pragma once

#include <fstream>
#include <iostream>
using namespace std;

namespace ariel{
    class NumberWithUnits{
        double number;
        string unit;

        bool checkIfTheSameType(const NumberWithUnits &num1, const NumberWithUnits &num2);

        public:
            NumberWithUnits(double num, string unit_input): number(num), unit(unit_input) {};

            static void read_units(ifstream& f);

            friend NumberWithUnits operator+(const NumberWithUnits& num1, const NumberWithUnits& num2);
            friend NumberWithUnits& operator+=(NumberWithUnits& num1, const NumberWithUnits& num2);
            NumberWithUnits& operator+();
            NumberWithUnits& operator++();      //prefix
            NumberWithUnits& operator++(int);   //postfix

            friend NumberWithUnits operator-(const NumberWithUnits& num1, const NumberWithUnits& num2);
            friend NumberWithUnits& operator-=(NumberWithUnits& num1, const NumberWithUnits& num2);
            NumberWithUnits& operator-();
            NumberWithUnits& operator--();      //prefix
            NumberWithUnits& operator--(int);   //postfix

            friend NumberWithUnits operator*(const double& num1, const NumberWithUnits& num2);
            friend NumberWithUnits operator*(const NumberWithUnits& num1, const double& num2);
            NumberWithUnits& operator *=(const double& num);

            bool operator<(const NumberWithUnits& num) const;
            bool operator<=(const NumberWithUnits& num) const;
            bool operator>(const NumberWithUnits& num) const;
            bool operator>=(const NumberWithUnits& num) const;
            bool operator==(const NumberWithUnits& num) const;
            bool operator!=(const NumberWithUnits& num) const;
            
            friend ostream& operator<<(ostream& out, const NumberWithUnits& num);
            friend istream& operator>>(istream& in, const NumberWithUnits& num);
    };
};