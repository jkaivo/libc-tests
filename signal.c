#include <signal.h>
#include "test.h"

sig_atomic_t test_sig_atomic = 0;

void test_signal_h(void)
{
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
