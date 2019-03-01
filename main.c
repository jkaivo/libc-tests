#include <string.h>
#include "test.h"

int main(int argc, char *argv[])
{
	if (argc == 2) {
		if (!strcmp(argv[1], "assert")) {
			test_assert();
		}
	}

	test_time();
	test_errno();
	test_ctype();
	test_locale();
	return 0;
}
