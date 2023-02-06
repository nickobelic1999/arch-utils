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
        void setErrorCode(int code);
        int getErrorCode();

        void setErrorMsg(std::string msg);
        std::string getErrorMsg();

        int onExit(int code, std::string msg);


        errorHandler();
        ~errorHandler();

    private:
        int _code;
        std::string _msg;

    };

}
