.POSIX:

include config.mk

CC=c99
CFLAGS=-g -I$(INCLUDEDIR) -nostdinc -fno-builtin
LDFLAGS=-L$(LIBDIR) $(LIBS)

TESTOBJS=main.o \
	assert.o \
	complex.o \
	ctype.o \
	errno.o \
	fenv.o \
	float.o \
	inttypes.o \
	iso646.o \
	limits.o \
	locale.o \
	math.o \
	setjmp.o \
	signal.o \
	stdalign.o \
	stdarg.o \
	stdatomic.o \
	stdbool.o \
	stddef.o \
	stdint.o \
	stdio.o \
	stdlib.o \
	stdnoreturn.o \
	string.o \
	tgmath.o \
	threads.o \
	time.o \
	uchar.o \
	wchar.o \
	wctype.o \
	test.o

testlibc: $(TESTOBJS) $(LIBDIR)/libc.a
	$(CC) -o $@ $(TESTOBJS) $(LDFLAGS)

assert.o: assert.c test.h
complex.o: complex.c test.h
ctype.o: ctype.c test.h
errno.o: errno.c test.h
fenv.o: fenv.c test.h
float.o: float.c test.h
inttypes.o: inttypes.c test.h
iso646.o: iso646.c test.h
limits.o: limits.c test.h
locale.o: locale.c test.h
math.o: math.c test.h
setjmp.o: setjmp.c test.h
signal.o: signal.c test.h
stdalign.o: stdalign.c test.h
stdard.o: stdarg.c test.h
stdatomic.o: stdatomic.c test.h
stdbool.o: stdbool.c test.h
stddef.o: stddef.c test.h
stdint.o: stdint.c test.h
stdio.o: stdio.c test.h
stdlib.o: stdlib.c test.h
stdnoreturn.o: stdnoreturn.c test.h
string.o: string.c test.h
tgmath.o: tgmath.c test.h
threads.o: threads.c test.h
time.o: time.c test.h
uchar.o: uchar.c test.h
wchar.o: wchar.c test.h
wctype.o: wctype.c test.h

test.o: test.c test.h
main.o: main.c test.h

clean:
	rm -f *.o testlibc
