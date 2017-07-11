# Compiler
CC = g++

# Compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#  -O2   Optimization level 2
CFLAGS = -Wall -g -std=c++11 -O2

# Compile covertools
covertools:
	$(CC) src/$@.cpp -o $@ $(CFLAGS)
