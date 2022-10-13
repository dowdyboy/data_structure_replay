#ifndef _ENTITY_H
#define _ENTITY_H

#include "my_code_lib.h"

class Student {
public:
	string name;
	int age;

	Student(string name, int age) {
		this->name = name;
		this->age = age;
	}

	bool operator==(const Student& s) const;
};

#endif