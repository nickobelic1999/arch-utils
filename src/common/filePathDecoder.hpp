//
// Created by nickobelic1999 on 3/9/23.
//

#pragma once

#include "common.hpp"

namespace Arch_Utils
{

    class File_Path_Decoder
    {

    public:


        const char* Grab_File_Path(int c, char* v[]);


        File_Path_Decoder();
        ~File_Path_Decoder();

    private:

        std::vector<char*> _find_filepath;


    };
}


