#include <iostream>
#include <string>

#include "Reader.hh"

int main(int argc, char** argv) 
{
    std::string filepath = std::string(argv[1]);
    
    Reader reader;
    reader.Read(filepath);

    // reader.Print();
    reader.PrintStatistics();
    return 0;
}