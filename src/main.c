#include "lib.h"

FILE *fpProdutos = NULL;
FILE *fpMatPrima = NULL;

MatPrima *arvoreMatPrima = NULL;
Produto *listaProdutos = NULL;

void main ()
{
  abrirArquivos(); 
  while(1)
  {
    limparTela();
    exibirMenu();
    int op = getOpcao();
    if(op == 0)
      break;
    opcaoHandler(&produtos, &matérias, op);
    esperar();
  }
  fecharArquivos();
}
