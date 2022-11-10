#ifndef _QUEUE_H
#define _QUEUE_H

#include "my_code_lib.h"

template<typename T>
class Queue {
public:
	virtual void enqueue(const T& e) = 0;
	virtual void enqueue(const T&& e) {
		this->enqueue(e);
	}
	virtual T& dequeue() = 0;
	virtual T& getFront() = 0;
	virtual int getSize() const = 0;
	virtual bool isEmpty() const = 0;
};

template<typename T>
class ArrayQueue: public Queue<T> {
private:
	ArrayList<T>* list;
public:
	ArrayQueue() {
		this->list = new ArrayList<T>();
	}
	ArrayQueue(int capacity) {
		this->list = new ArrayList<T>(capacity);
	}
	~ArrayQueue() {
		delete this->list;
	}
	void enqueue(const T& e) {
		this->list->addLast(e);
	}
	T& dequeue() {
		T e = this->list->getFirst();
		this->list->removeFirst();
		return e;
	}
	T& getFront() {
		T e = this->list->getFirst();
		return e;
	}
	int getSize() const {
		return this->list->getSize();
	}
	bool isEmpty() const {
		return this->list->getSize() > 0 ? false : true;
	}

	friend ostream& operator<<(ostream& os, const ArrayQueue<T>& queue) {
		os << "ArrayQueue(size: " << queue.getSize() << ") ";
		os << "front [";
		for (int i = 0; i < queue.getSize(); i++) {
			os << (*queue.list)[i] << ", ";
		}
		os << "]";
		return os;
	}
};


template<typename T>
class LoopQueue : public Queue {
private:
	T* data;
	int head;
	int tail;
public:
	LoopQueue() {

	}
	LoopQueue(int capacity) {

	}
};



#endif