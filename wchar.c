#if defined __STDC_VERSION__
#include <wchar.h>
#include "_wchar.h"
#include "test.h"

wchar_t test_wchar;
size_t test_size;
mbstate_t test_mbstate;
wint_t test_wint;
struct tm *test_tm;

void test_wchar_h(void)
{
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
