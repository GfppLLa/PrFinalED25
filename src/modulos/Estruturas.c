#include "../Bibliotecas/Estruturas.h"
#include <stdio.h>

//inserir fun��es
Produto* buscarProduto(Produto *no, int codigoProduto){
    Produto *aux = no;

    while(aux != NULL && aux->codigoProduto != codigoProduto){
        aux = aux->prox;
    }

    return aux;
}

MateriasPLD* buscarMateriaPLD(MateriasPLD *no, int codigoMateria) {
    MateriasPLD *aux = no;

    while (aux != NULL && aux->codigoMateria != codigoMateria) {
        aux = aux->prox;
    }

    return aux;
}

MateriaPrima* buscarMateria(MateriaPrima* raiz, int codigoMateria) {
    if (raiz == NULL || raiz->codigoMateria == codigoMateria) {
        return raiz;
    }

    if (codigoMateria < raiz->codigoMateria) {
        return buscarMateria(raiz->esq, codigoMateria);
    } else {
        return buscarMateria(raiz->dir, codigoMateria);
    }
}
