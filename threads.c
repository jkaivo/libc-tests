#if defined __STDC_VERSION__ && 201112L <= __STDC_VERSION__ && ! defined __STDC_NO_THREADS__
#include <threads.h>
#include "test.h"

void test_threads_h(void)
{
	testing_header("threads.h");

	/* TODO */

	testing_end();
}

#else
void test_threads_h(void)
{
}
#endif
