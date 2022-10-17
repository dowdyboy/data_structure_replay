#ifndef _ASSIST_H
#define _ASSIST_H

#include "my_code_lib.h"

#define RANDOM(a, b) (rand() % (b - a + 1) + a)

class ArrayGenerator {
private:
	ArrayGenerator() { ; }
public:
	static int* generateOrderedIntArray(int size, int start=0, int step=1);
	static int* generateRandomIntArray(int size, int start=0, int end=10000);
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


class Util {
private:
	Util() { ; }
public:
	template<typename T>
	static void swap(T& a, T& b);

	template<typename T>
	static void print_array(T data[], int size);

	template<typename T>
	static bool is_sorted_array(T data[], int size, bool reverse = false);
};

template<typename T>
void Util::swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
void Util::print_array(T data[], int size) {
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

template<typename T>
bool Util::is_sorted_array(T data[], int size, bool reverse) {
	for (int i = 0; i < size - 1; i++) {
		if (reverse ? data[i] < data[i + 1] : data[i] > data[i + 1]) {
			return false;
		}
	}
	return true;
}


#endif
