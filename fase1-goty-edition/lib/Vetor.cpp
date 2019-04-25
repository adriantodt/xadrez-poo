#include "Vetor.h"

using namespace std;

/**
 * Constrói um vetor vazio.
 */
template <class T> Vetor<T>::Vetor() {
	size = 0;
}

/**
 * Insere um elemento no vetor.
 */
template <class T> bool Vetor<T>::insert(T element) {
	if (size >= 100) return false;

	elements[size] = element;
	size++;
	return true;
}
	
/**
 * Remove um elemento do vetor.
 */
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
	
/**
 * Obtém um elemento do vetor a partir da posição.
 * 
 * Caso o elemento esteja no vetor, coloca-o no ponteiro definido e retorna verdadeiro.
 * Caso contrário, retorna falso.
 */
template <class T> bool Vetor<T>::get(int at, T *to) {
	if (at < 1) return false;
	if (size < at) return false;

	*to = elements[at];
	return true;
}
