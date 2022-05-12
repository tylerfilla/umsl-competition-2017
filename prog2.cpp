/*
 * Tyler Filla
 * OPC17 Entry
 * Problem #2
 */

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <map>

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        std::cout << "COMMAND ERROR" << std::endl;
        return 0;
    }

    std::string username = argv[2];
    std::string username2;

    std::set<char> used;

    for (int ci = 0; ci < username.size(); ++ci)
    {
        char c = username[ci];
        if (used.find(c) != used.end())
        {
            continue;
        }
        used.insert(c);

        username2 += c;
    }

    std::string username3;

    for (int ci = 0; ci < username2.size(); ++ci)
    {
        char c = username2[ci];
        if (isalpha(c))
        {
            username3 += toupper(c);
        }
    }

    for (int i = 0; i < username3.size(); ++i)
    {
        char c = username3[i];
        if (isalpha(c))
        {
            std::ifstream dict;
            dict.open(argv[1]);

            if (!dict)
            {
                std::cout << "FILE ERROR" << std::endl;
                return 0;
            }

            std::string word;
            while (dict >> word)
            {
                if (toupper(word[0]) == toupper(c))
                {
                    std::cout << word;
                }
            }

            if (i < username3.size() - 1)
            {
                std::cout << " ";
            }

            dict.close();
        }
    }

    if (!username3.empty())
    {
        std::cout << std::endl;
    }

    return 0;
}

