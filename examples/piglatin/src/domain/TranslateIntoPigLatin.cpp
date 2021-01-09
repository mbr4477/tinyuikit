#include "TranslateIntoPigLatin.h"

std::string TranslateIntoPigLatin(std::string input)
{
    int wordStart;
    int wordEnd;
    wordStart = 0;
    std::string word;
    std::string output = "";
    while ((wordEnd = input.find(' ', wordStart)) != std::string::npos)
    {
        word = input.substr(wordStart, wordEnd - wordStart);
        word = word.substr(1) + word[0] + "ay ";
        output += word;
    }
    return output;
}