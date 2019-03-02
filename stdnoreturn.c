#if defined __STDC_VERSION__ && 201112L <= __STDC_VERSION__
#include <stdnoreturn.h>
#include "test.h"

noreturn void foo(void)
{
	for (;;);
}

void test_stdnoreturn_h(void)
{
	testing_header(".h");

	/* tested by the fact that this compiles */

	testing_end();
}

#else
void test_stdnoreturn_h(void)
{
}
#endif
