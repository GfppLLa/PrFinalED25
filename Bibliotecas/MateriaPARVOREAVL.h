#ifndef MATERIAPARVOREAVL_H_INCLUDED
#define MATERIAPARVOREAVL_H_INCLUDED
#include "Estruturas.h"


MateriaPrima* buscarMateria(MateriaPrima* raiz, int codigoMateria);
int maiorValor(int a, int b);
int alturaNo(MateriaPrima *no);
int fatorBalanceamento(MateriaPrima *no);

MateriaPrima* criarNo(int codigoMateria, const char* nome, double preco);
MateriaPrima* rotacaoDireita(MateriaPrima *y);
MateriaPrima* rotacaoEsquerda(MateriaPrima *x);
MateriaPrima* inserirMateria(MateriaPrima *raiz, int codigoMateria, const char* nome, double preco);
void imprimirEmOrdem(MateriaPrima *raiz);

#endif // MATERIAPARVOREAVL_H_INCLUDED
