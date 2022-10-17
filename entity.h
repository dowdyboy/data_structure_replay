#ifndef _ENTITY_H
#define _ENTITY_H

#include "my_code_lib.h"

class Student {
private:
	string name;
	int age;

public:
	Student(string name, int age) {
		this->name = name;
		this->age = age;
	}
	bool operator==(const Student& s) const;
	bool operator<(const Student& s) const;
	bool operator>(const Student& s) const;

	friend ostream& operator<<(ostream& os, const Student& s);
};

#endif