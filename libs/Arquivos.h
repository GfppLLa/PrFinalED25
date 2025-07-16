#ifndef ARQUIVOS_H_INCLUDED
#define ARQUIVOS_H_INCLUDED

#include "Estruturas.h"
#include <stdio.h>

Produto *salvarInfoArq(FILE *arquivo, Produto *lista); // Lê produtos do arquivo e insere na lista
void imprimirNoArq(FILE *arquivo, Produto *lista); // Salva a lista de produtos no arquivo
MateriaPrima* salvarMateriasArq(FILE *arquivo, MateriaPrima *raiz); // Lê matérias-primas do arquivo e insere na árvore
void imprimirMateriasArq(FILE *arquivo, MateriaPrima *raiz); // Salva a árvore de matérias-primas no arquivo
void escreverMateriasEmOrdem(FILE *arquivo, MateriaPrima *raiz); // Escreve matérias em ordem no arquivo (in-order)
void carregarMateriasDosProdutos(FILE *arquivo, Produto *listaProdutos); // Associa matérias-primas aos produtos a partir do arquivo
void exportarMateriasDosProdutos(FILE *arquivo, Produto *listaProdutos); // Salva as associações de matérias-primas dos produtos no arquivo
void salvarTodos(Produto* produtos, MateriaPrima* materias); // Salva todos os dados nos arquivos correspondentes

#endif // ARQUIVOS_H_INCLUDED
