#include <string.h>
#include "test.h"

void test_string_h(void)
{
	size_t size;
	char dst[64] = { 0 };
	char less[] = "a";
	char more[] = "b";
	char haystack[] = "the five boxing wizards jump quickly";
	(void)size;

	testing_header("string.h");

	test_true(NULL == 0);

	test_string(memcpy(dst + 1, "foo", 3), "foo");
	test_string(memmove(dst, dst + 1, 3), "fooo");

	test_string(strcpy(dst, "foo"), "foo");
	memset(dst, '\0', sizeof(dst));
	test_string(strncpy(dst, "foo", 1), "f");
	test_string(strcat(dst, "oo"), "foo");
	test_string(strncat(dst, "barf", 3), "foobar");
	
	test_int_equals(memcmp(less, less, 2), 0);
	test_true(memcmp(less, more, 2) < 0);
	test_true(memcmp(more, less, 2) > 0);

	test_int_equals(strcmp(less, less), 0);
	test_true(strcmp(less, more) < 0);
	test_true(strcmp(more, less) > 0);

	test_int_equals(strcoll(less, less), 0);
	test_true(strcoll(less, more) < 0);
	test_true(strcoll(more, less) > 0);

	test_int_equals(strncmp(less, less, 2), 0);
	test_true(strncmp(less, more, 2) < 0);
	test_true(strncmp(more, less, 2) > 0);

	/* TODO: strxfrm */

	test_true(memchr(haystack, '1', sizeof(haystack)) == NULL);
	test_true(memchr(haystack, 'f', sizeof(haystack)) == haystack + 4);

	test_true(strchr(haystack, '1') == NULL);
	test_true(strchr(haystack, 'f') == haystack + 4);

	test_true(strcspn(haystack, " abcd") == 3);
	test_true(strcspn(haystack, "eht") == 0);
	test_true(strcspn(haystack, "12345") == sizeof(haystack) - 1);

	test_true(strpbrk(haystack, "12345") == NULL);
	test_true(strpbrk(haystack, "abcd") == haystack + 9);

	test_true(strrchr(haystack, '1') == NULL);
	test_true(strrchr(haystack, 'f') == haystack + 4);
	
	test_true(strspn(haystack, "12345") == 0);
	test_true(strspn(haystack, "eht") == 3);

	test_true(strstr(haystack, "wizard") == haystack + 16);
	test_true(strstr(haystack, "rogue") == NULL);

	/* TODO: strtok */

	/* TODO: memset */

	/* TODO: strerror */

	test_true(strlen(haystack) == sizeof(haystack) - 1);

	testing_end();
}
