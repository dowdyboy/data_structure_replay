#ifndef _SEARCH_H
#define _SEARCH_H


class LinearSearch {
private:
	LinearSearch() {};
public:	
	template<typename T> static int search(const T data[], int start, int end, const T& target);
};

template<typename T> int LinearSearch::search(const T data[], int start, int end, const T& target) {
	for (int i = start; i < end; i++) {
		if (data[i] == target) {
			return i;
		}
	}
	return -1;
}

#endif


