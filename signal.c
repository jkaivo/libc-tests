#include <signal.h>
#include "test.h"

void test_signal_h(void)
{
	sig_atomic_t sig_atomic;

	int signals[] = {
		SIGABRT,
		SIGFPE,
		SIGILL,
		SIGINT,
		SIGSEGV,
		SIGTERM,
	};

	testing_header("signal.h");

	test_distinct(signals);

	testing_end();
}
