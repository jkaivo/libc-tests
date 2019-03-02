#if defined __STDC_VERSION__ && 199901L <= __STDC_VERSION__
#include <stdint.h>
#include "test.h"

void test_stdint_h(void)
{
	intptr_t intptr;
	uintptr_t uintptr;
	intmax_t intmax;
	uintmax_t uintmax;

	testing_header("inttypes.h");

	test_min(INTPTR_MIN, 0);
	test_min(INTPTR_MAX, 0);
	test_min(UINTPTR_MAX, 0);

	test_min(INTMAX_MIN, 0);
	test_min(INTMAX_MAX, 0);
	test_min(UINTMAX_MAX, 0);

	test_min(PTRDIFF_MIN, 0);
	test_min(PTRDIFF_MAX, 0);
	test_min(PTRDIFF_MAX, 0);

	test_min(SIG_ATOMIC_MIN, 0);
	test_min(SIG_ATOMIC_MAX, 0);

	test_min(SIZE_MAX, 0);

	test_min(WCHAR_MIN, 0);
	test_min(WCHAR_MAX, 0);

	test_min(WINT_MIN, 0);
	test_min(WINT_MAX, 0);

	testing_end();
}

#else
void test_stdint_h(void)
{
}
#endif
