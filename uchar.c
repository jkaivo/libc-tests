#if defined __STDC_VERSION__ && 201112L <= __STDC_VERSION__
#include <uchar.h>
#include "test.h"

void test_uchar_h(void)
{
	mbstate_t mbstate;
	size_t size;
	char16_t char16;
	char32_t char32;

	testing_header("uchar.h");

	/* TODO */

	testing_end();
}

#else
void test_uchar_h(void)
{
}
#endif
