#ifndef _STACK_H
#define _STACK_H

#include "my_code_lib.h"

template<typename T>
class Stack {
public:
	virtual void push(const T& e) = 0;
	virtual void push(const T&& e) {
		this->push(e);
	}
	virtual T& pop() = 0;
	virtual T& peek() = 0;
	virtual int getSize() const = 0;
	virtual bool isEmpty() const = 0;
};


template<typename T>
class ArrayStack: public Stack<T> {
private:
	ArrayList<T>* list;
public:
	ArrayStack() {
		this->list = new ArrayList<T>();
	}
	ArrayStack(int capacity) {
		this->list = new ArrayList<T>(capacity);
	}
	~ArrayStack() {
		delete this->list;
	}
	void push(const T& e) {
		this->list->addLast(e);
	}
	T& pop() {
		T& e = this->list->getLast();
		this->list->removeLast();
		return e;
	}
	T& peek() {
		return this->list->getLast();
	}
	int getSize() const {
		return this->list->getSize();
	}
	bool isEmpty() const {
		return this->list->getSize() > 0 ? false : true;
	}

	friend ostream& operator<<(ostream& os, const ArrayStack<T>& stack) {
		os << "ArrayStack(size: " << stack.getSize() << ") ";
		os << "[";
		for (int i = 0; i < stack.list->getSize(); i++) {
			os << (*stack.list)[i] << ", ";
		}
		os << "] top";
		return os;
	}
};


#endif
