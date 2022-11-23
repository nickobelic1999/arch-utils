#!/bin/zsh

export o=defaults,x-mount.mkdir
export o_btrfs=$o,compress=lzo,ssd,noatime

export VOL_PATH=$1
export VOL_NAME=$2

btrfs subvolume create $1/$2
