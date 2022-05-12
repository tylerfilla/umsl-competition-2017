/*
 * Tyler Filla
 * OPC17 Entry
 * Problem #3
 */

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        std::cout << "DATA MISSING" << std::endl;
        return 0;
    }

    std::ifstream file;
    file.open(argv[1]);

    if (!file)
    {
        std::cout << "FILE ERROR" << std::endl;
        return 0;
    }

    std::map<int, int> m;

    int num;
    while (file >> num)
    {
        if (m.find(num) != m.end())
        {
            m.find(num)->second++;
        }
        else
        {
            m.insert(std::pair<int, int>(num, 1));
        }
    }

    if (m.empty())
    {
        std::cout << "FILE ERROR" << std::endl;
        return 0;
    }

    int max_key = -1;
    int max_count = -1;

    for (std::map<int, int>::iterator i = m.begin(); i != m.end(); ++i)
    {
        int key = (*i).first;
        int count = (*i).second;

        if (count > max_count)
        {
            max_key = key;
            max_count = count;
        }
    }

    std::set<int> winners;

    for (std::map<int, int>::iterator i = m.begin(); i != m.end(); ++i)
    {
        int key = (*i).first;
        int count = (*i).second;

        if (count == max_count)
        {
            winners.insert(key);
        }
    }

    file.close();

    std::ifstream rematch;
    rematch.open(argv[1]);

    int num2;
    while (rematch >> num2)
    {
        if (winners.find(num2) != winners.end())
        {
            std::cout << *winners.find(num2) << " " << max_count;
            break;
        }
    }

    rematch.close();

    return 0;
}

