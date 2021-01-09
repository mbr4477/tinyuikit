#include "TranslateIntoPigLatin.h"

std::string TranslateIntoPigLatin(std::string input)
{
    if (input.size() == 0)
    {
        return "";
    }
    int wordStart;
    int wordEnd;
    wordStart = 0;
    std::string word;
    std::string output = "";
    do
    {
        wordEnd = input.find(' ', wordStart);
        if (wordEnd == std::string::npos)
        {
            wordEnd = input.length();
        }
        word = input.substr(wordStart, wordEnd - wordStart);
        word = word.substr(1) + word[0] + "ay ";
        wordStart = wordEnd + 1;
        output += word;
    } while (wordEnd < input.length());
    return output;
}