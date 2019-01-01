CC=c89
CFLAGS=-Wall -Wextra -Wpedantic

testlibc: main.o test.o assert.o ctype.o locale.o
	$(CC) -o $@ *.o

assert.o: assert.c test.h

ctype.o: ctype.c test.h

locale.o: locale.c test.h

test.o: test.c test.h

main.o: main.c test.h

clean:
	rm -f *.o testlibc
