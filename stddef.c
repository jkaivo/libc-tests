#include <stddef.h>
#include "test.h"

struct s {
	char a;
	char b;
};

void test_stddef_h(void)
{
	ptrdiff_t ptrdiff;
	size_t size;
	wchar_t wchar;

	static struct s the_s;

	(void)ptrdiff;
	(void)size;
	(void)wchar;

	testing_header("stddef.h");

	test_true(NULL == 0);

	test_int_equals(offsetof(struct s, b), (char*)&(the_s.b) - (char*)&the_s);

	testing_end();
}
