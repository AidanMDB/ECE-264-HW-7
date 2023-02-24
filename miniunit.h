#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#ifndef __MINIUNIT_H__
#define __MINIUNIT_H__

#define MU_SUCCESS 0

#define mu_start() int _mu_first_failure_line_number_or_0 = MU_SUCCESS

#define mu_end() return _mu_first_failure_line_number_or_0

#define mu_check(condition) \
	do \
	{ \
		if(!(condition) && _mu_first_failure_line_number_or_0 == MU_SUCCESS) \
		{ \
			_mu_first_failure_line_number_or_0 = __LINE__; \
		} \
	}while(false)

#define mu_run(function) \
	do \
	{ \
		int line_number = function(); \
		if(line_number == MU_SUCCESS) \
		{ \
			printf("\x1b[32mTest passed:\x1b[0m %s\n", #function); \
		} \
		else \
		{ \
			printf("\x1b[31mTest failed:\x1b[0m %s \x1b[31mat line \x1b[0m %d\n", #function, line_number); \
		} \
	}while(false)

#define mu_check_strings_equal(s1, s2) mu_check(strcmp(#s1, #s2))

#endif /* end of include guard: __MINIUNIT_H__ */
