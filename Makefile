.POSIX:

include config.mk

CFLAGS=-g -I$(INCLUDEDIR) -nostdinc -fno-builtin
LDFLAGS=-L$(LIBDIR) $(LIBS)

TESTOBJS=main.o test.o assert.o ctype.o locale.o

testlibc: $(TESTOBJS) $(LIBDIR)/libc.a
	$(CC) -o $@ $(TESTOBJS) $(LDFLAGS)

assert.o: assert.c test.h

ctype.o: ctype.c test.h

locale.o: locale.c test.h

test.o: test.c test.h

main.o: main.c test.h

clean:
	rm -f *.o testlibc
