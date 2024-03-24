#include "errorHandler.hpp"

using namespace Arch_Utils;

void Error_Handler::SetErrorCode(int code)
{
    _code = code;
}

int Error_Handler::GetErrorCode()
{
    return _code;
}

void Error_Handler::SetErrorMsg(std::string msg)
{
    _msg = msg;
}

std::string Error_Handler::GetErrorMsg()
{
    return _msg;
}

int Error_Handler::OnExit()
{
    std::cerr << GetErrorMsg() << std::endl;
    return GetErrorCode();

}

Error_Handler::Error_Handler()
{}

Error_Handler::~Error_Handler()
{}

