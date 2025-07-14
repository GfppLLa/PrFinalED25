#include <stdio.h>
#include "lib.h"

void main ()
{
  MatPrima *materiais; // declarar a arvore para matéria prima
  Produto *produto; // declarar a dll para os produtos 
  // inicializar com malloc ou função
  abrirArquivos(&produtos, &materias); // tras os dados dos csv para memoria principal
  int opcao = -1;
  while(opcao != 0)
  {
    limparTela();
    exibirMenu();
    getOpcao(&opcao);
    opcaoHandler(&produtos, &matérias, opcao);
    esperar();
  }

  fecharArquivos();
  fecharArvore();

}
