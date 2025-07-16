#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Bibliotecas/Estruturas.h"
#include "../Bibliotecas/ProdutosLDE.h"
#include "../Bibliotecas/MateriasPLD.h"
#include "../Bibliotecas/MateriaPARVOREAVL.h"

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
    Produto* atual = buscarProduto(lista, codigo);

    if (atual == NULL) {
        return lista;
    }

    if (atual->ant == NULL) {
        lista = atual->prox;
        if (lista != NULL) {
            lista->ant = NULL;
        }
    } else {
        atual->ant->prox = atual->prox;
        if (atual->prox != NULL) {
            atual->prox->ant = atual->ant;
        }
    }

    free(atual);
    return lista;
}


double calcularCustoProd(MateriasPLD *materia, MateriaPrima *raiz){
    if(!materia){
        return 0.0;
    }

    if(!raiz){
        return 0.0;
    }

    MateriasPLD *percorrerLista = materia;
    double soma = 0.0;

    while(percorrerLista != NULL){

        MateriaPrima *noAUX = buscarMateria(raiz, percorrerLista->codigoMateria);
        soma += noAUX->preco * percorrerLista->quantidade;
        percorrerLista = percorrerLista->prox;
    }

    return soma;
}

double custoDeVenda(double custoDeProd, double margemLucro){
    double porcentMargem = margemLucro/100;
    double total = (1.00 + porcentMargem) * custoDeProd;

    return total;
}

void produtoSolicitado(int codigoProduto, Produto *produto, MateriaPrima *raiz){
    Produto *aux = buscarProduto(produto, codigoProduto);
    if(!aux){
        printf("Produto n�o encontrado!");
    }

    double custoProd = calcularCustoProd(aux->materiasProd, raiz);
    double precoFinal = custoDeVenda(custoProd, aux->margemLucro);
    printf("Codigo: %d\n", aux->codigoProduto);
    printf("Nome: %s\n", aux->nome);
    printf("Custo do produto: %.2f\n", custoProd);
    printf("Preco de venda: %.2f\n\n", precoFinal);
    if(!(aux->materiasProd)){
        printf("Produto sem materia prima cadastrada!\n\n");
        aux = aux->prox;
    }else{
        printf("Materias Primas do produto: \n");
        printf("------------------\n");
        imprimirMateriasPLD(aux->materiasProd, raiz);
        printf("------------------\n");
        aux = aux->prox;
    }
}

void imprimirProdutos(Produto* lista, MateriaPrima *raiz) {
    Produto* p = lista;

    while(p != NULL) {
        double custoProd = calcularCustoProd(p->materiasProd, raiz);
        double precoFinal = custoDeVenda(custoProd, p->margemLucro);
        printf("Codigo: %d\n", p->codigoProduto);
        printf("Nome: %s\n", p->nome);
        printf("Custo do produto: %.2f\n", custoProd);
        printf("Preco de venda: %.2f\n\n", precoFinal);
        if(!(p->materiasProd)){
            printf("Produto sem materia prima cadastrada!\n\n");
            p = p->prox;
        }else{
            printf("Materias Primas do produto: \n");
            printf("------------------\n");
            imprimirMateriasPLD(p->materiasProd, raiz);
            printf("------------------\n");
            p = p->prox;
        }
    }
}

void alterarProduto(Produto *lista, int codigo, const char *novoNome, double novaMargem) {
    Produto *prod = buscarProduto(lista, codigo);
    if (prod == NULL) {
        printf("Produto n�o encontrado.\n");
        return;
    }

    if (novoNome != NULL) {
        strcpy(prod->nome, novoNome);
    }

    prod->margemLucro = novaMargem;
    printf("Produto atualizado com sucesso.\n");
}

