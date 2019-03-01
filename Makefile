.POSIX:

include config.mk

CFLAGS=-g -I$(INCLUDEDIR) -nostdinc -fno-builtin
LDFLAGS=-L$(LIBDIR) $(LIBS)

TESTOBJS=main.o test.o assert.o ctype.o locale.o errno.o time.o signal.o

.SUFFIXES: .defs .d

.defs.d:
	awk -f defs2d.awk $< > $@

testlibc: $(TESTOBJS) $(LIBDIR)/libc.a
	$(CC) -o $@ $(TESTOBJS) $(LDFLAGS)

assert.o: assert.c test.h
ctype.o: ctype.c test.h
locale.o: locale.c locale.d test.h
errno.o: errno.c test.h
time.o: time.c test.h
signal.o: signal.c signal.d test.h
test.o: test.c test.h
main.o: main.c test.h

clean:
	rm -f *.o testlibc
