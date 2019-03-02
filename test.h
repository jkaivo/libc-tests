#include <stddef.h>

void testing_header(const char *);
void testing_comment(const char*);
void testing_end(void);

void test_int_equals_imp(const char*, int, int);
#define test_int_equals(expression, expected) test_int_equals_imp(#expression, expression, expected)

void test_double_imp(const char*, double, double);
#define test_double(expression, expected) test_double_imp(#expression, expression, expected)

void test_void_imp(const char*);
#define test_void(expression) ((void)expression), test_void_imp(#expression)

void test_bool_imp(const char *, int, int);
#define test_false(expression) test_bool_imp(#expression, expression, 0)
#define test_true(expression) test_bool_imp(#expression, expression, 1)
#define test_min(expression, min) test_bool_imp(#expression, min < 0 ? expression <= min : expression >= min, 1)
#define test_max(expression, max) test_bool_imp(#expression, 0 < expression && expression <= max, 1)
#define test_defined(expression) test_false(expression * 0)

void test_string_imp(const char*, const char*, const char*);
#define test_string(expression, string) test_string_imp(#expression, expression, string)

void test_distinct_imp(const char*, int *, size_t);
#define test_distinct(array) test_distinct_imp(#array, array, sizeof(array) / sizeof(array[0]))

extern int verbose;
extern unsigned int total_passed;
extern unsigned int total_failed;
