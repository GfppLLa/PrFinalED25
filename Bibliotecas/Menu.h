#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Estruturas.h"
#include <stdio.h>

void menu(); // Exibe o menu principal do sistema
void menuProdutos(Produto **produtos, MateriaPrima *materias); // Gerencia produtos (inserir, alterar, excluir, etc.)
void menuMaterias(MateriaPrima **materias); // Gerencia matérias-primas (inserir, alterar, excluir)

#endif
