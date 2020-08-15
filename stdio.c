#include <stdio.h>
#include "_stdio.h"
#include "test.h"

void test_stdio_h(void)
{
	FILE *file;
	fpos_t fpos;
	size_t size;
	(void)file;
	(void)fpos;
	(void)size;

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
