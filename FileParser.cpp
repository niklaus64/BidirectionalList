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
        int separators = 0;
        for(const auto& ch : tmp)
        {
            if(ch == '.') { ++separators; }
            assert (ch >= '0' || ch <= '9');
        }
        
        assert(separators == 0 || separators == 1);

        if(separators == 0)
        {
            list.push(numberParser.stringToInt(tmp));
        }
        else if(separators == 1)
        {
            list.push(numberParser.stringToDouble(tmp)); 
        }
    }
    
    return list;
}