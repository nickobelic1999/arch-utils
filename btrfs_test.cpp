//
// Created by nickobelic1999 on 3/9/23.
//

#include <iostream>

#include "arch_utils_common/btrfsUtils.hpp"

int main(int argc, char* argv[])
{

    Arch_Utils::Btrfs_Utils btrfsUtils;

    // Load in arguments
    std::vector<std::string> input_args;
    for (auto i = 1; i < argc; ++i)
    {
        input_args.push_back(argv[i]);
    }

    // Check for arguments
    if (input_args.empty())
    {
        std::cout << "You need to provide at least 1 argument!\n";
        return 1;
    }

    if(std::find(input_args.begin(), input_args.end(), "-h") != input_args.end())
    {
        std::cout << "This is the help prompt!" << std::endl;
    }
    else if(std::find(input_args.begin(), input_args.end(), "--help") != input_args.end())
    {
        std::cout << "This is the help prompt!" << std::endl;
    }
    else if(std::find(input_args.begin(), input_args.end(), "create") != input_args.end())
    {



        btrfsUtils.OpenFileSystem(str);
        btrfsUtils.CreateBtrfsSubvolume("@test");

    }
    else if(std::find(input_args.begin(), input_args.end(), "delete") != input_args.end())
    {


        btrfsUtils.OpenFileSystem("/Volume/machines");
        btrfsUtils.DeleteBtrfsSubvolume("@test");

    }
    else
    {
        std::cout << "No valid commands given!" << std::endl;
        return -1;
    }

    return 0;

}
