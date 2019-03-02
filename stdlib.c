#include <stdlib.h>
#include <limits.h>
#include "test.h"

void test_stdlib_h(void)
{
	div_t div;
	ldiv_t ldiv;
	size_t size;
	wchar_t wchar;

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

	testing_end();
}
