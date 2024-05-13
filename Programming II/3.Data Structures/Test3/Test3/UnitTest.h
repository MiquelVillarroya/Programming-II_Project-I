
#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include<iostream>

int _test_done = 0;
int _test_failed = 0;

#define TEST(msg, test) \
	_test_done++; \
	if (!test) { _test_failed++; } \
	std::cout \
		<< "\t" \
		<< (!(test)?"FAIL":"OK") \
		<< "\t" \
		<< msg \
		<< std::endl;

#define PRINT_TEST_REPORT() \
	std::cout \
		<< std::endl \
		<< " - Test performed: " << _test_done << std::endl \
		<< " - Success: " << _test_done - _test_failed << std::endl \
		<< " - Failed: " << _test_failed \
		<< std::endl << std::endl;

#endif
