#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "NumberWithUnits.hpp"
using namespace ariel;
#include "doctest.h"

TEST_CASE("Load & Read from file test")
{
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
}

TEST_CASE("error - [+] different dimensions")
{
    NumberWithUnits a(2, "kg");
    NumberWithUnits b(50, "min");
    CHECK_THROWS(a + b);

    NumberWithUnits c(-3, "ton");
    NumberWithUnits d(10, "m");
    CHECK_THROWS(c + d);
}

TEST_CASE("good - [+] same dimensions")
{
    NumberWithUnits a(2, "kg");
    NumberWithUnits b(5000, "g");
    NumberWithUnits result1(7, "kg");
    CHECK((a + b) == result1);

    NumberWithUnits c(-3, "km");
    NumberWithUnits d(10000, "m");
    NumberWithUnits result2(7, "km");
    CHECK((c + d) == result2);

    NumberWithUnits e(2, "hour");
    NumberWithUnits f(-60, "min");
    NumberWithUnits result3(1, "hour");
    CHECK((e + f) == result3);

    NumberWithUnits g(2, "hour");
    NumberWithUnits h(30, "min");
    NumberWithUnits result4(2.5, "hour");
    CHECK((g + h) == result4);

    NumberWithUnits i(5, "kg");
    NumberWithUnits j(9, "g");
    NumberWithUnits result5(5.009, "kg");
    CHECK((i + j) == result5);
}

TEST_CASE("error - [+=] different dimensions")
{
    NumberWithUnits a(2, "kg");
    NumberWithUnits b(50, "min");
    CHECK_THROWS(a += b);

    NumberWithUnits c(-3, "ton");
    NumberWithUnits d(10, "m");
    CHECK_THROWS(c += d);
}

TEST_CASE("good - [+=] same dimensions")
{
    NumberWithUnits a(2, "kg");
    NumberWithUnits b(5000, "g");
    NumberWithUnits result1(7, "kg");
    a += b;
    CHECK(a == result1);

    NumberWithUnits c(-3, "km");
    NumberWithUnits d(10000, "m");
    NumberWithUnits result2(7, "km");
    c += d;
    CHECK(c == result2);

    NumberWithUnits e(2, "hour");
    NumberWithUnits f(-60, "min");
    NumberWithUnits result3(1, "hour");
    e += f;
    CHECK(e == result3);

    NumberWithUnits g(2, "hour");
    NumberWithUnits h(30, "min");
    NumberWithUnits result4(2.5, "hour");
    g += h;
    CHECK(g == result4);

    NumberWithUnits i(5, "kg");
    NumberWithUnits j(9, "g");
    NumberWithUnits result5(5.009, "kg");
    i += j;
    CHECK(i == result5);
}

TEST_CASE("[+] Unari")
{
    NumberWithUnits a(5, "kg");
    CHECK((+a) == a);
    NumberWithUnits b(-3, "km");
    CHECK((+b) == b);
    NumberWithUnits c(2, "min");
    CHECK((+c) == c);
}

TEST_CASE("++")
{
    NumberWithUnits a(5, "kg");
    NumberWithUnits Pa(6, "kg");
    CHECK((++a) == Pa);
    CHECK((a++) == Pa);
    NumberWithUnits PPa(7, "kg");
    CHECK(a == PPa);

    NumberWithUnits b(3, "km");
    NumberWithUnits Pb(4, "km");
    CHECK((++b) == Pb);
    CHECK((b++) == Pb);
    NumberWithUnits PPb(5, "km");
    CHECK(b == PPb);

    NumberWithUnits c(-2, "hour");
    NumberWithUnits Pc(-1, "hour");
    CHECK((++c) == Pc);
    CHECK((c++) == Pc);
    NumberWithUnits PPc(0, "hour");
    CHECK(c == PPc);
}

TEST_CASE("error - [-] different dimensions")
{
    NumberWithUnits a(2, "kg");
    NumberWithUnits b(5, "min");
    CHECK_THROWS(a - b);

    NumberWithUnits c(-3, "ton");
    NumberWithUnits d(10, "m");
    CHECK_THROWS(c - d);
}

TEST_CASE("good - [-] same dimensions")
{
    NumberWithUnits a(2, "kg");
    NumberWithUnits b(5000, "g");
    NumberWithUnits result1(3000, "g");
    CHECK((b - a) == result1);

    NumberWithUnits c(-3, "km");
    NumberWithUnits d(10000, "m");
    NumberWithUnits result2(-13, "km");
    CHECK((c - d) == result2);

    NumberWithUnits e(2, "hour");
    NumberWithUnits f(-60, "min");
    NumberWithUnits result3(3, "hour");
    CHECK((e - f) == result3);

    NumberWithUnits g(2, "hour");
    NumberWithUnits h(30, "min");
    NumberWithUnits result4(1.5, "hour");
    CHECK((g - h) == result4);

    NumberWithUnits i(1, "kg");
    NumberWithUnits j(9, "g");
    NumberWithUnits result5(-991, "g");
    CHECK((j - i) == result5);
}

TEST_CASE("error - [-=] different dimensions")
{
    NumberWithUnits a(2, "kg");
    NumberWithUnits b(5, "min");
    CHECK_THROWS(a -= b);

    NumberWithUnits c(-3, "ton");
    NumberWithUnits d(10, "m");
    CHECK_THROWS(c -= d);
}

TEST_CASE("good - [-=] same dimensions")
{
    NumberWithUnits a(2, "kg");
    NumberWithUnits b(5000, "g");
    NumberWithUnits result1(3000, "g");
    b -= a;
    CHECK(b == result1);

    NumberWithUnits c(-3, "km");
    NumberWithUnits d(10000, "m");
    NumberWithUnits result2(-13, "km");
    c -= d;
    CHECK(c == result2);

    NumberWithUnits e(2, "hour");
    NumberWithUnits f(-60, "min");
    NumberWithUnits result3(3, "hour");
    e -= f;
    CHECK(e == result3);

    NumberWithUnits g(2, "hour");
    NumberWithUnits h(30, "min");
    NumberWithUnits result4(2.5, "hour");
    g += h;
    CHECK(g == result4);

    NumberWithUnits i(1, "kg");
    NumberWithUnits j(9, "g");
    NumberWithUnits result5(-991, "g");
    j -= i;
    CHECK(j == result5);
}

TEST_CASE("[-] Unari")
{
    NumberWithUnits a(2, "kg");
    NumberWithUnits Ma(-2, "kg");
    CHECK((-a) == Ma);
    NumberWithUnits b(-3, "km");
    NumberWithUnits Mb(3, "km");
    CHECK((-b) == Mb);
}

TEST_CASE("--")
{
    NumberWithUnits a(5, "kg");
    NumberWithUnits Ma(4, "kg");
    CHECK((--a) == Ma);
    CHECK((a--) == Ma);
    NumberWithUnits MMa(3, "kg");
    CHECK(a == MMa);

    NumberWithUnits b(3, "km");
    NumberWithUnits Mb(2, "km");
    CHECK((--b) == Mb);
    CHECK((b--) == Mb);
    NumberWithUnits MMb(1, "km");
    CHECK(b == MMb);

    NumberWithUnits c(-2, "hour");
    NumberWithUnits Mc(-3, "hour");
    CHECK((--c) == Mc);
    CHECK((c--) == Mc);
    NumberWithUnits MMc(-4, "hour");
    CHECK(c == MMc);
}

TEST_CASE("*")
{
    double num1 = 3;
    NumberWithUnits n1{2, "USD"};
    NumberWithUnits left{6, "USD"};
    CHECK((num1 * n1) == left);

    double num2 = -5;
    NumberWithUnits n2{1000, "m"};
    NumberWithUnits right{-5000, "m"};
    CHECK((n2 * num2) == right);
}

TEST_CASE("*=")
{
    double num1 = 3;
    NumberWithUnits n1{2, "USD"};
    NumberWithUnits ans1{6, "USD"};
    n1 *= num1;
    CHECK(n1 == ans1);

    double num2 = -6;
    NumberWithUnits n2{10, "cm"};
    NumberWithUnits ans2{-60, "cm"};
    n2 *= num2;
    CHECK(n2 == ans2);
}

TEST_CASE("error - [<] different dimensions")
{
    bool ans;

    NumberWithUnits a{2, "km"};
    NumberWithUnits b{1, "sec"};
    CHECK_THROWS(ans = (a < b));

    NumberWithUnits c{8, "g"};
    NumberWithUnits d{1000, "m"};
    CHECK_THROWS(ans = (c < d));
}

TEST_CASE("good - [<] different dimensions")
{
    //false
    NumberWithUnits a{20, "km"};
    NumberWithUnits b{5, "km"};
    CHECK_FALSE(a < b);

    NumberWithUnits c{5, "kg"};
    NumberWithUnits d{4500, "g"};
    CHECK_FALSE(c < d);

    NumberWithUnits e{2000000, "cm"};
    NumberWithUnits f{1, "km"};
    CHECK_FALSE(e < f);

    //true
    NumberWithUnits g{5, "km"};
    NumberWithUnits h{6, "km"};
    CHECK(g < h);

    NumberWithUnits i{5, "kg"};
    NumberWithUnits j{6000, "g"};
    CHECK(i < j);
}

TEST_CASE("error - [<=] different dimensions")
{
    bool ans;

    NumberWithUnits a{2, "km"};
    NumberWithUnits b{1, "sec"};
    CHECK_THROWS(ans = (a <= b));

    NumberWithUnits c{8, "g"};
    NumberWithUnits d{1000, "m"};
    CHECK_THROWS(ans = (c <= d));
}

TEST_CASE("good - [<=] different dimensions")
{
    //false
    NumberWithUnits a{20, "km"};
    NumberWithUnits b{5, "km"};
    CHECK_FALSE(a <= b);

    NumberWithUnits c{5, "kg"};
    NumberWithUnits d{4500, "g"};
    CHECK_FALSE(c <= d);

    NumberWithUnits e{2000000, "cm"};
    NumberWithUnits f{1, "km"};
    CHECK_FALSE(e <= f);

    //true
    NumberWithUnits g{5, "km"};
    NumberWithUnits h{6, "km"};
    CHECK(g <= h);

    NumberWithUnits i{5, "kg"};
    NumberWithUnits j{6000, "g"};
    CHECK(i <= j);

    NumberWithUnits k{1000, "m"};
    NumberWithUnits l{1, "km"};
    CHECK(k <= l);
}

TEST_CASE("error - [>] different dimensions")
{
    bool ans;

    NumberWithUnits a{2, "km"};
    NumberWithUnits b{1, "sec"};
    CHECK_THROWS(ans = (b > a));

    NumberWithUnits c{8, "g"};
    NumberWithUnits d{1000, "m"};
    CHECK_THROWS(ans = (d > c));
}

TEST_CASE("good - [>] different dimensions")
{
    //false
    NumberWithUnits a{20, "km"};
    NumberWithUnits b{5, "km"};
    CHECK_FALSE(b > a);

    NumberWithUnits c{5, "kg"};
    NumberWithUnits d{4500, "g"};
    CHECK_FALSE(d > c);

    NumberWithUnits e{2000000, "cm"};
    NumberWithUnits f{1, "km"};
    CHECK_FALSE(f > e);

    //true
    NumberWithUnits g{5, "km"};
    NumberWithUnits h{6, "km"};
    CHECK(h > g);

    NumberWithUnits i{5, "kg"};
    NumberWithUnits j{6000, "g"};
    CHECK(j > i);
}

TEST_CASE("error - [>=] different dimensions")
{
    bool ans;

    NumberWithUnits a{2, "km"};
    NumberWithUnits b{1, "sec"};
    CHECK_THROWS(ans = (b >= a));

    NumberWithUnits c{8, "g"};
    NumberWithUnits d{1000, "m"};
    CHECK_THROWS(ans = (d >= c));
}

TEST_CASE("good - [<=] different dimensions")
{
    //false
    NumberWithUnits a{20, "km"};
    NumberWithUnits b{5, "km"};
    CHECK_FALSE(b >= a);

    NumberWithUnits c{5, "kg"};
    NumberWithUnits d{4500, "g"};
    CHECK_FALSE(d >= c);

    NumberWithUnits e{2000000, "cm"};
    NumberWithUnits f{1, "km"};
    CHECK_FALSE(f >= e);

    //true
    NumberWithUnits g{5, "km"};
    NumberWithUnits h{6, "km"};
    CHECK(h >= g);

    NumberWithUnits i{5, "kg"};
    NumberWithUnits j{6000, "g"};
    CHECK(j >= i);

    NumberWithUnits k{1000, "m"};
    NumberWithUnits l{1, "km"};
    CHECK(l >= k);
}

TEST_CASE("==")
{
    NumberWithUnits a{1, "km"};
    NumberWithUnits b{1000, "m"};
    CHECK(a == b);

    NumberWithUnits c{1, "m"};
    NumberWithUnits d{100, "cm"};
    CHECK(c == d);

    NumberWithUnits e{1, "hour"};
    NumberWithUnits f{3600, "sec"};
    CHECK(e == f);

    NumberWithUnits g{1, "kg"};
    NumberWithUnits h{100, "g"};
    CHECK_FALSE(g == h);

    NumberWithUnits i{1, "hour"};
    NumberWithUnits j{360, "min"};
    CHECK_FALSE(i == j);
}

TEST_CASE("!=")
{
    NumberWithUnits a{1, "km"};
    NumberWithUnits b{1000, "m"};
    CHECK_FALSE(a != b);

    NumberWithUnits c{1, "m"};
    NumberWithUnits d{100, "cm"};
    CHECK_FALSE(c != d);

    NumberWithUnits e{1, "kg"};
    NumberWithUnits f{100, "g"};
    CHECK(e != f);

    NumberWithUnits g{1, "hour"};
    NumberWithUnits h{360, "min"};
    CHECK(g != h);
}

TEST_CASE("good - [<<]")
{
    NumberWithUnits a{700, "kg"};
    ostringstream streamB;
    streamB << a;
    CHECK(streamB.str() == "700[kg]");
}

TEST_CASE("error - [>>]")
{
    NumberWithUnits a{90, "ton"};
    istringstream sample_input1{"700[RL]"};
    CHECK_THROWS(sample_input1 >> a);
}

TEST_CASE("good - [>>]")
{
    NumberWithUnits a{7, "ton"};
    istringstream sample_input{"700[kg]"};
    sample_input >> a;
    NumberWithUnits b{700, "kg"};
    CHECK(a == b);
}