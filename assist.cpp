#include "my_code_lib.h"

int* ArrayGenerator::generateOrderedIntArray(int size, int start, int step) {
	int* ret = new int[size];
	int value = start;
	for (int i = 0; i < size; i++) {
		ret[i] = value;
		value += step;
	}
	return ret;
}