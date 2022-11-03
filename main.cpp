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
	if (!Util::is_sorted_array(arr, size)) {
		cout << "sort fail" << endl;
	}
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

void test_insert_sort(int size) {
	int* arr = ArrayGenerator::generateRandomIntArray(size);
	// Util::print_array(arr, size);
	InsertSort::sort(arr, 0, size);
	// Util::print_array(arr, size);
	if (!Util::is_sorted_array(arr, size)) {
		cout << "sort fail" << endl;
	}
	delete[] arr;
}

void test_insert_sort_ordered(int size) {
	int* arr2 = ArrayGenerator::generateOrderedIntArray(size);
	InsertSort::sort(arr2, 0, size);
	if (!Util::is_sorted_array(arr2, size)) {
		cout << "sort fail" << endl;
	}
	delete[] arr2;
}

void test_insert_sort_time() {
	double t = SpeedTester::test(1, test_insert_sort, 10000);
	cout << "time used : " << t << endl;
	t = SpeedTester::test(1, test_insert_sort_ordered, 10000);
	cout << "time used : " << t << endl;
}


void test_insert_sort_custom() {
	Student data[3] = {
		Student("zhang san", 20),
		Student("li si", 19),
		Student("wang wu", 18)
	};
	Util::print_array(data, 3);
	InsertSort::sort(data, 0, 3);
	Util::print_array(data, 3);
	if (!Util::is_sorted_array(data, 3)) {
		cout << "sort fail" << endl;
	}
}

void test_array_list() {
	ArrayList<int> a;
	for (int i = 0; i < 10; i++) {
		a.add(i * 10);
	}
	cout << a << endl;
	a.add(10);
	cout << a << endl;
	a[0] = 99;
	cout << a << endl;
	a.update(0, 111);
	cout << a << endl;
	// int x[10] = { 0 };
	// cout << x[1111] << endl;
	a.removeFirst();
	cout << a << endl;
	a.removeFirst();
	cout << a << endl;
}

void test_array_list_custom() {
	Student data[3] = {
		Student("zhang san", 18),
		Student("li si", 19),
		Student("wang wu", 20)
	};
	ArrayList<Student> a;
	a.add(data[0]);
	a.add(data[1]);
	a.add(data[2]);
	cout << a << endl;
	a.removeFirst();
	cout << a << endl;
}

void test_stack() {
	ArrayStack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s << endl;
	int e = s.pop();
	cout << "pop data: " << e << endl;
	cout << s << endl;
	cout << "top data: " << s.peek() << endl;
}

void test_queue() {
	ArrayQueue<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	cout << q << endl;
	int e = q.dequeue();
	cout << "dequeue data: " << e << endl;
	cout << q << endl;
	cout << "front data: " << q.getFront() << endl;
}


int main() {
	test_queue();
	return 0;
}