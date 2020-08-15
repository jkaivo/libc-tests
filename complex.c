#if defined __STDC_VERSION__ && \
	(__STDC_VERSION__ == 199901L || \
	 (201112L <= __STDC_VERSION__ && ! defined __STDC_NO_COMPLEX__))
#include <complex.h>
#include "test.h"

void test_complex_h(void)
{
	complex double cd;
	testing_header("complex.h");

	test_true(creal(I) == 0);
	test_true(cimag(I) == 1);
	test_true(creal(_Complex_I) == 0);
	test_true(cimag(_Complex_I) == 1);
	test_double(I * I, -1);

	#ifdef _Imaginary_I
	test_true(creal(_Imaginary_I) == 0);
	test_true(cimag(_Imaginary_I) == 1);
	#endif

	testing_end();
}

#else
void test_complex_h(void)
{
}
#endif
