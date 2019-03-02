#if defined __STDC_VERSION__ && 199901L <= __STDC_VERSION__
#include <stdbool.h>
#include "test.h"

void test_stdbool_h(void)
{
	bool b;

	testing_header("stdbool.h");

	test_true(true);
	test_false(false);
	test_true(__bool_true_false_are_defined);

	testing_end();
}

#else
void test_stdbool_h(void)
{
}
#endif
