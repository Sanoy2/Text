#include "Reader.hh"

Reader::Reader()
{
    pattern = std::regex("[^a-zA-Z]");
}

void Reader::Read(std::string filepath)
{
    std::cout << filepath << std::endl;
    std::ifstream file(filepath);
    std::string line;
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }
}

bool Reader::IsEmpty(std::string text)
{
    return text.empty() || text.length() < 1;
}

std::string Reader::RemoveSpecials(std::string text)
{
    return std::regex_replace(text, pattern, "");
}

void Reader::Increment(std::string newWord)
{
    if(dictionary.count(newWord) > 0)
    {
        dictionary[newWord] = dictionary[newWord] + 1;
    }
    else
    {
        dictionary[newWord] = 1;
    }
}

void Reader::Print()
{
    for(auto elem : dictionary)
    {
        std::cout << elem.first << " " << elem.second << std::endl;
    }
}