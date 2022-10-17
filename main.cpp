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

void test_time_calc() {
	double t = SpeedTester::test(10, test_linear_search, 10000);
	cout << "time used : " << t << endl;
}

void test_select_sort(int size) {
	int* arr = ArrayGenerator::generateRandomIntArray(size);
	// Util::print_array(arr, size);
	SelectSort::sort(arr, 0, size);
	// Util::print_array(arr, size);
	delete[] arr;
}

void test_select_sort_time() {
	double t = SpeedTester::test(1, test_select_sort, 10000);
	cout << "time used : " << t << endl;
}

void test_select_sort_custom() {
	Student data[3] = {
		Student("zhang san", 20),
		Student("li si", 19),
		Student("wang wu", 18)
	};
	Util::print_array(data, 3);
	SelectSort::sort(data, 0, 3);
	Util::print_array(data, 3);
}

int main() {

	return 0;
}