#include "test.h"
#include <stdio.h>
#include <ctype.h>
#include <limits.h>

#define UPPER "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWER "abcdefghijklmnopqrstuvwxyz"
#define DIGIT "0123456789"
#define HEX   DIGIT "ABCDEFabcdef"
#define CNTRL "\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f" \
              "\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f\x7f"
#define PUNCT "`~!@#$%^&*()_+-=[]\\{}|;':\",./<>?"
#define GRAPH UPPER LOWER DIGIT PUNCT
#define PRINT GRAPH " "
#define SPACE " \f\n\r\t\v"

#define test_ctype_function(fn, ex) test_ctype_function_imp(#fn, fn, ex, sizeof(ex))
#define test_ctype_conversion(fn, from, to) test_ctype_conversion_imp(#fn, fn, from, to)

static int is_expected(int n, const char *expected, size_t len)
{
	size_t i;
	for (i = 0; i < len - 1; i++) {
		if (expected[i] == n) {
			return 1;
		}
	}
	return 0;
}

static void test_ctype_function_imp(const char *fnname, int (*fn)(int), const char *expected, size_t len)
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

static int convert(const char *from, const char *to, int n)
{
	size_t i;
	for (i = 0; from[i] != '\0'; i++) {
		if (from[i] == n) {
			return to[i];
		}
	}
	return n;
}

static void test_ctype_conversion_imp(const char *fnname, int (*fn)(int), const char *from, const char *to)
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

void test_ctype(void)
{
	testing_header("ctype.h");
	test_ctype_function(isalnum, UPPER LOWER DIGIT);
	test_ctype_function(isalpha, UPPER LOWER);
	test_ctype_function(iscntrl, CNTRL);
	test_ctype_function(isdigit, DIGIT);
	test_ctype_function(isgraph, GRAPH);
	test_ctype_function(islower, LOWER);
	test_ctype_function(isprint, PRINT);
	test_ctype_function(ispunct, PUNCT);
	test_ctype_function(isspace, SPACE);
	test_ctype_function(isupper, UPPER);
	test_ctype_function(isxdigit, HEX);

	test_ctype_conversion(tolower, UPPER, LOWER);
	test_ctype_conversion(toupper, LOWER, UPPER);
}
