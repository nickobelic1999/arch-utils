//
// Created by nickobelic1999 on 3/6/23.
//

#include "btrfsUtils.hpp"

using namespace Arch_Utils;

void Btrfs_Utils::SetState(std::string state)
{
    _state =  state;
}

std::string Btrfs_Utils::GetState()
{
    return _state;
}

void Btrfs_Utils::SetPath(const char* path)
{
    _path = path;
}

std::string Btrfs_Utils::GetPath()
{
    return _path;
}

void Btrfs_Utils::SetFileDescriptor(size_t fd)
{
    _file_descriptor = fd;
}

size_t Btrfs_Utils::GetFileDescriptor()
{
    return _file_descriptor;
}


void Btrfs_Utils::OpenFileSystem(const char* path)
{

    // Open the Btrfs filesystem containing the subvolumes
    _file_descriptor = open(path, O_RDONLY | O_DIRECTORY);
    if (_file_descriptor == -1)
    {
        _error.SetErrorMsg("Error: failed to open Btrfs filesystem");
        _error.SetErrorCode(-1);
        _error.OnExit();
    }

}

void Btrfs_Utils::CreateBtrfsSubvolume(const char* name)
{

    // Create a subvolume
    memset(&_btrfs_args, 0, sizeof(_btrfs_args));
    strcpy(_btrfs_args.name, name);
    auto ret = ioctl(_file_descriptor, BTRFS_IOC_SUBVOL_CREATE, &_btrfs_args);
    if (ret == -1)
    {
        _error.SetErrorMsg("Error: failed to create subvolume");
        _error.SetErrorCode(-1);
        _error.OnExit();
    }

    CloseBtrfsSubvolume(_file_descriptor);
}

void Btrfs_Utils::DeleteBtrfsSubvolume(const char* name)
{

    // Delete a subvolume
    memset(&_btrfs_args, 0, sizeof(_btrfs_args));
    strcpy(_btrfs_args.name, name);
    auto ret = ioctl(_file_descriptor, BTRFS_IOC_SNAP_DESTROY, &_btrfs_args);
    if (ret == -1)
    {
        _error.SetErrorMsg("Error: failed to delete subvolume");
        _error.SetErrorCode(-1);
        _error.OnExit();
    }

    CloseBtrfsSubvolume(_file_descriptor);
}

void Btrfs_Utils::CloseBtrfsSubvolume(size_t fd)
{
    close(fd);
}


Btrfs_Utils::Btrfs_Utils() {}

Btrfs_Utils::~Btrfs_Utils() {}