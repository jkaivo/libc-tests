#include <limits.h>
#include "test.h"

void test_limits_h(void)
{
	testing_header("limits.h");

	test_min(CHAR_BIT, 8);

	test_min(SCHAR_MIN, -127);
	test_min(SCHAR_MAX, 127);

	test_min(UCHAR_MAX, 255);
	test_true(CHAR_MIN == SCHAR_MIN || CHAR_MIN == 0);
	test_true(CHAR_MAX == UCHAR_MAX || CHAR_MAX == SCHAR_MAX);

	test_min(MB_LEN_MAX, 1);

	test_min(SHRT_MIN, -32767);
	test_min(SHRT_MAX, 32767);
	test_min(USHRT_MAX, 65535u);

	test_min(INT_MIN, -32767);
	test_min(INT_MAX, 32767);
	test_min(UINT_MAX, 65535u);

	test_min(LONG_MIN, -2147483647l);
	test_min(LONG_MAX, 2147483647l);
	test_min(ULONG_MAX, 4294967295ul);

	#if defined __STDC_VERSION__ && 199901L <= __STDC_VERSION__
	test_min(LLONG_MIN, -9223372036854775807ll);
	test_min(LLONG_MAX, 9223372036854775807ll);
	test_min(ULLONG_MAX, 18446744073709551615ull);
	#endif


	testing_end();
}
