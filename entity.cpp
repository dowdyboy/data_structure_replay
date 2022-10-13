#include "my_code_lib.h"

bool Student::operator==(const Student& s) const {
	if (this->name == s.name && this->age == s.age) {
		return true;
	}
	else {
		return false;
	}
}