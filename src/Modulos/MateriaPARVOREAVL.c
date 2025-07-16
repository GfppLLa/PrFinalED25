#include "../Bibliotecas/MateriaPARVOREAVL.h"
#include "../Bibliotecas/Estruturas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

MateriaPrima* encontrarMinimo(MateriaPrima* no) {
    while (no->esq != NULL)
        no = no->esq;
    return no;
}

MateriaPrima* removerNo(MateriaPrima* raiz) {
    if (raiz->esq == NULL || raiz->dir == NULL) {
        MateriaPrima *temp = raiz->esq ? raiz->esq : raiz->dir;

        if (temp == NULL) {
            free(raiz);
            return NULL;
        } else {
            MateriaPrima *no = raiz;
            *raiz = *temp;
            free(no);
            return raiz;
        }
    } else {
        MateriaPrima *sucessor = encontrarMinimo(raiz->dir);
        raiz->codigoMateria = sucessor->codigoMateria;
        strcpy(raiz->nome, sucessor->nome);
        raiz->preco = sucessor->preco;
        raiz->dir = excluirMateria(raiz->dir, sucessor->codigoMateria);
        return raiz;
    }
}

MateriaPrima* balancearNo(MateriaPrima *no) {
    no->altura = 1 + maiorValor(alturaNo(no->esq), alturaNo(no->dir));
    int balance = fatorBalanceamento(no);

    if (balance > 1 && fatorBalanceamento(no->esq) >= 0)
        return rotacaoDireita(no);

    if (balance > 1 && fatorBalanceamento(no->esq) < 0) {
        no->esq = rotacaoEsquerda(no->esq);
        return rotacaoDireita(no);
    }

    if (balance < -1 && fatorBalanceamento(no->dir) <= 0)
        return rotacaoEsquerda(no);

    if (balance < -1 && fatorBalanceamento(no->dir) > 0) {
        no->dir = rotacaoDireita(no->dir);
        return rotacaoEsquerda(no);
    }

    return no;
}

MateriaPrima* excluirMateria(MateriaPrima* raiz, int codigo) {
    if (raiz == NULL)
        return NULL;

    if (codigo < raiz->codigoMateria) {
        raiz->esq = excluirMateria(raiz->esq, codigo);
    } else if (codigo > raiz->codigoMateria) {
        raiz->dir = excluirMateria(raiz->dir, codigo);
    } else {
        raiz = removerNo(raiz);
    }

    if (raiz == NULL)
        return NULL;

    return balancearNo(raiz);
}

void alterarMateriaPrima(MateriaPrima *raiz, int codigo, const char *novoNome, double novoPreco) {
    MateriaPrima *mat = buscarMateria(raiz, codigo);
    if (mat == NULL) {
        printf("Mat�ria-prima n�o encontrada.\n");
        return;
    }

    if (novoNome != NULL) {
        strcpy(mat->nome, novoNome);
    }

    mat->preco = novoPreco;
    printf("Mat�ria-prima atualizada com sucesso.\n");
}

void imprimirEmOrdem(MateriaPrima *raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esq);
        printf("Codigo: %d\nNome: %s\nPreco: %.2lf\n", raiz->codigoMateria, raiz->nome, raiz->preco);
        printf("------------------\n");
        imprimirEmOrdem(raiz->dir);
    }
}
