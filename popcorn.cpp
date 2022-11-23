#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>

#include <stdlib.h>

std::vector <std::string> args;

std::string destination;
std::string cmd;
std::string default_package_list = "base base-devel zsh grml-zsh-config openssh nano wget git btrfs-progs ";


static void show_usage(std::string name)
{
    std::cerr << "Usage: " << name << " <option(s)> SOURCES\n"
              << "Options:\n"
              << "\t-h,--help\t\tShow this help message\n"
              << "\tpopulate \tThis will use \"pacstrap -i\" to install the following packages: \"base base-devel zsh grml-zsh-config openssh nano wget git btrfs-progs\"\n"
              << "\tadduser \tThis will add a user with the same username and password to the directory specified, it is RECOMMENDED to change password upon login!\n"
              << "\trun \t\tThis will run the specified container with \"systemd-nspawn -bD\" extra systemd-nspawn arguments can be added before the directory."
              << std::endl;
}

std::string packages()
{
    std::string new_package_list;
    std::string pkgs;

    std::cout << "Enter any addtional required packages (Leave blank for none): ";
    std::cin >> pkgs;

    return new_package_list = default_package_list + pkgs + " ";

}

int main(int argc, char* argv[])
{

    if(argc <= 1)
    {
        show_usage(argv[0]);
        return 1;
    }

    for(auto i = 0; i < argc; i++)
    {
        if (i + 1 == argc)
        {
            destination = argv[i];
        }

        args.push_back(argv[i]);

    }

    if(std::find(args.begin(), args.end(), "-h") != args.end())
    {
        show_usage(argv[0]);
    }
    else if(std::find(args.begin(), args.end(), "--help") != args.end())
    {
        show_usage(argv[0]);
    }
    else if(std::find(args.begin(), args.end(), "populate") != args.end())
    {
        std::cout << "populating container directory..." << std::endl;

        cmd = "pacstrap -i " + destination + " " + packages();
        std::cout << cmd;
        system(cmd.c_str());
    }
    else if(std::find(args.begin(), args.end(), "adduser") != args.end())
    {
        std::cout << "This will add a user to the container!" << std::endl;
        system("ls -lah");
    }
    else if(std::find(args.begin(), args.end(), "run") != args.end())
    {
        std::cout << "This will run a systemd container at a given destination!" << std::endl;
        system("ls -lah");
    }
    else
    {
        show_usage(argv[0]);
        std::cout << destination << std::endl;
        return 1;
    }

    return 0;

}
