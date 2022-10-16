#ifndef _SORT_H
#define _SORT_H

#include "my_code_lib.h"

class SelectSort {
private:
	SelectSort() { ; }
public:
	template<typename T>
	static void sort(T data[],const int start,const int end);
};

template<typename T>
void SelectSort::sort(T data[], const int start, const int end) {
	for (int i = start; i < end; i++) {
		for (int j = i; j < end; j++) {
			if (data[j] < data[i]) {
				Util::swap(data[i], data[j]);
			}
		}
	}
}

#endif
