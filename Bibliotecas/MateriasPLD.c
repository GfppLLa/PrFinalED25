#include "MateriasPLD.h"
#include "Estruturas.h"
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
    MateriasPLD* atual = lista;

    while (atual != NULL && atual->codigoMateria != codigo) {
        atual = atual->prox;
    }

    if (atual == NULL){
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

void imprimirMateriasPLD(MateriasPLD* lista) {
    MateriasPLD* p = lista;
    
    printf("Materias-Primas do produto: \n");
    while(p != NULL){
        printf("Codigo: %d\n", p->codigoMateria);
        printf("Quantidade: %d\n", p->quantidade);
        printf("-----------------\n");
        p = p->prox;
    }
    
}

