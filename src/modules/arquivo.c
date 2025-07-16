#include "lib.h"

FILE* abrirArquivos()
{
  fpProdutos = fopen("../files/produtos.csv", "a+");
  fpMatPrima = fopen("../files/matPrima.csv", "a+");

  if (!fpProdutos || !fpMatPrima) {
    printf("Erro ao abrir arquivos");
    exit(1);
  }
}

int escreverCSV(FILE *arquivo, const char *texto); // escreve um csv e retorna flag 

void lerCSV(FILE *arquivo); // lê um arq csv e escreve-o em lista ou arvore

int fecharArquivos()
{
  fclose(fpProdutos);
  fclose(fpMatPrima);
}
