#!/bin/zsh

ACTION=$1

case $ACTION in

  populate)
    sudo pacstrap -i $2 base base-devel zsh grml-zsh-config openssh nano wget git btrfs-progs
    ;;

  useradd)
    #Chroot into container
    sudo chroot $2 /bin/zsh << EOT
    #Add user admin and set initial password to admin
    useradd -m -G wheel,storage,power,users,input -s /bin/zsh $3
    echo -e "$3\n$3" | passwd $3
    #Make user admin a sudoer
    echo $3" ALL=(ALL:ALL) ALL" >> /etc/sudoers
EOT
    ;;
  adduser)
    #Chroot into container
    sudo chroot $2 /bin/zsh << EOT
    #Add user admin and set initial password to admin
    useradd -m -G wheel,storage,power,users,input -s /bin/zsh $3
    echo -e "$3\n$3" | passwd $3
    #Make user admin a sudoer
    echo $3" ALL=(ALL:ALL) ALL" >> /etc/sudoers
EOT
    ;;

  run)
    sudo systemd-nspawn $4 -bD $2
    ;;

  *)
    echo "Error unknown command!"
    ;;
esac
