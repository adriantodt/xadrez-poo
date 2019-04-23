#include "Vetor.h"
using namespace std;

/* cria um vetor vazio */
Vetor::Vetor() {
	tamanho = 0;
}

Vetor::Vetor(int elem, int nRepeticoes){
	if (nRepeticoes <= MAX)
	for (tamanho = 0; tamanho < nRepeticoes; tamanho++)
		elementos[tamanho] = elem;
}



/*Insere elemento no vetor*/

bool Vetor::inserir(int elem){

	if(tamanho < MAX){

		elementos[tamanho] = elem;
		tamanho++;
		return true;
	}
    else
	    return false;
}
	
/*Remove elemento no vetor*/
bool Vetor::remover(int elem){

	int i;
	i = 0;

	if (tamanho > 0){
		while(i < MAX && elementos[i] != elem)
			i++;
		if(elementos[i] == elem){
			if(i < MAX){
				while (i < MAX-1){
					elementos[i] = elementos[i+1];
					i++;
				}
			}
			tamanho--;
			return true;
		}
	}
	else 
        return false;
}
	
/*Retorna o elemento do vetor na posição escolhida*/
int Vetor::recuperarElemento(int posicao){
	
	if(posicao >= 0 && posicao < tamanho){// posicao valida se esta entre 0 e o tamanho do vetor
		
		return elementos[posicao];
		
	}
	
	return -1;	
}
	
/*Inicializa o vetor com o elemento desejado*/
void Vetor::preencher(int elem, int nRepeticoes){
	if (nRepeticoes <= MAX)
	    for (tamanho = 0; tamanho < nRepeticoes; tamanho++)
		    elementos[tamanho] = elem;
}

/*Imprime os elementos do vetor*/
void Vetor::imprimir(){
	
	cout << endl;
	for (int i = 0; i < tamanho; i++){
		cout << "v[" << i << "] = "<< elementos[i] << endl;
	}
	cout << endl;



}
