#if defined __STDC_VERSION__
#include <wchar.h>
#include "test.h"

void test_wchar_h(void)
{
	wchar_t wchar;
	size_t size;
	mbstate_t mbstate;
	wint_t wint;
	struct tm *tm;

	testing_header("wchar.h");

	test_true(NULL == 0);
	test_min(WCHAR_MIN, 0);
	test_min(WCHAR_MAX, 0);
	test_defined(WEOF);

	testing_end();
}

#else
void test_wchar_h(void)
{
}
#endif
