#!/bin/bash
wget -O /tmp/libtest.so https://github.com/stivemok/alx-low_level_programming/raw/master/0x18-dynamic_libraries/libtest.so
export LD_PRELOAD=/tmp/libtest.so
