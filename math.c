#include <math.h>
#include "test.h"

void test_math_h(void)
{
	int iexp = 1;
	double iptr = 0;

	long double ldm1 = -1.0;
	double dm1 = -1.0;
	float fm1 = -1.0;
	long double ld1 =  1.0;
	double d1 = 1.0;
	float f1 = 1.0;

	testing_header("math.h");

	test_defined(HUGE_VAL);
	test_double(acos(1), 0);
	test_double(asin(1), 0);
	test_double(atan(1), 0);
	test_double(atan2(1, 1), 0);
	test_double(cos(1), 0);
	test_double(sin(1), 0);
	test_double(tan(1), 0);
	test_double(cosh(1), 0);
	test_double(sinh(1), 0);
	test_double(tanh(1), 0);
	test_double(exp(1), 0);
	test_double(frexp(1, &iexp), 0);
	test_double(ldexp(1, iexp), 0);
	test_double(log(2.4), 1);
	test_double(log10(10), 1);
	test_double(log10(100), 2);
	test_double(modf(1, &iptr), 0);
	test_double(pow(2, 2), 4);
	test_double(sqrt(100), 10);
	test_double(ceil(0.1), 1);
	test_double(fabs(-1.0), 1.0);
	test_double(floor(0.9), 0);
	test_double(fmod(1, 1), 0);

	#if defined __STDC_VERSION__ && 19901 <= __STDC_VERSION__
	test_int_equals(signbit(ldm1), 1);
	test_int_equals(signbit(dm1), 1);
	test_int_equals(signbit(fm1), 1);
	test_int_equals(signbit(ld1), 0);
	test_int_equals(signbit(d1), 0);
	test_int_equals(signbit(f1), 0);
	#endif

	testing_end();
}
