#include <iostream>
#include <random>
#include <ctime>
#include <unistd.h>

std::random_device rd;
std::mt19937 mt(rd());

static const char dict[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "!@#$%^&*()_+-=[]{};':\"./>?";

std::string genrand(const int len)
{
    std::string tmp_s;
    tmp_s.reserve(len);

    for(auto i = 0; i < len; i++)
    {
        tmp_s += dict[rand() % (sizeof(dict) - 1)];
    }

    return tmp_s;
}

int main(int argc, char* argv[])
{

    if(argc <= 1)
    {
        std::cerr << "genrand requires a number as an argument, all adddtional arguments will be disregarded!" << std::endl;
        return -1;
    }
    else
    {
        srand((unsigned)time(NULL) * getpid() * mt());
        std::cout << genrand(std::stoi(argv[1])) << "\n";

    }

    return 0;
}
