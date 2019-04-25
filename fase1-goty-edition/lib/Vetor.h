/**
 * Vetor de tamanho dinâmico.
 */
template <class T> class Vetor {
private:
	int size;
	T elements[100];

public:
	/**
	 * Constrói um vetor vazio.
	 */
	Vetor();

	/**
	 * Insere um elemento no vetor.
	 */
	bool insert(T element);

	/**
	 * Remove um elemento do vetor.
	 */
	bool remove(T element);

	/**
	 * Obtém um elemento do vetor a partir da posição.
	 * 
	 * Caso o elemento esteja no vetor, coloca-o no ponteiro definido e retorna verdadeiro.
	 * Caso contrário, retorna falso.
	 */
	bool get(int at, T *to);
};
