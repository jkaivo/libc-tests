void testing_header(const char *);
void testing_comment(const char*);

void test_int_equals_imp(const char*, int, int);
#define test_int_equals(expression, expected) test_int_equals_imp(#expression, expression, expected)

void test_void_imp(const char*);
#define test_void(expression) test_void_imp(#expression); (void)expression

void test_bool_imp(const char *, int, int);
#define test_false(expression) test_bool_imp(#expression, expression, 0)
#define test_true(expression) test_bool_imp(#expression, expression, 1)

void test_string_imp(const char*, const char*, const char*);
#define test_string(expression, string) test_string_imp(#expression, expression, string)

void test_assert(void);
void test_ctype(void);
void test_locale(void);
