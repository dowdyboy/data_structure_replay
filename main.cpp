#include "my_code_lib.h"


void linear_search_demo1() {
	Student data[3] = {
		Student("zhang san", 18),
		Student("li si", 19),
		Student("wang wu", 20)
	};
	Student target("zhang san", 18);

	int idx = LinearSearch::search(data, 0, 3, target);
	cout << idx << endl;
}

void test_linear_search(int size) {
	int* arr = ArrayGenerator::generateOrderedIntArray(size);
	for (int i = 0; i < size; i++) {
		LinearSearch::search(arr, 0, size, size);
	}
	delete[] arr;
}

int main() {
	double t = SpeedTester::test(10, test_linear_search, 10000);
	cout << "time used : " << t << endl;
	return 0;
}