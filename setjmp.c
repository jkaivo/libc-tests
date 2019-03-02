#include <setjmp.h>
#include "test.h"

void test_setjmp_h(void)
{
	jmp_buf jb;
	int r;
	int expected = 0;

	testing_header("setjmp.h");

	r = setjmp(jb);
	test_int_equals(r, expected);

	if (r == 0) {
		expected = 1;
		longjmp(jb, 1);
	}

	testing_end();
}
