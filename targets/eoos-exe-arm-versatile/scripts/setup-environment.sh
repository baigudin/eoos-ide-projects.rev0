#!/bin/sh
#
# This script setup enviroment for Linux to build the project.
#
# SDIR: .
# EDIR: .
source ./functions.sh

outMessage "Linaro toolchains downloading..."
wget https://releases.linaro.org/components/toolchain/binaries/7.3-2018.05/arm-eabi/gcc-linaro-7.3.1-2018.05-x86_64_arm-eabi.tar.xz

outMessage "LINARO TOOLCHAINS INSTALLING..."
sudo tar -Jxvf gcc-linaro-7.3.1-2018.05-x86_64_arm-eabi.tar.xz -C /opt
