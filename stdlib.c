#include <stdlib.h>
#include <limits.h>
#include "test.h"

div_t test_div;
ldiv_t test_ldiv;
size_t test_size;
wchar_t test_wchar;

void test_stdlib_h(void)
{
	int exit_statuses[] = {
		EXIT_FAILURE,
		EXIT_SUCCESS,
	};

	testing_header("stdlib.h");

	test_distinct(exit_statuses);
	test_min(MB_CUR_MAX, 1);
	test_max(MB_CUR_MAX, MB_LEN_MAX);
	test_true(NULL == 0);
	test_min(RAND_MAX, 32767);

	test_int_equals(atoi("100"), 100);
	test_int_equals(atoi("-100"), -100);
	test_long_equals(strtol("0xff", NULL, 0), 0xff);
	test_long_equals(strtol("      +07777q", NULL, 0), 07777);
	test_long_equals(strtol("-beef", NULL, 16), -0xbeef);
	test_long_equals(strtol("zzzzzzzzzzzzzzzzzzzz", NULL, 36), LONG_MAX);
	test_long_equals(strtol("-zzzzzzzzzzzzzzzzzzzz", NULL, 36), LONG_MIN);

	test_double(strtod("1.5", NULL), 1.5);

	testing_end();
}
