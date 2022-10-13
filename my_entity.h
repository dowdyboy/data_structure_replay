#ifndef _MY_ENTITY_H
#define _MY_ENTITY_H

#include "my_code_lib.h"

class Student {
public:
	Student(string name, int age) {
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
	bool operator==(const Student& s) const {
		if (this->name == s.name && this->age == s.age) {
			return true;
		}
		else {
			return false;
		}
	}
};

#endif