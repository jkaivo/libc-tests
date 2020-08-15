#if defined __STDC_VERSION__
#include <wchar.h>
#include "_wchar.h"
#include "test.h"

void test_wchar_h(void)
{
	wchar_t wchar;
	size_t size;
	mbstate_t mbstate;
	wint_t wint;
	struct tm *tm;
	(void)wchar;
	(void)size;
	(void)mbstate;
	(void)wint;
	(void)tm;

	testing_header("wchar.h");

	test_true(NULL == 0);

	if (WCHAR_MIN == 0) {
		test_min(WCHAR_MAX, 255);
	} else {
		test_min(WCHAR_MIN, -127);
		test_min(WCHAR_MAX, 127);
	}

	testing_end();
}

#else
void test_wchar_h(void)
{
}
#endif
