#include "NumberParser.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <cassert>

NumberParser::NumberParser() 
    : MAX_INT_DIGITS{countDigits(std::numeric_limits<int>::max())},
    MAX_INT_FIRST_DIGIT{getNthDigit(std::numeric_limits<int>::max(), MAX_INT_DIGITS)}
{
    
}

int NumberParser::stringToInt(const std::string &number) const
{
    bool isNegative = number[0] == '-';
    assert(number.length() > 0 && number.length() <= MAX_INT_DIGITS + isNegative);
    if(number.length() == MAX_INT_DIGITS + isNegative)
    {
        assert((number[isNegative] - '0') <= MAX_INT_FIRST_DIGIT);
    }
    int result = 0;
    int multiplier = 1;
    auto end = std::crend(number) - isNegative;
    for (auto ch = std::crbegin(number); ch != end; ++ch)
    {
        result += (*ch - '0') * multiplier;
        multiplier *= 10;
    }

    return isNegative ? -1 * result : result;
}

double NumberParser::stringToDouble(const std::string &number) const
{
    int separator = number.find_first_of(".");

    int integralPart = stringToInt(number.substr(0, separator));
    int fractionalPart = stringToInt(number.substr(separator + 1));
    bool isPositive = number[0] != '-';

    return makeDouble(integralPart, fractionalPart, isPositive);
}

int NumberParser::countDigits(int number) const
{
    int digits = 0;
    while (number > 0)
    {
        number /= 10;
        ++digits;
    }

    return digits;
}

int NumberParser::getNthDigit(int number, int n) const
{
    while(n > 1)
    {
        number /= 10;
        --n;
    }
    return number;
}

double NumberParser::makeDouble(int integralPart, int fractionalPart, bool isPositive) const
{
    double integral = static_cast<double>(integralPart);
    double fractional = static_cast<double>(fractionalPart) * static_cast<double>(std::pow(10, -countDigits(fractionalPart)));

    return isPositive ? integral + fractional : integral - fractional;
}