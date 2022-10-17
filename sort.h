#ifndef _SORT_H
#define _SORT_H

#include "my_code_lib.h"


class SelectSort {
private:
	SelectSort() { ; }
public:
	template<typename T>
	static void sort(T data[],const int start,const int end, const bool reverse=false);
};

template<typename T>
void SelectSort::sort(T data[], const int start, const int end, const bool reverse) {
	for (int i = start; i < end; i++) {
		for (int j = i; j < end; j++) {
			bool cond = reverse ? !(data[j] < data[i]) : data[j] < data[i];
			if (cond) {
				Util::swap(data[i], data[j]);
			}
		}
	}
}

class InsertSort {
private:
	InsertSort(){ ; }
public:
	template<typename T>
	static void sort(T data[], const int start, const int end, const bool reverse = false);
};

template<typename T>
void InsertSort::sort(T data[], const int start, const int end, const bool reverse) {
	for (int i = start; i < end; i++) {
		T tmp = data[i];
		int j = i;
		for (; j - 1 >= start && reverse ? !(tmp < data[j - 1]) : tmp < data[j - 1]; j--) {
			data[j] = data[j - 1];
		}
		data[j] = tmp;
	}
}

#endif
