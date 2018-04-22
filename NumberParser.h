#pragma once

#include <string>
#include <cmath>
#include <limits>

class NumberParser
{
public:
    NumberParser();
    int stringToInt(const std::string &number) const;
    double stringToDouble(const std::string &number) const;
private:
    const int MAX_INT_DIGITS;
    const int MAX_INT_FIRST_DIGIT;

    int countDigits(int number) const;
    int getNthDigit(int number, int n) const;
    double makeDouble(int integralPart, int fractionalPart, bool isPositive) const;
};