#if defined __STDC_VERSION__
#include <stdio.h>
#include <limits.h>
#include <wctype.h>
#include "_wctype.h"
#include "test.h"

wint_t test_wint;
wctrans_t test_wctrans;
wctype_t test_wctype;

#define UPPER L"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWER L"abcdefghijklmnopqrstuvwxyz"
#define DIGIT L"0123456789"
#define HEX   DIGIT L"ABCDEFabcdef"
#define CNTRL L"\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f" \
              L"\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f\x7f"
#define PUNCT L"`~!@#$%^&*()_+-=[]\\{}|;':\",./<>?"
#define GRAPH UPPER LOWER DIGIT PUNCT
#define PRINT GRAPH " "
#define SPACE L" \f\n\r\t\v"

#define test_ctype_function(fn, ex) test_ctype_function_imp(#fn, fn, ex, sizeof(ex))
#define test_ctype_conversion(fn, from, to) test_ctype_conversion_imp(#fn, fn, from, to)

static int is_expected(int n, const wchar_t *expected, size_t len)
{
	size_t i;
	for (i = 0; i < len - 1; i++) {
		if (expected[i] == n) {
			return 1;
		}
	}
	return 0;
}

static void test_ctype_function_imp(const char *fnname, int (*fn)(int), const wchar_t *expected, size_t len)
{
	char expression[64];
	int i;
	for (i = 0; i < UCHAR_MAX; i++) {
		sprintf(expression, "%s(%d)", fnname, i);
		test_bool_imp(expression, fn(i), is_expected(i, expected, len));
	}
	sprintf(expression, "%s(EOF)", fnname);
	test_bool_imp(expression, fn(EOF), 0);
}

static int convert(const wchar_t *from, const wchar_t *to, int n)
{
	size_t i;
	for (i = 0; from[i] != '\0'; i++) {
		if (from[i] == n) {
			return to[i];
		}
	}
	return n;
}

static void test_ctype_conversion_imp(const char *fnname, int (*fn)(int), const wchar_t *from, const wchar_t *to)
{
	char expression[64];
	int i;
	for (i = 0; i < UCHAR_MAX; i++) {
		int j = convert(from, to, i);
		sprintf(expression, "%s(%d)", fnname, i);
		test_int_equals_imp(expression, fn(i), j);
	}
	sprintf(expression, "%s(EOF)", fnname);
	test_int_equals_imp(expression, fn(EOF), EOF);
}

void test_wctype_h(void)
{
	testing_header("wctype.h");

	test_ctype_function(iswalnum, UPPER LOWER DIGIT);
	test_ctype_function(iswalpha, UPPER LOWER);
	test_ctype_function(iswcntrl, CNTRL);
	test_ctype_function(iswdigit, DIGIT);
	test_ctype_function(iswgraph, GRAPH);
	test_ctype_function(iswlower, LOWER);
	test_ctype_function(iswprint, PRINT);
	test_ctype_function(iswpunct, PUNCT);
	test_ctype_function(iswspace, SPACE);
	test_ctype_function(iswupper, UPPER);
	test_ctype_function(iswxdigit, HEX);

	/* TODO: wctype() */
	/* TODO: iswctype() */

	test_ctype_conversion(towlower, UPPER, LOWER);
	test_ctype_conversion(towupper, LOWER, UPPER);

	/* TODO: wctrans() */
	/* TODO: towctrans() */

	testing_end();
}

#else
void test_wctype_h(void)
{
}
#endif

