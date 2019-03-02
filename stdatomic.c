#if defined __STDC_VERSION__ && 201112L <= __STDC_VERSION__ && ! defined __STDC_NO_ATOMICS__
#include <stdatomic.h>
#include "test.h"

void test_stdatomic_h(void)
{
	testing_header("stdatomic.h");

	/* TODO */

	testing_end();
}

#else
void test_stdatomic_h(void)
{
}
#endif
