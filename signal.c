#include <signal.h>
#include "test.h"

static sig_atomic_t sig_atomic;

static int signals[] = {
	SIGABRT,
	SIGFPE,
	SIGILL,
	SIGINT,
	SIGSEGV,
	SIGTERM,
};

void test_signal_h(void)
{
	testing_header("signal.h");

	test_distinct(signals);

	testing_end();
}
