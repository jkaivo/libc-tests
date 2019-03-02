#if defined __STDC_VERSION__ && 201112L <= __STDC_VERSION__
#include <stdalign.h>
#include "test.h"

void test_stdalign_h(void)
{
	testing_header("stdalign.h");

	/* alignas() */
	/* alignof() */

	test_defined(__alignas_is_defined);
	test_defined(__alignof_is_defined);

	testing_end();
}

#else
void test_stdalign_h(void)
{
}
#endif
