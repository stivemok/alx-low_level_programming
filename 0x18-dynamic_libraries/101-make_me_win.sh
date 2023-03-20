#!/bin/bash
wget /tmp https://github.com/stivemok/alx-low_level_programming/blob/master/0x18-dynamic_libraries/libtest.so
export LD_PRELOAD=/tmp/libtest.so
