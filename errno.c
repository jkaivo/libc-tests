#include <errno.h>
#include "test.h"

#ifndef EDOM
#error EDOM not defined
#endif

#ifndef ERANGE
#error ERANGE not defined
#endif

#if __STDC_VERSION__ >= 199409
#ifndef EILSEQ
#error EILSEQ not defined
#endif
#endif

void test_errno_h(void)
{
	struct lconv *lc;
	int errno_values[] = {
		EDOM,
		ERANGE,
		#ifdef EILSEQ
		EILSEQ,
		#endif
	};

	testing_header("errno.h");

	test_distinct(errno_values);

	testing_end();
}
