#if defined __STDC_VERSION__ && 199901L <= __STDC_VERSION__
#include <wchar.h>
#include <inttypes.h>
#include "test.h"

void test_inttypes_h(void)
{
	imaxdiv_t imaxdiv;
	char *endptr;

	testing_header("inttypes.h");

	test_true(imaxabs(-1) == 1);

	intmax_t im = strtoimax("100000000q", &endptr, 0);
	test_true(im == 100000000);
	test_true(*endptr == 'q');

	testing_end();
}

#else
void test_inttypes_h(void)
{
}
#endif
