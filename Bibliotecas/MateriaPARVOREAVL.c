#include "MateriaPARVOREAVL.h"
#include "Estruturas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int alturaNo(MateriaPrima *no) {
	if (no == NULL)
		return 0;
	return no->altura;
}

int maiorValor(int a, int b) {
	return (a > b) ? a : b;
}


MateriaPrima* criarNo(int codigoMateria, const char* nome, double preco) {
	MateriaPrima *novo = (MateriaPrima*)malloc(sizeof(MateriaPrima));
	novo->codigoMateria = codigoMateria;
	novo->preco = preco;
	strcpy(novo->nome, nome);
	novo->esq = NULL;
	novo->dir = NULL;
	novo->altura = 1;
	return novo;
}

int fatorBalanceamento(MateriaPrima *no) {
	if (no == NULL) {
		return 0;
	}
	return alturaNo(no->esq) - alturaNo(no->dir);
}

MateriaPrima* rotacaoDireita(MateriaPrima *y) {
	MateriaPrima *x = y->esq;
	MateriaPrima *T2 = x->dir;

	x->dir = y;
	y->esq = T2;

	y->altura = maiorValor(alturaNo(y->esq), alturaNo(y->dir)) + 1;
	x->altura = maiorValor(alturaNo(x->esq), alturaNo(x->dir)) + 1;

	return x;
}

MateriaPrima* rotacaoEsquerda(MateriaPrima *x) {
	MateriaPrima *y = x->dir;
	MateriaPrima *T2 = y->esq;

	y->esq = x;
	x->dir = T2;

	x->altura = maiorValor(alturaNo(x->esq), alturaNo(x->dir)) + 1;
	y->altura = maiorValor(alturaNo(y->esq), alturaNo(y->dir)) + 1;

	return y;
}

MateriaPrima* inserirMateria(MateriaPrima *raiz, int codigoMateria, const char* nome, double preco) {
    if (raiz == NULL)
        return criarNo(codigoMateria, nome, preco);

    if (codigoMateria < raiz->codigoMateria)
        raiz->esq = inserirMateria(raiz->esq, codigoMateria, nome, preco);
    else if (codigoMateria > raiz->codigoMateria)
        raiz->dir = inserirMateria(raiz->dir, codigoMateria, nome, preco);
    else
        return raiz;

    raiz->altura = 1 + maiorValor(alturaNo(raiz->esq), alturaNo(raiz->dir));

    int balance = fatorBalanceamento(raiz);

    if (balance > 1 && codigoMateria < raiz->esq->codigoMateria)
        return rotacaoDireita(raiz);

    if (balance < -1 && codigoMateria > raiz->dir->codigoMateria)
        return rotacaoEsquerda(raiz);

    if (balance > 1 && codigoMateria > raiz->esq->codigoMateria) {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }

    if (balance < -1 && codigoMateria < raiz->dir->codigoMateria) {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

void imprimirEmOrdem(MateriaPrima *raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esq);
        printf("Código: %d\nNome: %s\nPreço: %.2lf\n", raiz->codigoMateria, raiz->nome, raiz->preco);
        printf("------------------\n");
        imprimirEmOrdem(raiz->dir);
    }
}