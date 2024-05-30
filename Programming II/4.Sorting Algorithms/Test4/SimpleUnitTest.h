#ifndef __SIMPLEUNITTEST__H__
#define __SIMPLEUNITTEST__H__

#include<stdio.h>

int _test_done = 0;
int _test_failed = 0;

#define TEST(msg, test) _test_done++; printf("\t%s\t%s\n", !(test) ? _test_failed++, "FAIL" : "OK", msg)

#define PRINT_TEST_REPORT() printf("\nTest performed: %d\nSuccess: %d\nFailed: %d\n", \
	_test_done, _test_done - _test_failed, _test_failed)

#endif
