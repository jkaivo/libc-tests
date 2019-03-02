#include <string.h>
#include "test.h"

void test_string_h(void)
{
	size_t size;

	testing_header("string.h");

	test_true(NULL == 0);

	testing_end();
}
