#include "../Bibliotecas/MateriasPLD.h"
#include "../Bibliotecas/MateriaPARVOREAVL.h"
#include "../Bibliotecas/Estruturas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

MateriasPLD* criarMateriaNaLista(int codigo, int quantidade) {
    MateriasPLD* novo = (MateriasPLD*)malloc(sizeof(MateriasPLD));
    if (!novo) return NULL;

    novo->codigoMateria = codigo;
    novo->quantidade = quantidade;
    novo->ant = NULL;
    novo->prox = NULL;

    return novo;
}

MateriasPLD* posicaoMateriaPLD(MateriasPLD* lista, int codigo) {
    MateriasPLD* atual = lista;

    while (atual != NULL && atual->codigoMateria < codigo) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        MateriasPLD* ultimo = lista;
        while (ultimo && ultimo->prox != NULL) {
            ultimo = ultimo->prox;
        }
        return ultimo;
    }

    return atual->ant;
}

MateriasPLD* inserirMateriaOrdenado(MateriasPLD* lista, int codigo, int quantidade) {
    MateriasPLD* novo = criarMateriaNaLista(codigo, quantidade);
    if (!novo) return lista;

    if (lista == NULL || (lista->ant == NULL && codigo < lista->codigoMateria)) {
        novo->prox = lista;
        if (lista != NULL)
            lista->ant = novo;
        return novo;
    }

    MateriasPLD* anterior = posicaoMateriaPLD(lista, codigo);

    novo->prox = anterior->prox;
    novo->ant = anterior;

    if (anterior->prox != NULL)
        anterior->prox->ant = novo;

    anterior->prox = novo;

    return lista;
}

MateriasPLD* excluirMateriaPLD(MateriasPLD* lista, int codigo) {
    MateriasPLD* atual = buscarMateriaPLD(lista, codigo);

    if (atual == NULL) {
        return lista;
    }

    if (atual->ant == NULL) {
        lista = atual->prox;
        if (lista != NULL)
            lista->ant = NULL;
    } else {
        atual->ant->prox = atual->prox;
        if (atual->prox != NULL)
            atual->prox->ant = atual->ant;
    }

    free(atual);
    return lista;
}

void alterarQuantidadeMateriaProduto(Produto *lista, int codigoProduto, int codigoMateria, int novaQuantidade) {
    Produto *prod = buscarProduto(lista, codigoProduto);
    if (prod == NULL) {
        printf("Produto nao encontrado.\n");
        return;
    }

    MateriasPLD *matPLD = buscarMateriaPLD(prod->materiasProd, codigoMateria);
    if (matPLD == NULL) {
        printf("Materia-prima nao encontrada no produto.\n");
        return;
    }

    matPLD->quantidade = novaQuantidade;
}

void adicionarOuSubstituirMateriaProduto(Produto *lista, int codigoProduto, int codigoMateria, int quantidade) {
    Produto *prod = buscarProduto(lista, codigoProduto);
    if (prod == NULL) {
        printf("Produto nao encontrado.\n");
        return;
    }

    MateriasPLD *existente = buscarMateriaPLD(prod->materiasProd, codigoMateria);
    if (existente != NULL) {
        existente->quantidade = quantidade;
    } else {
        prod->materiasProd = inserirMateriaOrdenado(prod->materiasProd, codigoMateria, quantidade);
    }

}

void removerMateriaDoProduto(Produto *lista, int codigoProduto, int codigoMateria) {
    Produto *prod = buscarProduto(lista, codigoProduto);
    if (prod == NULL) {
        printf("Produto nao encontrado.\n");
        return;
    }

    prod->materiasProd = excluirMateriaPLD(prod->materiasProd, codigoMateria);
    printf("Materia-prima removida do produto.\n");
}


void imprimirMateriasPLD(MateriasPLD* lista, MateriaPrima *raiz) {
    MateriasPLD* p = lista;

    while(p != NULL){
        MateriaPrima *aux = buscarMateria(raiz, p->codigoMateria);
        printf("Codigo: %d; ", p->codigoMateria);
        printf("Nome: %s; ", aux->nome);
        printf("Preco: %.2f; ", aux->preco);
        printf("Quantidade: %d;\n", p->quantidade);
        p = p->prox;
    }

}

