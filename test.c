#include <stdio.h>
#include <stdarg.h>
#include <float.h>

unsigned int total_passed = 0;
unsigned int total_failed = 0;
static int passed;
static int failed;
int verbose = 0;

typedef enum {
	DEFAULT = 39,
	RED = 31,
	GREEN = 32,
	YELLOW = 33,
	BLUE = 34,
	MAGENTA = 35
} Color;

static void set_output_color(Color c)
{
	printf("\033[%dm", c);
}

static void print_result(int success, const char *format, ...)
{
	va_list ap;
	Color color = GREEN;
	char indicator = '+';

	if (success) {
		color = GREEN;
		passed++;
	} else {
		color = RED;
		indicator = '-';
		failed++;
	}

	set_output_color(color);
	putchar(indicator);

	if (verbose) {
		putchar(' ');

		va_start(ap, format);
		vprintf(format, ap);
		va_end(ap);

		putchar(success ? '\n' : '\n');
	}
	set_output_color(DEFAULT);
}

void testing_header(const char *header)
{
	printf("Testing header ");
	set_output_color(MAGENTA);
	printf("<%s>", header);
	set_output_color(DEFAULT);
	printf("\n");
}

void testing_end(void)
{
	if (!verbose) {
		putchar('\n');
	}

	printf("%d tests passed, %d tests failed\n", passed, failed);

	total_passed += passed;
	passed = 0;

	total_failed += failed;
	failed = 0;
}

void testing_comment(const char *comment)
{
	if (verbose) {
		printf("- %s\n", comment);
	}
}

void test_int_equals_imp(const char *expression, int result, int expected)
{
	print_result(result == expected, "%s == %d", expression, expected);
}

void test_double_imp(const char *expression, double result, double expected)
{
	int success = (result - expected < DBL_EPSILON);
	print_result(success, "%s == %d", expression, (int)expected);
}

void test_void_imp(const char *expression)
{
	putchar('?');
	if (verbose) {
		printf(" %s\n", expression);
	}
}

void test_bool_imp(const char *expression, int result, int expected)
{
	int success = (result && expected) || (!result && !expected);
	print_result(success, "%s%s", expected ? "" : "!", expression);
}

void test_string_imp(const char *expression, const char *totest, const char *tocompare)
{
	int success = 1;
	int i;
	for (i = 0; totest[i] != '\0'; i++) {
		if (totest[i] != tocompare[i]) {
			success = 0;
		}
	}
	if (tocompare[i] != '\0') {
		success = 0;
	}
	print_result(success, "%s == \"%s\"", expression, tocompare);
}

void test_distinct_imp(const char *arrayname, int *array, size_t nelements)
{
	int success = 1;
	size_t i, j;
	for (i = 0; i < nelements; i++) {
		for (j = i + 1; j < nelements; j++) {
			if (array[i] == array[j]) {
				success = 0;
			}
		}
	}
	print_result(success, "Elements in %s are%s distinct", arrayname, success ? "" : " not");
}
