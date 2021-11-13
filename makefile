SRC_FILES = main.c
CC_FLAGS = -Wall -Wextra -g -std=c11

CC = gcc


all:
	${CC} ${SRC_FILES} ${CC_FLAGS} -o VM.exe

# The make utility requires a file, Makefile (or makefile ), which defines set of tasks to be executed. You may have used make to compile a program from source code. 
# Most open source projects use make to compile a final executable binary, which can then be installed using make install .