#pragma once

#include <fstream>
#include <iostream>
using namespace std;

#include <map>
#include <string>

namespace ariel{
    class NumberWithUnits{
        double number;
        string unit;

        static double convert(const string& unit1, const string& unit2, double value);
        static void casting(const string &str1, const string &str2);

        public:
            NumberWithUnits(double num, const string& unit_input);

            static void read_units(ifstream& f);

            NumberWithUnits operator+(const NumberWithUnits& num) const;
            NumberWithUnits& operator+=(const NumberWithUnits& num);
            NumberWithUnits operator+();
            NumberWithUnits& operator++();     //prefix
            NumberWithUnits operator++(int);   //postfix

            NumberWithUnits operator-(const NumberWithUnits& num) const;
            NumberWithUnits& operator-=(const NumberWithUnits& num);
            NumberWithUnits operator-();
            NumberWithUnits& operator--();     //prefix
            NumberWithUnits operator--(int);   //postfix

            friend NumberWithUnits operator*(const double& num1, const NumberWithUnits& num2);
            NumberWithUnits operator*(const double& num) const;
            NumberWithUnits& operator *=(const double& num);

            bool operator<(const NumberWithUnits& num) const;
            bool operator<=(const NumberWithUnits& num) const;
            bool operator>(const NumberWithUnits& num) const;
            bool operator>=(const NumberWithUnits& num) const;
            bool operator==(const NumberWithUnits& num) const;
            bool operator!=(const NumberWithUnits& num) const;
            
            friend ostream& operator<<(ostream& out, const NumberWithUnits& num);
            friend istream& operator>>(istream& in, NumberWithUnits& num);
    };
};