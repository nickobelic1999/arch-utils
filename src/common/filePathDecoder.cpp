//
// Created by nickobelic1999 on 3/9/23.
//

#include "filePathDecoder.hpp"

using namespace Arch_Utils;

const char* File_Path_Decoder::Grab_File_Path(int c, char* v[])
{
    const char* str[_find_filepath.size()];

    for(auto i = 0; i < c; i++)
    {
        if(*v[i] == '/')
        {
            _find_filepath.push_back(v[i]);
            strcat((char *) str, v[i]);
        }
    }

}