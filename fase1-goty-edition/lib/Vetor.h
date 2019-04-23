#include <iostream>
#define MAX 100
template <class T> class Vetor {
private:
	int size;
	T elements[100];

public:
	Vetor();

	bool set(T element);

	bool remove(T element);

	bool get(int at, T *to);
};
