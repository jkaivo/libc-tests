#include <time.h>
#include "test.h"

#ifndef NULL
#error NULL not defined
#endif

#ifndef CLOCKS_PER_SEC
#error CLOCKS_PER_SEC not defined
#endif

#define test_strftime(_fmt, _tm, _expected) do { \
	char buf[128]; \
	strftime(buf, sizeof(buf), _fmt, &_tm); \
	test_string(buf, _expected); \
} while (0)

void test_time(void)
{
	struct tm tm;
	tm.tm_year = 2001 - 1900;
	tm.tm_mon = 7 - 1;
	tm.tm_mday = 4;
	tm.tm_hour = 13;
	tm.tm_min = 40;
	tm.tm_sec = 50;
	tm.tm_isdst = -1;

	testing_header("time.h");

	testing_comment("letting mktime() adjust fields");
	mktime(&tm);

	testing_comment("testing asctime()");
	test_string(asctime(&tm), "something something");

	testing_comment("testing strftime()");
	test_strftime("%a", tm, "???");
	test_strftime("%A", tm, "???day");
	test_strftime("%b", tm, "Jun");
	test_strftime("%B", tm, "June");
	test_strftime("%c", tm, "see 7.23.1");
	test_strftime("%C", tm, "01");
	test_strftime("%d", tm, "04");
	test_strftime("%D", tm, "06/04/01");
	test_strftime("%e", tm, " 4");
	test_strftime("%F", tm, "2001-06-04");
	test_strftime("%g", tm, "week_of_year");
	test_strftime("%G", tm, "2001");
	test_strftime("%h", tm, "Jun");
	test_strftime("%H", tm, "13");
	test_strftime("%I", tm, "01");
	test_strftime("%j", tm, "160");
	test_strftime("%m", tm, "06");
	test_strftime("%n", tm, "\n");
	test_strftime("%p", tm, "PM");
	test_strftime("%r", tm, "01:40");
	test_strftime("%R", tm, "13:40");
	test_strftime("%S", tm, "50");
	test_strftime("%t", tm, "\t");
	test_strftime("%T", tm, "13:40:50");
	test_strftime("%u", tm, "weekday_number");
	test_strftime("%U", tm, "week number");
	test_strftime("%V", tm, "week number");
	test_strftime("%w", tm, "weekday number");
	test_strftime("%W", tm, "week number");
	test_strftime("%x", tm, "date per 7.23.1");
	test_strftime("%X", tm, "time per 7.23.1");
	test_strftime("%y", tm, "01");
	test_strftime("%Y", tm, "2001");
	test_strftime("%z", tm, "tz_offset");
	test_strftime("%Z", tm, "tz_name");
	test_strftime("%%", tm, "%");

	testing_end();
}
