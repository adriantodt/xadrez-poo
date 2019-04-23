#include "Vetor.h"

using namespace std;

template <class T> Vetor<T>::Vetor<T>() {
	size = 0;
}

template <class T> bool Vetor<T>::insert(T element) {
	if (size >= 100) return false;

	elements[size] = element;
	size++;
	return true;
}
	
template <class T> bool Vetor<T>::remove(T element){
	if (size < 1) return false;
	
	for(int i = 0; i < size; i++) {
		if (elements[i] == element) {
			for (i = i; i <= size; i++) {
				elements[i] = elements[i + 1];
			}
			size--;
			return true;
		}
	}
	
	return false;
}
	
template <class T> bool Vetor<T>::get(int at, T *to) {
	if (at < 1) return false;
	if (size < at) return false;

	*to = elements[at];
	return true;
}