#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>


int main(int argc, char *argv[])
{
    std::string inputLine;
    int numberOfLines = 0;
    std::cin >> numberOfLines;
    std::vector<std::string>input;
    input.reserve(numberOfLines);
    for(int i = 0; i < numberOfLines; i++)
    {
        std::getline(std::cin, inputLine);
        input.push_back(inputLine);
    }
    for(auto line: input)
    {
        std::cout << line << std::endl;
    }
    return 0;
}