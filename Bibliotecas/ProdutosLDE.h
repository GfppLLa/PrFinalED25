#ifndef PRODUTOSLDE_H_INCLUDED
#define PRODUTOSLDE_H_INCLUDED
#include "Estruturas.h"

Produto* criarProduto(int codigoProduto, const char* nome, double margemLucro);
Produto* posicaoProduto(Produto* lista, int codigo);
Produto* inserirProdutoOrdenado(Produto* lista, int codigo, const char* nome, double margemLucro);
Produto* excluirProduto(Produto* lista, int codigo);
void imprimirProdutos(Produto* lista);



#endif