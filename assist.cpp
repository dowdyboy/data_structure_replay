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

int* ArrayGenerator::generateRandomIntArray(int size, int start, int end) {
	srand(time(NULL));
	int* ret = new int[size];
	for (int i=0; i<size; i++){
		int rnd = RANDOM(start, end);
		ret[i] = rnd;
	}
	return ret;
}