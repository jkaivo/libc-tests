#include <signal.h>
#include "test.h"

void test_signal_h(void)
{
	sig_atomic_t sig_atomic = 0;

	int signals[] = {
		SIGABRT,
		SIGFPE,
		SIGILL,
		SIGINT,
		SIGSEGV,
		SIGTERM,
	};

	(void)sig_atomic;

	testing_header("signal.h");

	test_distinct(signals);

	testing_end();
}
