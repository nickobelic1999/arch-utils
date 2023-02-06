#include "arch_utils_common.hpp"

using namespace arch_utils;

void errorHandler::setErrorCode(int code)
{
    _code = code;
}

int errorHandler::getErrorCode()
{
    return _code;
}

void errorHandler::setErrorMsg(std::string msg)
{
    _msg = msg;
}

std::string errorHandler::getErrorMsg()
{
    return _msg
}

int errorHandler::onExit(int code, std::string msg)
{

    std::cerr << msg << std::endl;
    return code;

}

errorHandler::errorHandler()
{}

errorHandler::~errorHandler()
{}


