#include <float.h>
#include "_float.h"
#include "test.h"

void test_float_h(void)
{
	testing_header("float.h");

	test_min(DBL_DIG, 10);
	test_min(DBL_MAX_10_EXP, 37);
	test_min(DBL_MIN_10_EXP, -37);

	test_min(FLT_DIG, 6);
	test_min(FLT_MAX_10_EXP, 37);
	test_min(FLT_MIN_10_EXP, -37);
	test_min(FLT_RADIX, 2);
	
	test_min(LDBL_DIG, 6);
	test_min(LDBL_MAX_10_EXP, 37);
	test_min(LDBL_MIN_10_EXP, -37);

	test_min(DBL_MAX, 1e+37);
	test_min(FLT_MAX, 1e+37);
	test_min(LDBL_MAX, 1e+37);

	test_max(DBL_EPSILON, 1e-9);
	test_max(DBL_MIN, 1e-37);
	test_max(FLT_EPSILON, 1e-5);
	test_max(FLT_MIN, 1e-37);
	test_max(LDBL_EPSILON, 1e-9);
	test_max(LDBL_MIN, 1e-37);

	#if defined __STDC_VERSION__ && 201112L <= __STDC_VERSION__
	test_min(DBL_DECIMAL_DIG, 10);
	test_min(FLT_DECIMAL_DIG, 6);
	test_min(LDBL_DECIMAL_DIG, 6);
	#endif

	testing_end();
}
