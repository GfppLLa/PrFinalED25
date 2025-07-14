#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

typedef struct Arvore{
    int altura;
    int codigoMateria;
    double preco;
    char nome[100];
    struct Arvore *esq;
    struct Arvore *dir;
}MateriaPrima;

typedef struct ListaD{
    int codigoMateria;
    int quantidade;
    struct ListaD *ant;
    struct ListaD *prox;
}MateriasPLD;

typedef struct produto{
    int codigoProduto;
    char nome[100];
    double margemLucro;
    struct produto *ant;
    struct produto *prox;
    MateriasPLD *materiasProd;
}Produto;

#endif // ESTRUTURAS_H_INCLUDED
