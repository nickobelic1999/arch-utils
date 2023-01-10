#include "arch_util_common.hpp"

std::vector <std::string> args;
std::string destination;

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
    else if(std::find(args.begin(), args.end(), ""))

    return 0;
}
