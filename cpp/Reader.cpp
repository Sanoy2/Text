#include "Reader.hh"

Reader::Reader()
{
    pattern = std::regex("[^A-Za-z\\s]+");
}

void Reader::Read(std::string filepath)
{
    // std::cout << filepath << std::endl;
    std::ifstream file(filepath);
    std::string line;
    while (std::getline(file, line))
    {
        line = RemoveSpecials(line);
        std::vector<std::string> words;
        boost::split(words, line, [](char c)
        {
            return c == ' ';
        });

        for (auto &word : words) // access by reference to avoid copying
        {
            if(!IsEmpty(word))
            {
                std::transform(word.begin(), word.end(), word.begin(), ::tolower);
                Increment(word);
            }
        }
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
        std::cout << "Key: " << elem.first << ", Value: " << elem.second << std::endl;
    }
    std::cout << dictionary.size() << " words in dictionary" << std::endl;
}

void Reader::PrintStatistics()
{
    std::cout << NumberOfDifferentWords() << " different keys" << std::endl;
    std::cout << NumberOfWords() << " words in text" << std::endl;
}

int Reader::NumberOfWords()
{
    int numberOfWords = 0;
    for(auto elem : dictionary)
    {
        numberOfWords += elem.second;
    }
    return numberOfWords;
}

int Reader::NumberOfDifferentWords()
{
    return dictionary.size();
}