#!/bin/sh
gcc -Wall -Wextra -Wpedantic -Werror -fpic -shared -rdynamic -o borklib.so borklib.c -ldl
