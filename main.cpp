#include <iostream>
#include <cassert>
#include <fstream>
#include "FileParser.h"
#include "BidirectionalList.h"

auto main(int argc, char** argv) -> int 
{
    assert(argc > 1);

    FileParser fp;
    std::string filename{argv[1]};
    BidirectionalList list = fp.parseFile(filename, {1, 10});

    return 0;
}