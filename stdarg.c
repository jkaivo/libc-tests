#include <stdarg.h>
#include <float.h>
#include <limits.h>
#include "test.h"

typedef enum { INT, LONG, DOUBLE, LONG_DOUBLE, POINTER } type;

static void variadic(type t, ...)
{
	int i;
	long l;
	double d;
	long double ld;
	void *p;

	va_list ap;
	va_start(ap, t);

	switch (t) {
	case INT:	i = va_arg(ap, int); test_true(i == INT_MAX); break;
	case LONG:	l = va_arg(ap, long); test_true(l == LONG_MAX); break;
	case DOUBLE:	d = va_arg(ap, double); test_true(d == DBL_MAX); break;
	case LONG_DOUBLE: ld = va_arg(ap, long double); test_true(ld == LDBL_MAX); break;	
	case POINTER:	p = va_arg(ap, void *); test_true(p == 0); break;
	}

	va_end(ap);
}

void test_stdarg_h(void)
{
	testing_header("stdarg.h");

	variadic(INT, INT_MAX);
	variadic(LONG, LONG_MAX);
	/*
	variadic(DOUBLE, DBL_MAX);
	variadic(LONG_DOUBLE, LDBL_MAX);
	*/
	variadic(POINTER, 0);

	testing_end();
}
