#include "lib.h"

FILE *fpProdutos = NULL;
FILE *fpMatPrima = NULL;

MatPrima *arvoreMatPrima = NULL;
Produto *listaProdutos = NULL;

void main ()
{
  abrirArquivos();
  
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
}
