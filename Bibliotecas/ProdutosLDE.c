#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estruturas.h"
#include "ProdutosLDE.h"
#include "MateriasPLD.h"

Produto* criarProduto(int codigoProduto, const char* nome, double margemLucro) {
    Produto* novo = (Produto*)malloc(sizeof(Produto));

    if (!novo) {
        return NULL;
    }

    novo->codigoProduto = codigoProduto;
    strcpy(novo->nome, nome);
    novo->margemLucro = margemLucro;
    novo->ant = NULL;
    novo->prox = NULL;
    novo->materiasProd = NULL;

    return novo;
}

Produto* posicaoProduto(Produto* lista, int codigo) {
    Produto* atual = lista;

    while (atual != NULL && atual->codigoProduto < codigo) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        Produto* ultimo = lista;
        while (ultimo && ultimo->prox != NULL) {
            ultimo = ultimo->prox;
        }
        return ultimo;
    }

    return atual->ant;
}

Produto* inserirProdutoOrdenado(Produto* lista, int codigo, const char* nome, double margemLucro) {
    Produto* novo = criarProduto(codigo, nome, margemLucro);
    if (!novo) {
        return lista;
    }
    
    if (lista == NULL || (lista->ant == NULL && codigo < lista->codigoProduto)) {
        novo->prox = lista;
        if (lista != NULL) {
            lista->ant = novo;
        }
        lista = novo;
        return lista;
    }

    Produto* anterior = posicaoProduto(lista, codigo);

    novo->prox = anterior->prox;
    novo->ant = anterior;

    if (anterior->prox != NULL) {
        anterior->prox->ant = novo;
    }
    anterior->prox = novo;

    return lista;
}

Produto* excluirProduto(Produto* lista, int codigo) {
    Produto* atual = lista;

    if (atual == NULL) {
        return lista;
    }
    
    while (atual != NULL && atual->codigoProduto != codigo) {
        atual = atual->prox;
    }

    if (atual == NULL){ 
        return lista;
    }

    if (atual->ant == NULL) {
        lista = atual->prox;
        if (lista != NULL) {
            lista->ant = NULL;
        }
    }
    else {
        atual->ant->prox = atual->prox;
        if (atual->prox != NULL) {
            atual->prox->ant = atual->ant;
        }
    }

    free(atual);
    return lista;
}

void imprimirProdutos(Produto* lista) {
    Produto* p;
    for (p = lista; p != NULL; p = p->prox) {
        printf("Código: %d\n", p->codigoProduto);
        printf("Nome: %s\n", p->nome);
        printf("Margem de Lucro: %.2lf%%\n\n", p->margemLucro);
        imprimirMateriasPLD(lista->materiasProd);
    }
}


