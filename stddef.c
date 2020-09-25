#include <stddef.h>
#include "test.h"

struct s {
	char a;
	char b;
};

ptrdiff_t test_ptrdiff;
size_t test_size;
wchar_t test_wchar;

void test_stddef_h(void)
{
	static struct s the_s;

	testing_header("stddef.h");

	test_true(NULL == 0);

	test_int_equals(offsetof(struct s, b), (char*)&(the_s.b) - (char*)&the_s);

	testing_end();
}
