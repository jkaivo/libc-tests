#include <signal.h>
#include "test.h"

#include "signal.d"

void test_signal_h(void)
{
	testing_header("signal.h");

	test_distinct(signals);

	testing_end();
}
