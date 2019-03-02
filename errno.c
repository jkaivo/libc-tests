#include <errno.h>
#include "test.h"

void test_errno_h(void)
{
	int errno_values[] = {
		EDOM,
		ERANGE,
		#if defined __STDC_VERSION__
		EILSEQ,
		#endif
	};

	testing_header("errno.h");

	test_distinct(errno_values);

	testing_end();
}
