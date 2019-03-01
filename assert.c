#include <stdio.h>
#include "test.h"

void test_assert_h(void)
{
	int n = 0;

	testing_header("assert.h");

#define NDEBUG
#include <assert.h>
	testing_comment("Expression with side-effect should be removed by preprocessor");
	test_void(assert(n = 1));
	test_int_equals(n, 0);

#undef NDEBUG
#include <assert.h>
	testing_comment("Expression with side-effect should execute");
	test_void(assert(n = 1));
	test_int_equals(n, 1);

#define NDEBUG
#include <assert.h>
	testing_comment("Successful assertion should be removed by preprocessor");
	test_void(assert(n == 1));

#undef NDEBUG
#include <assert.h>
	testing_comment("Successful assertion should execute");
	test_void(assert(n == 1));

#define NDEBUG
#include <assert.h>
	testing_comment("Unsuccessful assertion should be removed by preprocessor");
	test_void(assert(n == 0));

#undef NDEBUG
#include <assert.h>
	testing_comment("Unsuccessful assertion should execute");
	test_void(assert(n == 0));
}
