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

static struct {
	char *name;
	void (*fn)(void);
	int run;
} tests[] = {
	{ "assert",	test_assert_h,		0 },
	{ "complex",	test_complex_h,		1 },
	{ "ctype",	test_ctype_h,		1 },
	{ "errno",	test_errno_h,		1 },
	{ "fenv",	test_fenv_h,		1 },
	{ "float",	test_float_h,		1 },
	{ "inttypes",	test_inttypes_h,	1 },
	{ "iso646",	test_iso646_h,		1 },
	{ "limits",	test_limits_h,		1 },
	{ "locale",	test_locale_h,		1 },
	{ "math",	test_math_h,		1 },
	{ "setjmp",	test_setjmp_h,		1 },
	{ "signal",	test_signal_h,		1 },
	{ "stdalign",	test_stdalign_h,	1 },
	{ "stdarg",	test_stdarg_h,		1 },
	{ "stdatomic",	test_stdatomic_h,	1 },
	{ "stdbool",	test_stdbool_h,		1 },
	{ "stddef",	test_stddef_h,		1 },
	{ "stdint",	test_stdint_h,		1 },
	{ "stdio",	test_stdio_h,		1 },
	{ "stdlib",	test_stdlib_h,		1 },
	{ "stdnoreturn",test_stdnoreturn_h,	1 },
	{ "string",	test_string_h,		1 },
	{ "tgmath",	test_tgmath_h,		1 },
	{ "threads",	test_threads_h,		1 },
	{ "time",	test_time_h,		1 },
	{ "uchar",	test_uchar_h,		1 },
	{ "wchar",	test_wchar_h,		1 },
	{ "wctype",	test_wctype_h,		1 },
};

void show_tests(void)
{
	size_t i;
	printf("Valid tests: %s", tests[0].name);
	for (i = 1; i < sizeof(tests) / sizeof(tests[0]); i++) {
		printf(", %s", tests[i].name);
	}
	printf("\n");
}

void usage(const char *argv0)
{
	printf("Usage: %s [-v] [test...]\n", argv0);
	show_tests();
}

int main(int argc, char *argv[])
{
	int torun = 1;
	int i, j;

	for (i = 1; i < argc; i++) {
		int ok = 0;

		if (!strcmp("-v", argv[i])) {
			verbose = 1;
			ok = 1;
		}

		for (j = 0; j < sizeof(tests) / sizeof(tests[0]); j++) {
			if (!strcmp(tests[j].name, argv[i])) {
				torun = 2;
				tests[j].run = 2;
				ok = 1;
			}
		}

		if (!ok) {
			usage(argv[0]);
			return 1;
		}
	}

	if (argc == 2) {
		if (!strcmp(argv[1], "assert")) {
			test_assert_h();
		}
	}

	for (i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
		if (tests[i].run == torun) {
			tests[i].fn();
		}
	}

	printf("Total: %u passed, %u failed\n", total_passed, total_failed);
	return 0;
}
