@echo off

gcc -c ./src/test/main.c -I ./include
gcc -o ./bin/sha512.exe main.o -L ./lib -lsha512
gcc -o ./bin/_sha512.exe main.o -L ./lib -lsha512lib

del *.o