#include <string.h>
#include <stdio.h>
#include "test.h"

void test_assert_h(void);
void test_complex_h(void);
void test_ctype_h(void);
void test_errno_h(void);
void test_fenv_h(void);
void test_float_h(void);
void test_inttypes_h(void);
void test_iso646_h(void);
void test_limits_h(void);
void test_locale_h(void);
void test_math_h(void);
void test_setjmp_h(void);
void test_signal_h(void);
void test_stdalign_h(void);
void test_stdarg_h(void);
void test_stdatomic_h(void);
void test_stdbool_h(void);
void test_stddef_h(void);
void test_stdint_h(void);
void test_stdio_h(void);
void test_stdlib_h(void);
void test_stdnoreturn_h(void);
void test_string_h(void);
void test_tgmath_h(void);
void test_threads_h(void);
void test_time_h(void);
void test_uchar_h(void);
void test_wchar_h(void);
void test_wctype_h(void);

int main(int argc, char *argv[])
{
	if (argc == 2) {
		if (!strcmp(argv[1], "assert")) {
			test_assert_h();
		}
	}

	/* test_complex_h(); */
	test_ctype_h();
	test_errno_h();
	/* test_fenv_h(); */
	test_float_h();
	/* test_inttypes_h(); */
	test_iso646_h();
	test_limits_h();
	test_locale_h();
	/* test_math_h(); */
	/* test_setjmp_h(); */
	test_signal_h();
	/* test_stdalign_h(); */
	/* test_stdarg_h(); */
	/* test_stdatomic_h(); */
	test_stdbool_h();
	test_stddef_h();
	/* test_stdint_h(); */
	/* test_stdio_h(); */
	/* test_stdlib_h(); */
	/* test_stdnoreturn_h(); */
	/* test_string_h(); */
	/* test_tgmath_h(); */
	/* test_threads_h(); */
	test_time_h();
	/* test_uchar_h(); */
	/* test_wchar_h(); */
	/* test_wctype_h(); */

	printf("Total: %u passed, %u failed\n", total_passed, total_failed);
	return 0;
}
