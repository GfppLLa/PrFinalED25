#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/Estruturas.h"
#include "../libs/ProdutosLDE.h"
#include "../libs/MateriasPLD.h"
#include "../libs/MateriaPARVOREAVL.h"
#include "../libs/Arquivos.h"

Produto *salvarInfoArq(FILE *arquivo, Produto *lista){

    char bufferLinha[150];
    char *auxString;
    int codigoProd;
    char nomeProd[100];
    double margemProd;

    while(fgets(bufferLinha, sizeof(bufferLinha), arquivo) != NULL){
        auxString = strtok(bufferLinha, "; \n");
        codigoProd = atoi(auxString);

        auxString = strtok(NULL, "; \n");
        strcpy(nomeProd, auxString);

        auxString = strtok(NULL, "; \n");
        margemProd = atof(auxString);

        lista = inserirProdutoOrdenado(lista, codigoProd, nomeProd, margemProd);
    }

    return lista;
}

void imprimirNoArq(FILE *arquivo, Produto *lista){
    Produto *aux = lista;

    fprintf(arquivo, "Codigo;Nome;Margem de Lucro\n");
    while(aux != NULL){
        fprintf(arquivo, "%d;%s;%.2f\n", aux->codigoProduto, aux->nome, aux->margemLucro);
        aux = aux->prox;
    }
}
MateriaPrima* salvarMateriasArq(FILE *arquivo, MateriaPrima *raiz) {
    char bufferLinha[150];
    char *auxString;
    int codigo;
    char nome[100];
    double preco;

    while (fgets(bufferLinha, sizeof(bufferLinha), arquivo) != NULL) {
        auxString = strtok(bufferLinha, "; \n");
        codigo = atoi(auxString);

        auxString = strtok(NULL, "; \n");
        strcpy(nome, auxString);

        auxString = strtok(NULL, "; \n");
        preco = atof(auxString);

        raiz = inserirMateria(raiz, codigo, nome, preco);
    }

    return raiz;
}

void imprimirMateriasArq(FILE *arquivo, MateriaPrima *raiz){
    if (arquivo == NULL || raiz == NULL) {
    return;
    }

    fprintf(arquivo, "Codigo;Nome;Preco\n");
    escreverMateriasEmOrdem(arquivo, raiz);
}

void escreverMateriasEmOrdem(FILE *arquivo, MateriaPrima *raiz){
    if (raiz != NULL) {
        escreverMateriasEmOrdem(arquivo, raiz->esq);
        fprintf(arquivo, "%d;%s;%.2lf\n", raiz->codigoMateria, raiz->nome, raiz->preco);
        escreverMateriasEmOrdem(arquivo, raiz->dir);
    }
}

void carregarMateriasDosProdutos(FILE *arquivo, Produto *listaProdutos) {
    char linha[150];
    char *token;
    int codigoProduto, codigoMateria, quantidade;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        token = strtok(linha, ";,\n");
        codigoProduto = atoi(token);

        token = strtok(NULL, ";,\n");
        codigoMateria = atoi(token);

        token = strtok(NULL, ";,\n");
        quantidade = atoi(token);

        adicionarOuSubstituirMateriaProduto(listaProdutos, codigoProduto, codigoMateria, quantidade);
    }
}

void exportarMateriasDosProdutos(FILE *arquivo, Produto *listaProdutos) {
    if (arquivo == NULL) return;

    fprintf(arquivo, "Codigo_produto;Codigo_materia;Quantidade\n");

    Produto *p = listaProdutos;
    while (p != NULL) {
        MateriasPLD *mat = p->materiasProd;
        while (mat != NULL) {
            fprintf(arquivo, "%d;%d;%d\n", p->codigoProduto, mat->codigoMateria, mat->quantidade);
            mat = mat->prox;
        }
        p = p->prox;
    }
}

void salvarTodos(Produto* produtos, MateriaPrima* materias) {
    FILE *arq;

    arq = fopen("../ARQUIVOS/produtos.csv", "w");
    imprimirNoArq(arq, produtos);
    fclose(arq);

    arq = fopen("../ARQUIVOS/materias_primas.csv", "w");
    imprimirMateriasArq(arq, materias);
    fclose(arq);

    arq = fopen("../ARQUIVOS/materias_produto.csv", "w");
    exportarMateriasDosProdutos(arq, produtos);
    fclose(arq);
}
