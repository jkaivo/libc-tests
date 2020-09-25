CC=ungol-gcc
C_VERSION=c89
#C_VERSION=iso9899:199409
#C_VERSION=c99
#C_VERSION=c11
#C_VERSION=c17
CFLAGS=-fno-builtin -g -std=$(C_VERSION) -Wall -Wextra
LDFLAGS=-lc -lm
