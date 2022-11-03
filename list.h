#ifndef _LIST_H
#define _LIST_H

#include "my_code_lib.h"


template <typename T>
class List {
public:
	static uint8 const STATUS_OK = 0;
	static uint8 const STATUS_RANGE_ERROR = 1;
	static uint8 const STATUS_NOT_FOUND_ELEMENT = 2;
	virtual ~List() { ; }
	virtual uint8 add(const T& e) = 0;
	virtual uint8 add(const T&& e) {
		return this->add(e);
	}
	virtual uint8 add(const int index,const T& e) = 0;
	virtual uint8 add(const int index, const T&& e) {
		return this->add(index, e);
	}
	virtual uint8 addFirst(const T& e) = 0;
	virtual uint8 addFirst(const T&& e) {
		return this->addFirst(e);
	}
	virtual uint8 addLast(const T& e) = 0;
	virtual uint8 addLast(const T&& e) {
		return this->addLast(e);
	}
	virtual uint8 remove(const int i) = 0;
	virtual uint8 removeFirst() = 0;
	virtual uint8 removeLast() = 0;
	virtual uint8 removeElement(T& e) = 0;
	virtual uint8 removeElement(T&& e) {
		return this->removeElement(e);
	}
	virtual uint8 update(const int index, const T& e) = 0;
	virtual uint8 update(const int index, const T&& e) {
		return this->update(index, e);
	}
	virtual T& operator[](const int index) const = 0;
	virtual T& get(const int index) = 0;
	virtual T& getFirst() = 0;
	virtual T& getLast() = 0;
	virtual int indexOf(const T& e) = 0;
	virtual int indexOf(const T&& e) {
		return this->indexOf(e);
	}
	virtual int getSize() const = 0;
};

template <typename T>
class ArrayList: public List<T> {
private:
	T* data;
	int capacity;
	int size = 0;
	uint8 checkAddAndExpand(int index) {
		if (index < 0 || index > this->size) {
			return List<T>::STATUS_RANGE_ERROR;
		}
		if (this->size >= this->capacity) {
			this->capacity = (int)(2 * this->capacity);
			auto newData = new T[this->capacity];
			for (int i = 0; i < this->size; i++) {
				newData[i] = this->data[i];
			}
			delete[] this->data;
			this->data = newData;
		}
		return List<T>::STATUS_OK;
	}
	uint8 checkRemoveAndShrink(int index) {
		if (index < 0 || index > this->size - 1) {
			return List<T>::STATUS_RANGE_ERROR;
		}
		if (this->capacity > 10 && this->size * 2 <= this->capacity) {
			this->capacity = (int)(0.75 * this->capacity);
			auto newData = new T[this->capacity];
			for (int i = 0; i < this->size; i++) {
				newData[i] = this->data[i];
			}
			delete[] this->data;
			this->data = newData;
		}
		return List<T>::STATUS_OK;
	}
	uint8 checkUpdate(int index) {
		if (index < 0 || index > this->size - 1) {
			return List<T>::STATUS_RANGE_ERROR;
		}
		return List<T>::STATUS_OK;
	}
public:
	ArrayList() {
		this->capacity = 10;
		this->data = new T[this->capacity];
	}
	ArrayList(int capacity) {
		this->capacity = capacity;
		this->data = new T[capacity];
	}
	~ArrayList() {
		delete[] this->data;
	}
	uint8 add(const T& e) {
		return this->add(this->size, e);
	}
	uint8 add(const int index, const T& e) {
		uint8 status = this->checkAddAndExpand(index);
		if (status != List<T>::STATUS_OK) {
			return status;
		}
		for (int i = this->size; i - 1 >= index; i--) {
			this->data[i] = this->data[i - 1];
		}
		this->data[index] = e;
		this->size++;
		return List<T>::STATUS_OK;
	}
	uint8 addFirst(const T& e) {
		return this->add(0, e);
	}
	uint8 addLast(const T& e) {
		return this->add(this->size, e);
	}
	uint8 remove(const int i) {
		uint8 status = this->checkRemoveAndShrink(i);
		if (status != List<T>::STATUS_OK) {
			return status;
		}
		for (int x = i; x + 1 < this->size; x++) {
			this->data[x] = this->data[x + 1];
		}
		this->size--;
		return List<T>::STATUS_OK;
	}
	uint8 removeFirst() {
		return this->remove(0);
	}
	uint8 removeLast() {
		return this->remove(this->size - 1);
	}
	uint8 removeElement(T& e) {
		int index = this->indexOf(e);
		if (index == -1) {
			return List<T>::STATUS_NOT_FOUND_ELEMENT;
		}
		this->remove(index);
		return List<T>::STATUS_OK;
	}
	uint8 update(const int index, const T& e) {
		uint8 status = this->checkUpdate(index);
		if (status != List<T>::STATUS_OK) {
			return status;
		}
		this->data[index] = e;
		return List<T>::STATUS_OK;
	}
	T& get(const int index) {
		if (index < 0 || index > this->size - 1) {
			throw exception("index out of range");
		}
		return this->data[index];
	}
	T& getFirst() {
		return this->get(0);
	}
	T& getLast() {
		return this->get(this->size - 1);
	}
	T& operator[](int index) const {
		/*if (index < 0 || index > this->size - 1) {
			throw exception("index out of range");
		}*/
		return this->data[index];
	}
	int indexOf(const T& e) {
		for (int i = 0; i < this->size; i++) {
			if (this->data[i] == e) {
				return i;
			}
		}
		return -1;
	}
	int getSize() const {
		return this->size;
	}
	int getCapacity() {
		return this->capacity;
	}
	

	friend ostream& operator<<(ostream& os, const ArrayList<T>& list) {
		os << "ArrayList(capacity: " << list.capacity << ", " << "size: " << list.size << ") ";
		os << "[";
		for (int i = 0; i < list.size; i++) {
			os << list.data[i] << ", ";
		}
		os << "]";
		return os;
	}
};



#endif