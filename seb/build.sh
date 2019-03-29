#!/bin/bash -x
set -euo pipefail

mkdir -p obj bin
find src/ -name '*.c'|sed 's/^src\///'|while read src; do
	gcc -O2 -g3 -Wall -Werror -pedantic -ansi -std=c99 -Iinclude src/${src} -c -o obj/${src/.c/.o};
done;
gcc -O2 -g3 -Wall -Werror -pedantic -ansi -std=c99 -Iinclude main.c -c -o obj/main.o;

gcc -O2 -g3 obj/*.o -o bin/checker

