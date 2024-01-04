#!/bin/sh
clear
set -ex
output="main.out"
flags="-std=c11 -lm -ldl -Wall -Wextra -Wpedantic -Werror -g"
# flags="-std=c11 -lm -Wall -Wextra -Wpedantic -Werror -Ofast"
gcc main.c $flags -o $output
