#ifndef _ASSIST_H
#define _ASSIST_H

#include "my_code_lib.h"

class ArrayGenerator {
private:
	ArrayGenerator() { ; }
public:
	static int* generateOrderedIntArray(int size, int start=0, int step=1);
};

class SpeedTester {
private:
	SpeedTester() { ; }
public:
	template<typename Fn, typename... Args>
	static double test(int count, Fn func, Args... args);
};

template<typename Fn, typename... Args>
double SpeedTester::test(int count, Fn func, Args... args) {
	clock_t start_t, end_t;
	double time_used = 0.;
	start_t = clock();
	for (int i = 0; i < count; i++) {
		func(args...);
	}
	end_t = clock();
	time_used = (double)(end_t - start_t);
	time_used /= CLOCKS_PER_SEC;
	return time_used;
}


#endif
