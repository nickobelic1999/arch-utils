#include <system_error>
#include <filesystem>
#include <iostream>

int main(int argc, char* argv[])
{
    const std::filesystem::path from{argv[1]}, to{argv[2]};

    if(argc <= 1)
    {
        std::cerr << "no file paths were provided!" << std::endl;
        return -1;
    }

    try
    {
        std::filesystem::copy_file(from, to);
    }
    catch(std::filesystem::filesystem_error const& e)
    {
        std::cout
            << "what():  " << e.what() << '\n'
            << "path1(): " << e.path1() << '\n'
            << "path2(): " << e.path2() << '\n'
            << "code().value():    " << e.code().value() << '\n'
            << "code().message():  " << e.code().message() << '\n'
            << "code().category(): " << e.code().category().name() << '\n';
    }
 
    std::error_code err;
    std::filesystem::copy_file(from, to, err);
    std::cout << "\nerror_code has non-throwing sets: " << err.message() << '\n';
}
