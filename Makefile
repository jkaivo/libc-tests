.POSIX:

.SUFFIXES: .h .d

include config.mk

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

testlibc: $(TESTOBJS)
	$(CC) -o $@ $(TESTOBJS) $(LDFLAGS)

$(TESTOBJS): test.h
float.o: _float.h
math.o: _math.h
stdalign.o: _stdalign.h
stdio.o: _stdio.h
stdnoreturn.o: _stdnoreturn.h
wchar.o: _wchar.h
wctype.o: _wctype.h

test.o: test.h
main.o: test.h

.d.h:
	awk '{printf("#ifndef %s\n#error %s not defined\n#endif\n", $$0, $$0);}' $< > $@

clean:
	rm -f *.o testlibc
