//
// Created by nickobelic1999 on 3/6/23.
//

#pragma once

#include "common.hpp"

namespace Arch_Utils
{

    class Btrfs_Utils
    {
    public:

        void SetState(std::string state);
        std::string GetState();

        void SetPath(const char* path);
        std::string GetPath();

        void SetFileDescriptor(size_t fd);
        size_t GetFileDescriptor();

        void OpenFileSystem(const char* path);

        void CreateBtrfsSubvolume(const char* name);
        void DeleteBtrfsSubvolume(const char* name);

        void CloseBtrfsSubvolume(size_t fd);

        Btrfs_Utils();
        ~Btrfs_Utils();
    private:

        struct btrfs_ioctl_vol_args _btrfs_args;

        size_t _file_descriptor;
        std::string _path;
        std::string _state;

        Error_Handler _error;


    };

} // arch_utils

