#include <stddef.h>
#include "test.h"

static ptrdiff_t ptrdiff;
static size_t size;
static wchar_t wchar;

void test_stddef_h(void)
{
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
