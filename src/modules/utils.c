#include "lib.h"

void menu()
{
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
}

void limparTela()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

int getOpcao()
{
  int op, flag;
  do{
    printf("Digite uma opcao (numero): ");
    flag = scanf("%d", &op);
    while(getchar() != '\n');
  } while(flag != 1)
  return op;
}

void opcaoHandler(int opcao); // recebe opcaoe direciona para as funcionalidades

int gerarCodigo(char *str); // recebe uma string e retorna um codigo/hash

float calcularPrecoVenda(float margemLucro, MatPrima *listaMateriais);

float calcularPrecoCusto(MatPrima* listaMateriais);

int max(int a, int b); // Retorna o maior entre dois inteiros               

void esperar(); // espera um enter para continuar o fluxo do programa
