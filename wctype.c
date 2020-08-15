#if defined __STDC_VERSION__
#include <wctype.h>
#include "_wctype.h"
#include "test.h"

void test_wctype_h(void)
{
	wint_t wint;
	wctrans_t wctrans;
	wctype_t wctype;
	(void)wint;
	(void)wctrans;
	(void)wctype;

	testing_header("wctype.h");

	testing_end();
}

#else
void test_wctype_h(void)
{
}
#endif
