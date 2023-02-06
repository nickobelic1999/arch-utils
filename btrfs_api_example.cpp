#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/btrfs.h>
#include <btrfsutil.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#include "arch_util_common.hpp"

int main(int argc, char* argv[])
{
  auto ret = 0;
  struct btrfs_ioctl_vol_args btrfs_args;

  // Load in arguments
  std::vector<std::string> input_args;
  for (auto i = 1; i < argc; ++i)
  {
    input_args.push_back(argv[i]);
  }

  // Check for arguments
  if (input_args.empty()) {
    std::cout << "You need to provide at least 1 argument!\n";
    return 1;
  }

  // Open the Btrfs filesystem containing the subvolumes
  auto fd = open("/Volumes/dataStore", O_RDONLY | O_DIRECTORY);
  if (fd == -1)
  {
    std::cerr << "Error: failed to open Btrfs filesystem" << std::endl;
    return 1;
  }

  if(std::find(input_args.begin(), input_args.end(), "-h") != input_args.end())
  {
    //show_usage(argv[0]);
    return 0;
  }
  else if(std::find(input_args.begin(), input_args.end(), "-h") != input_args.end())
  {
    //show_usage(argv[0])
    return 0;
  }
  else if(std::find(input_args.begin(), input_args.end(), "create") != input_args.end())
  {
    // Create a subvolume
    //struct btrfs_ioctl_vol_args btrfs_args;
    memset(&btrfs_args, 0, sizeof(btrfs_args));
    strcpy(btrfs_args.name, "@test_vol");
    ret = ioctl(fd, BTRFS_IOC_SUBVOL_CREATE, &btrfs_args);
    if (ret == -1)
    {
      std::cerr << "Error: failed to create subvolume" << std::endl;
      return 1;
    }

    return 0;

  }
  else
  {
    // Delete a subvolume
    memset(&btrfs_args, 0, sizeof(btrfs_args));
    strcpy(btrfs_args.name, "@test_vol");
    ret = ioctl(fd, BTRFS_IOC_SNAP_DESTROY, &btrfs_args);
    if (ret == -1)
    {
      std::cerr << "Error: failed to delete subvolume" << std::endl;
      return 1;
    }

    return 0;

  }

  // Close the Btrfs filesystem
  close(fd);
  return 0;
}
