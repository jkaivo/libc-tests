#include <locale.h>
#include <limits.h>
#include "test.h"

#ifndef LC_ALL
#error LC_ALL not defined
#endif

#ifndef LC_COLLATE
#error LC_COLLATE not defined
#endif

#ifndef LC_CTYPE
#error LC_CTYPE not defined
#endif

#ifndef LC_MONETARY
#error LC_MONETARY not defined
#endif

#ifndef LC_NUMERIC
#error LC_NUMERIC not defined
#endif

#ifndef LC_TIME
#error LC_TIME not defined
#endif

void test_locale(void)
{
	struct lconv *lc;
	int locale_categories[] = {
		LC_ALL,
		LC_COLLATE,
		LC_CTYPE,
		LC_MONETARY,
		LC_NUMERIC,
		LC_TIME,
	};

	testing_header("locale.h");

	test_distinct(locale_categories);

	/* TODO: test setlocale() */

	testing_comment("testing results of localeconv()");
	lc = localeconv();
	test_string(lc->decimal_point, ".");
	test_string(lc->thousands_sep, "");
	test_string(lc->grouping, "");
	test_string(lc->int_curr_symbol, "");
	test_string(lc->currency_symbol, "");
	test_string(lc->mon_decimal_point, "");
	test_string(lc->mon_thousands_sep, "");
	test_string(lc->positive_sign, "");
	test_string(lc->negative_sign, "");
	test_int_equals(lc->frac_digits, CHAR_MAX);
	test_int_equals(lc->p_cs_precedes, CHAR_MAX);
	test_int_equals(lc->p_sep_by_space, CHAR_MAX);
	test_int_equals(lc->n_cs_precedes, CHAR_MAX);
	test_int_equals(lc->n_sep_by_space, CHAR_MAX);
	test_int_equals(lc->p_sign_posn, CHAR_MAX);
	test_int_equals(lc->n_sign_posn, CHAR_MAX);

	testing_end();
}
