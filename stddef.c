#include <stddef.h>
#include "test.h"

void test_stddef_h(void)
{
	ptrdiff_t ptrdiff;
	size_t size;
	wchar_t wchar;

	struct s {
		char a;
		char b;
	};

	testing_header("stddef.h");

	test_true(NULL == 0);

	/*
	test_int_eq(offsetof(struct s, b), 1);
	*/

	testing_end();
}
