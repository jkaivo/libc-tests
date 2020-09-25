#include <stdio.h>
#include "_stdio.h"
#include "test.h"

FILE *test_file;
fpos_t test_fpos;
size_t test_size;

void test_stdio_h(void)
{
	int buftypes[] = {
		_IOFBF,
		_IOLBF,
		_IONBF,
	};

	int seeks[] = {
		SEEK_CUR,
		SEEK_END,
		SEEK_SET,
	};

	testing_header("stdio.h");

	test_distinct(buftypes);
	test_distinct(seeks);

	test_min(BUFSIZ, 256);
	test_min(FILENAME_MAX, 1);
	test_min(FOPEN_MAX, 8);
	test_min(L_tmpnam, 1);
	test_true(NULL == 0);
	test_min(TMP_MAX, 25);

	testing_end();
}
