#if defined __STDC_VERSION__
#include <iso646.h>
#include "test.h"

void test_iso646_h(void)
{
	int i = 1;
	testing_header("iso646.h");

	test_true(i and 1);
	test_true(i and_eq 1);
	test_true(i bitand 1);
	test_true(i bitor 1);
	test_true(compl i);
	test_false(not i);
	test_true(i not_eq 0);
	test_true(0 or i);
	test_true(i or_eq 1);
	test_true(i xor 0);
	test_true(i xor_eq 0);

	testing_end();
}

#else
void test_iso646_h(void)
{
}
#endif
