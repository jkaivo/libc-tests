#if defined __STDC_VERSION__ && 199901L <= __STDC_VERSION__
#include <stdint.h>
#include "test.h"

void test_stdint_h(void)
{
	intptr_t intptr;
	uintptr_t uintptr;
	intmax_t intmax;
	uintmax_t uintmax;

	testing_header("stdint.h");

	test_min(INTPTR_MIN, -32767);
	test_min(INTPTR_MAX, 32767);
	test_min(UINTPTR_MAX, 65535);

	test_min(INTMAX_MIN, -9223372036854775807LL);
	test_min(INTMAX_MAX, 9223372036854775807LL);
	test_min(UINTMAX_MAX, 18446744073709551615ULL);

	test_min(PTRDIFF_MIN, -65535);
	test_min(PTRDIFF_MAX, 65535);

	if (SIG_ATOMIC_MIN == 0) {
		test_min(SIG_ATOMIC_MAX, 255);
	} else {
		test_min(SIG_ATOMIC_MIN, -127);
		test_min(SIG_ATOMIC_MAX, 127);
	}

	test_min(SIZE_MAX, 65535);

	if (WCHAR_MIN == 0) {
		test_min(WCHAR_MAX, 255);
	} else {
		test_min(WCHAR_MIN, -127);
		test_min(WCHAR_MAX, 127);
	}

	if (WINT_MIN == 0) {
		test_min(WINT_MAX, 65535);
	} else {
		test_min(WINT_MIN, 0);
		test_min(WINT_MAX, 0);
	}

	testing_end();
}

#else
void test_stdint_h(void)
{
}
#endif
