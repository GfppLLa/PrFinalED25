#ifndef MATERIASPLD_H_INCLUDED
#define MATERIASPLD_H_INCLUDED

#include "Estruturas.h"

MateriasPLD* criarMateriaNaLista(int codigo, int quantidade); // Cria um novo nó de matéria-prima na lista do produto
MateriasPLD* posicaoMateriaPLD(MateriasPLD* lista, int codigo); // Encontra a posição de inserção na lista ordenada
MateriasPLD* inserirMateriaOrdenado(MateriasPLD* lista, int codigo, int quantidade); // Insere matéria-prima ordenadamente na lista
MateriasPLD* excluirMateriaPLD(MateriasPLD* lista, int codigo); // Remove uma matéria-prima da lista de um produto
void alterarQuantidadeMateriaProduto(Produto *lista, int codigoProduto, int codigoMateria, int novaQuantidade); // Altera a quantidade de uma matéria-prima de um produto
void adicionarOuSubstituirMateriaProduto(Produto *lista, int codigoProduto, int codigoMateria, int quantidade); // Adiciona ou substitui matéria-prima em um produto
void removerMateriaDoProduto(Produto *lista, int codigoProduto, int codigoMateria); // Remove matéria-prima de um produto
void imprimirMateriasPLD(MateriasPLD* lista, MateriaPrima *raiz); // Imprime a lista de matérias-primas de um produto

#endif // MATERIASPLD_H_INCLUDED
