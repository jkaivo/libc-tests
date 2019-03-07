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

	static struct s the_s;

	testing_header("stddef.h");

	test_true(NULL == 0);

	test_int_equals(offsetof(struct s, b), (char*)&(the_s.b) - (char*)&the_s);

	testing_end();
}
