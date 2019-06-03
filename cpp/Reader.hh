#ifndef READER_HH
#define READER_HH

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <map>
#include <boost/algorithm/string.hpp>

class Reader
{
    private:
        std::map<std::string, int> dictionary;
        std::regex pattern;
        std::string RemoveSpecials(std::string);
        bool IsEmpty(std::string);
        void Increment(std::string);

    public: 
        Reader();
        void Read(std::string);
        void Print();
};

#endif