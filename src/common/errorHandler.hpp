#pragma once

#include <iostream>

namespace Arch_Utils
{
  class Error_Handler
  {
  public:
      void SetErrorCode(int code);
      int GetErrorCode();

      void SetErrorMsg(std::string msg);
      std::string GetErrorMsg();

      int OnExit();


      Error_Handler();
      ~Error_Handler();

  private:
      int _code;
      std::string _msg;

  };
}
