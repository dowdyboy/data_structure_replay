#include "my_code_lib.h"


int main() {
	Student data[3] = {
		Student("zhang san", 18),
		Student("li si", 19),
		Student("wang wu", 20)
	};
	Student target("zhang san", 18);

	int idx = LinearSearch::search(data, 0, 3, target);
	cout << idx << endl;
	return 0;
}