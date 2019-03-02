#if defined __STDC_VERSION__ && 199901L <= __STDC_VERSION__
#include <fenv.h>
#include "test.h"

void test_fenv_h(void)
{
	fenv_t fenv;
	fexcept_t fexcept;

	testing_header("fenv.h");

	testing_end();
}

#else
void test_fenv_h(void)
{
}
#endif
