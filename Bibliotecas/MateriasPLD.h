#ifndef MATERIASPLD_H_INCLUDED
#define MATERIASPLD_H_INCLUDED
#include "Estruturas.h"

MateriasPLD* criarMateriaNaLista(int codigo, int quantidade);
MateriasPLD* posicaoMateriaPLD(MateriasPLD* lista, int codigo);
MateriasPLD* inserirMateriaOrdenado(MateriasPLD* lista, int codigo, int quantidade);
MateriasPLD* excluirMateriaPLD(MateriasPLD* lista, int codigo);
void imprimirMateriasPLD(MateriasPLD* lista);


#endif // MATERIASPLD_H_INCLUDED
