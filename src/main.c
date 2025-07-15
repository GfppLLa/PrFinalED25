#include "lib.h"

void main ()
{
  MatPrima *materiais = (MatPrima*)malloc(sizeof(MatPrima));     // declarar a arvore para matéria prima
  Produto  *produtos  = (Produto*)malloc(sizeof(Produto));       // declarar a dll para os produtos 
  
  abrirArquivo(<caminho>, <modo>); // tras os dados dos csv para memoria principal
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
