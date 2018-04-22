#include <iostream>
#include <cassert>
#include <fstream>
#include "FileParser.h"
#include "BidirectionalList.h"

int main(int argc, char** argv) 
{
    assert(argc > 1);
    std::cout << "DBG: argv[1] = " << argv[1] << std::endl;

    std::string filename{argv[1]};
    FileParser fp;
    BidirectionalList list = fp.parseFile(filename, {1, 10});
    
    return 0;
}