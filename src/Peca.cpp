#include <fstream>
#include "Peca.h"

Peca::Peca(bool _branco) {
    branco = _branco;
    capturada = false;
}

bool Peca::isBranco() {
    return branco;
}

bool Peca::isCapturada() {
    return capturada;
}

void Peca::setCapturada(bool _capturada) {
    capturada = _capturada;
}

void Peca::desenha() {
    throw "Método não implementado.";    
}

bool Peca::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    throw "Método não implementado.";
}

TipoPeca Peca::getTipo() {
    throw "Método não implementado.";
}
