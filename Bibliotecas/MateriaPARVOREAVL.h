#ifndef MATERIAPARVOREAVL_H_INCLUDED
#define MATERIAPARVOREAVL_H_INCLUDED

#include "Estruturas.h"

int maiorValor(int a, int b); // Retorna o maior entre dois valores
int alturaNo(MateriaPrima *no); // Retorna a altura de um nó na árvore
int fatorBalanceamento(MateriaPrima *no); // Calcula o fator de balanceamento de um nó
MateriaPrima* encontrarMinimo(MateriaPrima* no); // Retorna o nó com menor valor (mais à esquerda)
MateriaPrima* removerNo(MateriaPrima* raiz); // Remove um nó com um ou zero filhos
MateriaPrima* balancearNo(MateriaPrima *no); // Realiza rotações para balancear o nó
MateriaPrima* excluirMateria(MateriaPrima* raiz, int codigo); // Remove uma matéria-prima da árvore
MateriaPrima* criarNo(int codigoMateria, const char* nome, double preco); // Cria um novo nó de matéria-prima
MateriaPrima* rotacaoDireita(MateriaPrima *y); // Realiza rotação à direita
MateriaPrima* rotacaoEsquerda(MateriaPrima *x); // Realiza rotação à esquerda
MateriaPrima* inserirMateria(MateriaPrima *raiz, int codigoMateria, const char* nome, double preco); // Insere uma matéria-prima na árvore AVL
void alterarMateriaPrima(MateriaPrima *raiz, int codigo, const char *novoNome, double novoPreco); // Altera nome ou preço de uma matéria-prima
void imprimirEmOrdem(MateriaPrima *raiz); // Imprime as matérias-primas em ordem crescente de código

#endif // MATERIAPARVOREAVL_H_INCLUDED
