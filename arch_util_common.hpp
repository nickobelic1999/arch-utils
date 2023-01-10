#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <regex>

#include <stdlib.h>


namespace arch_utils
{
    struct cmds
    {
	std::string command;

    };

    class errorHandler
    {
    public:
        void printMsg(std::string);


        errorHandler();
        ~errorHandler();

    private:

        std::string _msg;

    };

}
