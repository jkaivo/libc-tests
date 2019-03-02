#if defined __STDC_VERSION__ && 199901L <= __STDC_VERSION__
#include <tgmath.h>
#include "test.h"

void test_tgmath_h(void)
{
	testing_header("tgmath.h");

	/* I'm not really sure how to test this accurately in C alone */

	testing_end();
}

#else
void test_tgmath_h(void)
{
}
#endif
