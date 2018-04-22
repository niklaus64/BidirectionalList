#pragma once

#include "NumberParser.h"
#include "BidirectionalList.h"
#include <string>

class FileParser
{
	using Range = std::pair<uint32_t, uint32_t>;
    NumberParser numberParser;
public:
    FileParser() = default;
    BidirectionalList parseFile(const std::string& filename, const Range& range);
};
