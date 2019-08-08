#if defined __STDC_VERSION__ && 201112L <= __STDC_VERSION__
#include <stdalign.h>
#include "_stdalign.h"
#include "test.h"

void test_stdalign_h(void)
{
	testing_header("stdalign.h");

	/* alignas() */
	/* alignof() */

	test_int_equals(__alignas_is_defined, 1);
	test_int_equals(__alignof_is_defined, 1);

	testing_end();
}

#else
void test_stdalign_h(void)
{
}
#endif
