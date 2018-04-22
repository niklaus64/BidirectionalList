#include "FileParser.h"
#include <fstream>
#include <cassert>
#include <iostream>

BidirectionalList FileParser::parseFile(const std::string& filename, const Range& range)
{
    BidirectionalList list {range};

    std::fstream file;
    file.open(filename, std::ios::in);

    assert(file.is_open());

    std::string tmp;
    while(file >> tmp)
    {
        ValueType type = getType(tmp);
        assert(type != ValueType::INVALID);

        if(type == ValueType::INT) { list.push(numberParser.stringToInt(tmp)); } 
        else if(type == ValueType::DOUBLE) { list.push(numberParser.stringToDouble(tmp)); }
    }
    
    return list;
}

FileParser::ValueType FileParser::getType(const std::string& number)
{
    int separators = 0;
    for(const auto& ch : number)
    {
        if(ch == '.') { ++separators; }
        assert (ch >= '0' || ch <= '9');
    }
    
    if(separators == 0) { return ValueType::INT; }
    else if(separators == 1) { return ValueType::DOUBLE; }
    else { return ValueType::INVALID; }
}